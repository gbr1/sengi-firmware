#ifndef _ROS_orbus_interface_MotorStatus_h
#define _ROS_orbus_interface_MotorStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace orbus_interface
{

  class MotorStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _state_type;
      _state_type state;
      typedef float _voltage_type;
      _voltage_type voltage;
      typedef float _watt_type;
      _watt_type watt;
      typedef uint64_t _time_execution_type;
      _time_execution_type time_execution;
      typedef float _temperature_type;
      _temperature_type temperature;

    MotorStatus():
      header(),
      state(""),
      voltage(0),
      watt(0),
      time_execution(0),
      temperature(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_state = strlen(this->state);
      varToArr(outbuffer + offset, length_state);
      offset += 4;
      memcpy(outbuffer + offset, this->state, length_state);
      offset += length_state;
      offset += serializeAvrFloat64(outbuffer + offset, this->voltage);
      offset += serializeAvrFloat64(outbuffer + offset, this->watt);
      union {
        uint64_t real;
        uint32_t base;
      } u_time_execution;
      u_time_execution.real = this->time_execution;
      *(outbuffer + offset + 0) = (u_time_execution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time_execution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time_execution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time_execution.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_execution);
      offset += serializeAvrFloat64(outbuffer + offset, this->temperature);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_state;
      arrToVar(length_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_state-1]=0;
      this->state = (char *)(inbuffer + offset-1);
      offset += length_state;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->voltage));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->watt));
      union {
        uint64_t real;
        uint32_t base;
      } u_time_execution;
      u_time_execution.base = 0;
      u_time_execution.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time_execution.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time_execution.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time_execution.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->time_execution = u_time_execution.real;
      offset += sizeof(this->time_execution);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->temperature));
     return offset;
    }

    const char * getType(){ return "orbus_interface/MotorStatus"; };
    const char * getMD5(){ return "805de2c25f938a75e82054190dd60d91"; };

  };

}
#endif