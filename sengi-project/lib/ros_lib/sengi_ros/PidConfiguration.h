#ifndef _ROS_sengi_ros_PidConfiguration_h
#define _ROS_sengi_ros_PidConfiguration_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sengi_ros/Pid.h"

namespace sengi_ros
{

  class PidConfiguration : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      sengi_ros::Pid pid[2];
      typedef int8_t _mode_type;
      _mode_type mode;

    PidConfiguration():
      header(),
      pid(),
      mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 2; i++){
      offset += this->pid[i].serialize(outbuffer + offset);
      }
      union {
        int8_t real;
        uint8_t base;
      } u_mode;
      u_mode.real = this->mode;
      *(outbuffer + offset + 0) = (u_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 2; i++){
      offset += this->pid[i].deserialize(inbuffer + offset);
      }
      union {
        int8_t real;
        uint8_t base;
      } u_mode;
      u_mode.base = 0;
      u_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mode = u_mode.real;
      offset += sizeof(this->mode);
     return offset;
    }

    const char * getType(){ return "sengi_ros/PidConfiguration"; };
    const char * getMD5(){ return "c2cc028fe69c75c511f1eccf2a00ac6a"; };

  };

}
#endif