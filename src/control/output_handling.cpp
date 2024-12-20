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
         comp.motor_left.motorGoP(25-vars.Output);
         comp.motor_right.motorGoP(25+vars.Output);
         break;
         case NINLEFT:
         for (size_t i = 0; i < 2; i++)
         {
          comp.motor_left.motorGoP(19);
          comp.motor_right.motorGoP(3);
          delay(10);
         }
         
         
         break;
         case NINRIGHT:
         for (size_t i = 0; i < 2; i++)
         {
          comp.motor_left.motorGoP(3);
          comp.motor_right.motorGoP(19);
          delay(10);
         }
         
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