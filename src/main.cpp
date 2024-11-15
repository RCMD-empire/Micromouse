// Micromouse course - evosoft

#include <Arduino.h>
#include <functional>
#include "utils/logging.h"
#include "utils/task.h"
#include "hal/micromouse.h"
#include "variables.h"
#include "components.h"
#include "control/controller.h"
#include "control/input_handling.h"
#include "control/output_handling.h"

using namespace std::chrono_literals;

void debug();

#ifdef BLE_LOGGING
BleSerial ble;
#endif

MM::Variables vars {};
MM::Components comp {};

MM::Task task_read_sensors   {MM::read_sensors, 1s};
MM::Task task_pre_process    {MM::pre_process, 1s};
MM::Task task_evaluate       {MM::evaluate, 1s};
MM::Task task_post_process   {MM::post_process, 1s};
MM::Task task_update_outputs {MM::update_outputs, 1s};
MM::Task task_debug          {debug, 1s};


void debug() {
  LOG_INFO("\nSensors' raws:\n");
  LOG_INFO("Right: %d\n",vars.ir_right_raw);
  LOG_INFO("FrontRight: %d\n",vars.ir_frontright_raw);
  LOG_INFO("Left: %d\n",vars.ir_left_raw);
  LOG_INFO("FrontLeft: %d\n\n",vars.ir_frontleft_raw);
  String readStr = ble.readString();
  if (readStr = "M1")
  {
    LOG_INFO("Boobies!");
  }
}

void setup() {
  LOGGING_BEGIN();
  pinMode(DEBUG_LED_1, OUTPUT);
  vars.ir_en_frontleft = true;
  comp.ir_frontleft.update_output();
  vars.ir_en_frontright = true;
  comp.ir_frontright.update_output();
  vars.ir_en_left = true;
  comp.ir_left.update_output();
  vars.ir_en_right=true;
  comp.ir_right.update_output();
  LOG_INFO("Setup Done\n");
}

void loop() {
  task_read_sensors();
  task_pre_process();
  task_evaluate();
  task_post_process();
  task_update_outputs();
  task_debug();
}