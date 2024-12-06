// Micromouse course - evosoft

#include "utils/logging.h"
#include "variables.h"
#include "components.h"
#include "input_handling.h"

void MM::read_sensors()
{
    /* Write your code here */
    comp.ir_frontleft.read();
    comp.ir_frontright.read();
    comp.ir_left.read();
    comp.ir_right.read();
}

void MM::pre_process()
{
    /* Write your code here */
    
}