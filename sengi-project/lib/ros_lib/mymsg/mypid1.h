#ifndef _ROS_mymsg_mypid1_h
#define _ROS_mymsg_mypid1_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace mymsg
{

  class mypid1 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _channel_type;
      _channel_type channel;
      typedef float _kp_type;
      _kp_type kp;
      typedef float _ki_type;
      _ki_type ki;
      typedef float _kd_type;
      _kd_type kd;
      typedef float _ka_type;
      _ka_type ka;

    mypid1():
      header(),
      channel(0),
      kp(0),
      ki(0),
      kd(0),
      ka(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->channel >> (8 * 0)) & 0xFF;
      offset += sizeof(this->channel);
      union {
        float real;
        uint32_t base;
      } u_kp;
      u_kp.real = this->kp;
      *(outbuffer + offset + 0) = (u_kp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_kp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_kp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_kp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->kp);
      union {
        float real;
        uint32_t base;
      } u_ki;
      u_ki.real = this->ki;
      *(outbuffer + offset + 0) = (u_ki.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ki.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ki.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ki.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ki);
      union {
        float real;
        uint32_t base;
      } u_kd;
      u_kd.real = this->kd;
      *(outbuffer + offset + 0) = (u_kd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_kd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_kd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_kd.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->kd);
      union {
        float real;
        uint32_t base;
      } u_ka;
      u_ka.real = this->ka;
      *(outbuffer + offset + 0) = (u_ka.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ka.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ka.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ka.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ka);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->channel =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->channel);
      union {
        float real;
        uint32_t base;
      } u_kp;
      u_kp.base = 0;
      u_kp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_kp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_kp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_kp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->kp = u_kp.real;
      offset += sizeof(this->kp);
      union {
        float real;
        uint32_t base;
      } u_ki;
      u_ki.base = 0;
      u_ki.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ki.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ki.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ki.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ki = u_ki.real;
      offset += sizeof(this->ki);
      union {
        float real;
        uint32_t base;
      } u_kd;
      u_kd.base = 0;
      u_kd.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_kd.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_kd.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_kd.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->kd = u_kd.real;
      offset += sizeof(this->kd);
      union {
        float real;
        uint32_t base;
      } u_ka;
      u_ka.base = 0;
      u_ka.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ka.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ka.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ka.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ka = u_ka.real;
      offset += sizeof(this->ka);
     return offset;
    }

    const char * getType(){ return "mymsg/mypid1"; };
    const char * getMD5(){ return "f27ef164f7c581cb3956ca8b34d3f0d1"; };

  };

}
#endif