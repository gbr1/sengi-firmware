#ifndef _ROS_orbus_interface_ControlStatus_h
#define _ROS_orbus_interface_ControlStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace orbus_interface
{

  class ControlStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _pwm_type;
      _pwm_type pwm;
      typedef float _position_type;
      _position_type position;
      typedef float _velocity_type;
      _velocity_type velocity;
      typedef float _current_type;
      _current_type current;
      typedef float _effort_type;
      _effort_type effort;

    ControlStatus():
      header(),
      pwm(0),
      position(0),
      velocity(0),
      current(0),
      effort(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->pwm);
      offset += serializeAvrFloat64(outbuffer + offset, this->position);
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity);
      offset += serializeAvrFloat64(outbuffer + offset, this->current);
      offset += serializeAvrFloat64(outbuffer + offset, this->effort);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->pwm));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->position));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocity));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->current));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->effort));
     return offset;
    }

    const char * getType(){ return "orbus_interface/ControlStatus"; };
    const char * getMD5(){ return "ed0271b2d851fc154e536f6c8b1a71af"; };

  };

}
#endif