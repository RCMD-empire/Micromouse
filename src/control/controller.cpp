// Micromouse course - evosoft

#include "utils/logging.h"
#include "variables.h"
#include "components.h"
#include "controller.h"
#include "PID_v1.h"


// PID constants ==========================================
double Kp = 0.1;  // Proporcionális tag
double Ki = 0.0;  // Integrális tag
double Kd = 0.0; // Differenciális tag

double Setpoint = 0.0;

// Alapjárati sebesség és maximális PWM érték
int16_t baseSpeed = 8; // Alapjárati sebesség (%)
int16_t maxPWM = 20;   // Maximális PWM érték (%)


PID myPID(&vars.inputPID, &vars.OutputPID, &Setpoint, Kp, Ki, Kd, DIRECT);

// === PID kimenet PWM-re skálázása ===
int16_t scaleToPWM(int16_t pidOutput, int16_t maxPWM) {
    if (pidOutput > maxPWM) return maxPWM;
    if (pidOutput < -maxPWM) return -maxPWM;
    return pidOutput;
}

void controlMotorsWithPWM() {
   
    vars.inputPID = vars.ir_left_filt - vars.ir_right_filt;
    myPID.Compute();
    LOG_INFO("PID: %d, left: %d,right: %d \n", vars.OutputPID, vars.ir_left_filt ,vars.ir_right_filt);
    LOG_INFO("input: %d, \n", vars.inputPID);
    

    if (vars.ir_frontleft_filt > 2000.0 || vars.ir_frontright_filt > 2000.0) {
        comp.motor_left.motorStop();  
        comp.motor_right.motorStop();   
    }
    else {
        comp.motor_left.motorGoP(15 - vars.OutputPID);
        comp.motor_right.motorGoP(15 + vars.OutputPID);
    }


    /*if (left_distance < target_distance) {
        // Bal oldali távolság kisebb, mint a cél, lassítjuk a bal motort
        
        //double motor_left = scaleToPWM(baseSpeed - correction_left, maxPWM);
        
        //comp.motor_left.motorGoP(motor_left);   // Bal motor sebessége
    } else {
        //comp.motor_left.motorGoP(baseSpeed);   // Bal motor alap sebesség
    }

    if (right_distance < target_distance) {
        // Jobb oldali távolság kisebb, mint a cél, lassítjuk a jobb motort
       
       //double motor_right = scaleToPWM(baseSpeed - correction_right, maxPWM);
        //comp.motor_right.motorGoP(motor_right); // Jobb motor sebessége
    } else {
        //comp.motor_right.motorGoP(baseSpeed); // Jobb motor alap sebesség
    }*/
}



void MM::evaluate()
{
    if(vars.frist){
       
        myPID.SetSampleTime(1000);
        myPID.SetOutputLimits(50,-50);
        myPID.SetMode(AUTOMATIC);
        vars.frist = false;
    }
    controlMotorsWithPWM();


    delay(10);   
    
}