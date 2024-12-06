// Micromouse course - evosoft

#include "utils/logging.h"
#include "variables.h"
#include "components.h"
#include "controller.h"

// PID constants ==========================================
double Kp = 1.0;  // Proporcionális tag
double Ki = 0.1;  // Integrális tag
double Kd = 0.05; // Differenciális tag

// Alapjárati sebesség és maximális PWM érték
int16_t baseSpeed = 8; // Alapjárati sebesség (%)
int16_t maxPWM = 20;   // Maximális PWM érték (%)


int16_t calculatePID(double target, double current, double* error_old, double* integral) {
    double error = target - current;
    *integral += error;
    double derivative = error - *error_old;

    double output = Kp * error + Ki * *integral + Kd * derivative;

    *error_old = error;
    return (int16_t)output;
}

// === PID kimenet PWM-re skálázása ===
int16_t scaleToPWM(int16_t pidOutput, int16_t maxPWM) {
    if (pidOutput > maxPWM) return maxPWM;
    if (pidOutput < -maxPWM) return -maxPWM;
    return pidOutput;
}

void controlMotorsWithPWM() {
    double target_distance = 1800.0;  // Maximális cél távolság

    double left_distance = vars.ir_left_filt;
    double right_distance = vars.ir_right_filt;
    double front_left_distance = vars.ir_frontleft_filt;
    double front_right_distance = vars.ir_frontright_filt;

    /*if (front_left_distance > 2000.0 || front_right_distance > 2000.0) {
        comp.motor_left.motorStop();  
        comp.motor_right.motorStop();   
    }*/


    if (left_distance < target_distance) {
        // Bal oldali távolság kisebb, mint a cél, lassítjuk a bal motort
        int16_t correction_left = calculatePID(target_distance, left_distance, &vars.error_left_old, &vars.integral_left);
        double motor_left = scaleToPWM(baseSpeed - correction_left, maxPWM);
        LOG_INFO("PID: %d, sclaleToPWM: %d\n", correction_left, motor_left);
        //comp.motor_left.motorGoP(motor_left);   // Bal motor sebessége
    } else {
        //comp.motor_left.motorGoP(baseSpeed);   // Bal motor alap sebesség
    }

    if (right_distance < target_distance) {
        // Jobb oldali távolság kisebb, mint a cél, lassítjuk a jobb motort
        int16_t correction_right = calculatePID(target_distance, right_distance, &vars.error_right_old, &vars.integral_right);
        double motor_right = scaleToPWM(baseSpeed - correction_right, maxPWM);
        //comp.motor_right.motorGoP(motor_right); // Jobb motor sebessége
    } else {
        //comp.motor_right.motorGoP(baseSpeed); // Jobb motor alap sebesség
    }
}



void MM::evaluate()
{
    controlMotorsWithPWM();

    delay(10);   
    
}