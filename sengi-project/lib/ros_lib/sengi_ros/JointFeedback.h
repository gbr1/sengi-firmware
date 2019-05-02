#ifndef _ROS_sengi_ros_JointFeedback_h
#define _ROS_sengi_ros_JointFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sengi_ros
{

  class JointFeedback : public ros::Msg
  {
    public:
      typedef float _measured_velocity_type;
      _measured_velocity_type measured_velocity;
      typedef float _measured_travel_type;
      _measured_travel_type measured_travel;

    JointFeedback():
      measured_velocity(0),
      measured_travel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_measured_velocity;
      u_measured_velocity.real = this->measured_velocity;
      *(outbuffer + offset + 0) = (u_measured_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_measured_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_measured_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_measured_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->measured_velocity);
      union {
        float real;
        uint32_t base;
      } u_measured_travel;
      u_measured_travel.real = this->measured_travel;
      *(outbuffer + offset + 0) = (u_measured_travel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_measured_travel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_measured_travel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_measured_travel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->measured_travel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_measured_velocity;
      u_measured_velocity.base = 0;
      u_measured_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_measured_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_measured_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_measured_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->measured_velocity = u_measured_velocity.real;
      offset += sizeof(this->measured_velocity);
      union {
        float real;
        uint32_t base;
      } u_measured_travel;
      u_measured_travel.base = 0;
      u_measured_travel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_measured_travel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_measured_travel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_measured_travel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->measured_travel = u_measured_travel.real;
      offset += sizeof(this->measured_travel);
     return offset;
    }

    const char * getType(){ return "sengi_ros/JointFeedback"; };
    const char * getMD5(){ return "6c66d61c0419d0645fff2bdc292447ca"; };

  };

}
#endif