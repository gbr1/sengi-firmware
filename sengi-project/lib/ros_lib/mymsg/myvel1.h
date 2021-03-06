#ifndef _ROS_mymsg_myvel1_h
#define _ROS_mymsg_myvel1_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mymsg
{

  class myvel1 : public ros::Msg
  {
    public:
      typedef float _leftwheel_type;
      _leftwheel_type leftwheel;
      typedef float _rightwheel_type;
      _rightwheel_type rightwheel;

    myvel1():
      leftwheel(0),
      rightwheel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_leftwheel;
      u_leftwheel.real = this->leftwheel;
      *(outbuffer + offset + 0) = (u_leftwheel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_leftwheel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_leftwheel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_leftwheel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->leftwheel);
      union {
        float real;
        uint32_t base;
      } u_rightwheel;
      u_rightwheel.real = this->rightwheel;
      *(outbuffer + offset + 0) = (u_rightwheel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rightwheel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rightwheel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rightwheel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rightwheel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_leftwheel;
      u_leftwheel.base = 0;
      u_leftwheel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_leftwheel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_leftwheel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_leftwheel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->leftwheel = u_leftwheel.real;
      offset += sizeof(this->leftwheel);
      union {
        float real;
        uint32_t base;
      } u_rightwheel;
      u_rightwheel.base = 0;
      u_rightwheel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rightwheel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rightwheel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rightwheel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rightwheel = u_rightwheel.real;
      offset += sizeof(this->rightwheel);
     return offset;
    }

    const char * getType(){ return "mymsg/myvel1"; };
    const char * getMD5(){ return "e3b2588f2a6f830b1d697775842e5af3"; };

  };

}
#endif