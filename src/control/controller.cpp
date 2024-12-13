// Micromouse course - evosoft

#include "utils/logging.h"
#include "variables.h"
#include "components.h"
#include "controller.h"
#include"PID_v1.h"
PID myPID(&vars.Input,&vars.Output,&vars.Setpoint,vars.Kp,vars.Ki, vars.Kd,DIRECT);
bool jo =true;
 void MM::evaluate()
{
    LOG_INFO("FL: %d, L: %d, FR: %d, R: %d\n",vars.ir_frontleft_filt,vars.ir_left_filt, vars.ir_frontright_filt, vars.ir_right_filt);
    vars.Input=vars.ir_left_filt-vars.ir_right_filt;
        if (jo)
    {
         myPID.SetMode(AUTOMATIC);
         myPID.SetSampleTime(10); 
         myPID.SetOutputLimits(-50,50);
         vars.Setpoint=vars.Input;
         jo = false;
    }
    
    

 
if (vars.ir_frontleft_filt>vars.max_distance_stop&&
vars.ir_frontright_filt>vars.max_distance_stop&&
vars.ir_left_filt>300&&
vars.ir_right_filt>300)
{
   
   if(vars.ir_left_filt<vars.max_distance_stop){
        myPID.SetTunings(0.01,0,0);
        vars.haMerre = NINLEFT;
   }
    else if(vars.ir_right_filt<vars.max_distance_stop){
        myPID.SetTunings(0.01,0,0);
        vars.haMerre = NINRIGHT;
    }
    else{
        vars.haMerre= STOP;
    }

}
else 
  {
    if(vars.ir_left_filt<vars.maximum_distance&&vars.ir_right_filt>vars.maximum_distance){
        myPID.SetTunings(0.007,0,0);
        
        vars.haMerre=RIGHT;//balra
    }
    else if(vars.ir_left_filt>vars.maximum_distance&&vars.ir_right_filt<vars.maximum_distance){
        myPID.SetTunings(0.007,0,0);
       

        vars.haMerre=LEFT;//jobbra
    }
    else{
        myPID.SetTunings(0.007,0,0);
        
     
        vars.haMerre=FORWARD;

    }
     myPID.Compute();

}   

    



}

