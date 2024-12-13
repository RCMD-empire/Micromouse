// Micromouse course - evosoft

#include "utils/logging.h"
#include "variables.h"
#include "components.h"
#include "input_handling.h"
#include <filters.h>
#include <filters/IIRFilter.hpp>

void MM::read_sensors()
{
    comp.IR_frontleft.read();
    comp.IR_right.read();
    comp.IR_frontright.read();
    comp.IR_left.read();
}
double MM::Filter(double ir_old_filt, double ir_raw){
    double filtered_value;
    filtered_value=(ir_old_filt*0.10)+(ir_raw*0.90);
    return filtered_value;
}

        


void MM::pre_process()
{
    
    
        
    /*
     vars.ir_frontleft_filt=(vars.ir_frontleft_raw*0.9)+(vars.ir_frontleft_old*0.1);
     vars.ir_frontright_filt=(vars.ir_frontright_raw*0.9)+(vars.ir_frontrigth_old*0.1);
     vars.ir_left_filt=(vars.ir_left_raw*0.9)+(vars.ir_left_old*0.1);
     vars.ir_right_filt=(vars.ir_right_raw*0.9)+(vars.ir_right_old*0.1);
    */


    //a régi változókba betölteni a legfrissebbeket
    
    vars.ir_frontleft_old=vars.ir_frontleft_filt;
    vars.ir_frontrigth_old=vars.ir_frontright_filt;
    vars.ir_right_old=vars.ir_right_filt;
    vars.ir_left_old=vars.ir_left_filt;
    
    //meghívni a függvényt ami szűri az ir értékeket (külön mind a 4et)
    
    vars.ir_frontleft_filt=Filter(vars.ir_frontleft_old,vars.ir_frontleft_raw);
    vars.ir_frontright_filt=Filter(vars.ir_frontrigth_old,vars.ir_frontright_raw);
    vars.ir_left_filt=Filter(vars.ir_left_old,vars.ir_left_raw);
    vars.ir_right_filt=Filter(vars.ir_right_old,vars.ir_right_raw);
    

}
