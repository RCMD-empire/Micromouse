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
    vars.ir_left_filt =  vars.ir_old_left * 0.1 + vars.ir_left_raw * 0.9;
    vars.ir_right_filt =  vars.ir_old_right * 0.1 + vars.ir_right_raw * 0.9;
    vars.ir_frontleft_filt =  vars.ir_old_Frontleft * 0.1 + vars.ir_frontleft_raw * 0.9;
    vars.ir_frontright_filt =  vars.ir_old_Frontright * 0.1 + vars.ir_frontright_raw * 0.9;

    LOG_INFO("left filt: %d\n",vars.ir_left_filt);
    LOG_INFO("right filt: %d\n",vars.ir_right_filt);
    LOG_INFO("FL filt: %d\n",vars.ir_frontleft_filt);
    LOG_INFO("FR filt: %d\n",vars.ir_frontright_filt);

    vars.ir_old_left =  vars.ir_left_filt;
    vars.ir_old_right = vars.ir_right_filt;
    vars.ir_old_Frontleft =  vars.ir_frontleft_filt;
    vars.ir_old_Frontright =  vars.ir_frontright_filt;
}