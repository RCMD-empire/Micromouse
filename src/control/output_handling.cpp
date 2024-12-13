// Micromouse course - evosoft

#include "utils/logging.h"
#include "variables.h"
#include "components.h"
#include "output_handling.h"


void MM::post_process()
{
    /* Write your code here */
}

void MM::update_outputs()
{
    comp.IR_frontleft.read();
    vars.ir_en_frontleft=true;  
    comp.IR_right.read();
    vars.ir_en_right=true;
    comp.IR_frontright.read();
    vars.ir_en_frontright=true;
    comp.IR_left.read();
    vars.ir_en_left=true;
      
       switch (vars.haMerre)
      {
       case FORWARD:
         comp.motor_left.motorGoP(23-vars.Output);
         comp.motor_right.motorGoP(23+vars.Output);
         break;
         case NINLEFT:
         comp.motor_left.motorGoP(18);
         comp.motor_right.motorGoP(5);
         
         break;
         case NINRIGHT:
         comp.motor_left.motorGoP(5);
         comp.motor_right.motorGoP(18);
         break;
         case RIGHT:
         comp.motor_left.motorBrake(10);
         comp.motor_right.motorBrake(10);
         comp.motor_left.motorGo(23 + vars.Output);
         comp.motor_right.motorGo(23 - vars.Output);
         break;
         case LEFT:
         LOG_INFO("RIGHT");
         comp.motor_left.motorBrake(10);
         comp.motor_right.motorBrake(10);
         comp.motor_left.motorGo(23 + vars.Output);
         comp.motor_right.motorGo(23 - vars.Output);
         
         break;
         case STOP:
         comp.motor_left.motorBrake(100);
         comp.motor_right.motorBrake(100);
          default:
         break;
       }
    
    
    
}