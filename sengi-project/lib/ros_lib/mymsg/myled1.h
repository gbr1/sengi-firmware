#ifndef _ROS_mymsg_myled1_h
#define _ROS_mymsg_myled1_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace mymsg
{

  class myled1 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int8_t _id_type;
      _id_type id;
      typedef uint8_t _red_type;
      _red_type red;
      typedef uint8_t _green_type;
      _green_type green;
      typedef uint8_t _blue_type;
      _blue_type blue;

    myled1():
      header(),
      id(0),
      red(0),
      green(0),
      blue(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->red >> (8 * 0)) & 0xFF;
      offset += sizeof(this->red);
      *(outbuffer + offset + 0) = (this->green >> (8 * 0)) & 0xFF;
      offset += sizeof(this->green);
      *(outbuffer + offset + 0) = (this->blue >> (8 * 0)) & 0xFF;
      offset += sizeof(this->blue);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->id = u_id.real;
      offset += sizeof(this->id);
      this->red =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->red);
      this->green =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->green);
      this->blue =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->blue);
     return offset;
    }

    const char * getType(){ return "mymsg/myled1"; };
    const char * getMD5(){ return "050ab24a1297872fbbf20b711f5dc010"; };

  };

}
#endif