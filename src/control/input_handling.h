// Micromouse course - evosoft
#pragma once

namespace MM {

class Variables;

void read_sensors();
void pre_process();
double Filter(double ir_old_filt, double ir_raw);
double Calibrate(double ir_value);
} // namespace MM