// Micromouse course - evosoft

#include "utils/logging.h"
#include "variables.h"
#include "components.h"
#include "controller.h"
#include "PID_v1.h"


// PID constants ==========================================
double Kp = 2;  // Proporcionális tag
double Ki = 5;  // Integrális tag
double Kd = 1; // Differenciális tag

double Setpoint = 2000;

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
   
    double left_distance = vars.ir_left_filt;
    double right_distance = vars.ir_right_filt;
    double front_left_distance = vars.ir_frontleft_filt;
    double front_right_distance = vars.ir_frontright_filt;

    LOG_INFO("PID: %d, \n", vars.OutputPID);

    /*if (front_left_distance > 2000.0 || front_right_distance > 2000.0) {
        comp.motor_left.motorStop();  
        comp.motor_right.motorStop();   
    }*/


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
        myPID.SetMode(AUTOMATIC);
        vars.frist = false;
    }
    controlMotorsWithPWM();


    delay(10);   
    
}