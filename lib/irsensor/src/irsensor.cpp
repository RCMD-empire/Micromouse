// Micromouse course - evosoft

#include <Arduino.h>
#include "irsensor.h"

namespace MM {

    IRSensor::IRSensor(uint8_t sensor_pin, uint8_t en_pin, uint16_t& value, bool& en)
        : m_sensor_pin(sensor_pin), m_en_pin(en_pin), m_value(value), m_en(en)
    {
        pinMode(en_pin, OUTPUT);
        update_output();
    }

    void IRSensor::update_output()
    {
        digitalWrite(m_en_pin, m_en);
    }

    void IRSensor::read()
    {
        m_value = analogRead(m_sensor_pin);
    }

} //namespace MM