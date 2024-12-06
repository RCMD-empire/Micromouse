
// Micromouse course - evosoft
#pragma once

#include <irsensor.h>
#include "hal/micromouse.h"
#include "variables.h"
#include <FS_MX1508.h>

namespace MM {

struct Components {
IRSensor ir_left {IR_2, IR_EN_2, vars.ir_left_raw, vars.ir_en_left};
IRSensor ir_frontleft {IR_1, IR_EN_1, vars.ir_frontleft_raw, vars.ir_en_frontleft};
IRSensor ir_right {IR_3, IR_EN_3, vars.ir_right_raw, vars.ir_en_right};
IRSensor ir_frontright {IR_4, IR_EN_4, vars.ir_frontright_raw, vars.ir_en_frontright};

MX1508 motor_left {MOTOR_1_A, MOTOR_1_B, SLOW_DECAY};
MX1508 motor_right {MOTOR_2_B, MOTOR_2_A, SLOW_DECAY};

};

} // namespace MM

extern MM::Components comp;