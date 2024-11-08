// Micromouse course - evosoft

#include "utils/logging.h"
#include "variables.h"
#include "components.h"
#include "output_handling.h"
#include "Arduino.h"


void MM::post_process()
{
    /* Write your code here */
}

void MM::update_outputs()
{
    /* Write your code here */
    vars.blinker = !vars.blinker;
    digitalWrite(DEBUG_LED_1, vars.blinker);
}