// Micromouse course - evosoft
#pragma once

#include <cstdint>

namespace MM {

class IRSensor {
public:
  IRSensor(uint8_t sensor_pin, uint8_t en_pin, uint16_t& value, bool& en);

  void update_output();
  void read();

private:
  const uint8_t m_sensor_pin;
  const uint8_t m_en_pin;
  uint16_t& m_value;
  bool& m_en;
};

} // namespace MM

