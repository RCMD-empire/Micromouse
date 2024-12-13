// Micromouse course - evosoft
#pragma once

#include <cstdint>
    
namespace MM {

    enum hovaMennyek{
        FORWARD,
        LEFT,
        RIGHT,
        NINRIGHT,
        NINLEFT,
        STOP
    };

struct Variables {
// Inputs =================================================
    uint16_t ir_left_raw;
    uint16_t ir_frontleft_raw;
    uint16_t ir_frontright_raw;
    uint16_t ir_right_raw;

    uint16_t ir_left_filt;
    uint16_t ir_frontleft_filt;
    uint16_t ir_frontright_filt;
    uint16_t ir_right_filt;

    uint32_t encoder_left_raw;
    uint32_t encoder_right_raw;

// Internals ==============================================
    /* Write your code here */
    double ir_frontleft_old;
    double ir_frontrigth_old;
    double ir_right_old;
    double ir_left_old;
    double maximum_distance=700;
    double max_distance_stop= 400;

    hovaMennyek haMerre;

    double Setpoint=0;
    double Input=ir_left_filt-ir_right_filt;
    double Output;

//Specify the links and initial tuning parameters
double Kp=0.0005, Ki=0, Kd=0;



// Outputs ================================================
    bool ir_en_left =true;
    bool ir_en_frontleft=true;
    bool ir_en_frontright=true;
    bool ir_en_right=true;

    int16_t motor_left;
    int16_t motor_right;
    bool    motor_brake;
};

} // namespace MM

extern MM::Variables vars;