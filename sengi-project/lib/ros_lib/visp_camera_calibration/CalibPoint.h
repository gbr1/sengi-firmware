#ifndef _ROS_visp_camera_calibration_CalibPoint_h
#define _ROS_visp_camera_calibration_CalibPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace visp_camera_calibration
{

  class CalibPoint : public ros::Msg
  {
    public:
      typedef int32_t _i_type;
      _i_type i;
      typedef int32_t _j_type;
      _j_type j;
      typedef float _X_type;
      _X_type X;
      typedef float _Y_type;
      _Y_type Y;
      typedef float _Z_type;
      _Z_type Z;

    CalibPoint():
      i(0),
      j(0),
      X(0),
      Y(0),
      Z(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_i;
      u_i.real = this->i;
      *(outbuffer + offset + 0) = (u_i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_i.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->i);
      union {
        int32_t real;
        uint32_t base;
      } u_j;
      u_j.real = this->j;
      *(outbuffer + offset + 0) = (u_j.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_j.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_j.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_j.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->j);
      offset += serializeAvrFloat64(outbuffer + offset, this->X);
      offset += serializeAvrFloat64(outbuffer + offset, this->Y);
      offset += serializeAvrFloat64(outbuffer + offset, this->Z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_i;
      u_i.base = 0;
      u_i.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_i.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_i.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_i.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->i = u_i.real;
      offset += sizeof(this->i);
      union {
        int32_t real;
        uint32_t base;
      } u_j;
      u_j.base = 0;
      u_j.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_j.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_j.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_j.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->j = u_j.real;
      offset += sizeof(this->j);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->X));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Z));
     return offset;
    }

    const char * getType(){ return "visp_camera_calibration/CalibPoint"; };
    const char * getMD5(){ return "9b9d41ff2127a593c07cec2a11858ac5"; };

  };

}
#endif