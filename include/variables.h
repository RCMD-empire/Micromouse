// Micromouse course - evosoft
#pragma once

#include <cstdint>

namespace MM {

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
    double error_left_old;   // Bal motor előző hiba
    double error_right_old;  // Jobb motor előző hiba
    double integral_left;    // Bal motor integrált hiba
    double integral_right;   // Jobb motor integrált hiba

// Outputs ================================================
    bool ir_en_left;
    bool ir_en_frontleft;
    bool ir_en_frontright;
    bool ir_en_right;

    int16_t motor_left;
    int16_t motor_right;
    bool    motor_brake;

    bool blinker;
};

} // namespace MM

extern MM::Variables vars;