#ifndef _ROS_visp_tracker_MovingEdgeSite_h
#define _ROS_visp_tracker_MovingEdgeSite_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace visp_tracker
{

  class MovingEdgeSite : public ros::Msg
  {
    public:
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef int32_t _suppress_type;
      _suppress_type suppress;

    MovingEdgeSite():
      x(0),
      y(0),
      suppress(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      union {
        int32_t real;
        uint32_t base;
      } u_suppress;
      u_suppress.real = this->suppress;
      *(outbuffer + offset + 0) = (u_suppress.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_suppress.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_suppress.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_suppress.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->suppress);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      union {
        int32_t real;
        uint32_t base;
      } u_suppress;
      u_suppress.base = 0;
      u_suppress.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_suppress.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_suppress.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_suppress.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->suppress = u_suppress.real;
      offset += sizeof(this->suppress);
     return offset;
    }

    const char * getType(){ return "visp_tracker/MovingEdgeSite"; };
    const char * getMD5(){ return "d67448def98304944978d0ca12803af8"; };

  };

}
#endif