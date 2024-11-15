// Micromouse course - evosoft

#include "utils/logging.h"
#include "variables.h"
#include "components.h"
#include "controller.h"


void MM::evaluate()
{
    /* Write your code here */
    comp.motor_left.motorGoP(50);
    comp.motor_right.motorGoP(50);

}