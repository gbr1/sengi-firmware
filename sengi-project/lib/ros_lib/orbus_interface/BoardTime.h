#ifndef _ROS_orbus_interface_BoardTime_h
#define _ROS_orbus_interface_BoardTime_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace orbus_interface
{

  class BoardTime : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint64_t _idle_type;
      _idle_type idle;
      typedef uint64_t _ADC_type;
      _ADC_type ADC;
      typedef uint64_t _led_type;
      _led_type led;
      typedef uint64_t _serial_parser_type;
      _serial_parser_type serial_parser;
      typedef uint64_t _I2C_type;
      _I2C_type I2C;

    BoardTime():
      header(),
      idle(0),
      ADC(0),
      led(0),
      serial_parser(0),
      I2C(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_idle;
      u_idle.real = this->idle;
      *(outbuffer + offset + 0) = (u_idle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_idle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_idle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_idle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->idle);
      union {
        uint64_t real;
        uint32_t base;
      } u_ADC;
      u_ADC.real = this->ADC;
      *(outbuffer + offset + 0) = (u_ADC.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ADC.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ADC.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ADC.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ADC);
      union {
        uint64_t real;
        uint32_t base;
      } u_led;
      u_led.real = this->led;
      *(outbuffer + offset + 0) = (u_led.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_led.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_led.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_led.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->led);
      union {
        uint64_t real;
        uint32_t base;
      } u_serial_parser;
      u_serial_parser.real = this->serial_parser;
      *(outbuffer + offset + 0) = (u_serial_parser.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_serial_parser.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_serial_parser.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_serial_parser.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->serial_parser);
      union {
        uint64_t real;
        uint32_t base;
      } u_I2C;
      u_I2C.real = this->I2C;
      *(outbuffer + offset + 0) = (u_I2C.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_I2C.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_I2C.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_I2C.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->I2C);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_idle;
      u_idle.base = 0;
      u_idle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_idle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_idle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_idle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->idle = u_idle.real;
      offset += sizeof(this->idle);
      union {
        uint64_t real;
        uint32_t base;
      } u_ADC;
      u_ADC.base = 0;
      u_ADC.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ADC.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ADC.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ADC.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ADC = u_ADC.real;
      offset += sizeof(this->ADC);
      union {
        uint64_t real;
        uint32_t base;
      } u_led;
      u_led.base = 0;
      u_led.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_led.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_led.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_led.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->led = u_led.real;
      offset += sizeof(this->led);
      union {
        uint64_t real;
        uint32_t base;
      } u_serial_parser;
      u_serial_parser.base = 0;
      u_serial_parser.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_serial_parser.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_serial_parser.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_serial_parser.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->serial_parser = u_serial_parser.real;
      offset += sizeof(this->serial_parser);
      union {
        uint64_t real;
        uint32_t base;
      } u_I2C;
      u_I2C.base = 0;
      u_I2C.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_I2C.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_I2C.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_I2C.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->I2C = u_I2C.real;
      offset += sizeof(this->I2C);
     return offset;
    }

    const char * getType(){ return "orbus_interface/BoardTime"; };
    const char * getMD5(){ return "81dcd23ed2c44b2289f755758888101b"; };

  };

}
#endif