#ifndef _ROS_sengi_ros_Drive_h
#define _ROS_sengi_ros_Drive_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace sengi_ros
{

  class Drive : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      float drivers[2];

    Drive():
      header(),
      drivers()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 2; i++){
      union {
        float real;
        uint32_t base;
      } u_driversi;
      u_driversi.real = this->drivers[i];
      *(outbuffer + offset + 0) = (u_driversi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_driversi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_driversi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_driversi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->drivers[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 2; i++){
      union {
        float real;
        uint32_t base;
      } u_driversi;
      u_driversi.base = 0;
      u_driversi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_driversi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_driversi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_driversi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->drivers[i] = u_driversi.real;
      offset += sizeof(this->drivers[i]);
      }
     return offset;
    }

    const char * getType(){ return "sengi_ros/Drive"; };
    const char * getMD5(){ return "bd2f9d7d37189a26f56c02d747ac1ca3"; };

  };

}
#endif