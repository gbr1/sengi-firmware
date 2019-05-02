#ifndef _ROS_SERVICE_calibrate_h
#define _ROS_SERVICE_calibrate_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace visp_camera_calibration
{

static const char CALIBRATE[] = "visp_camera_calibration/calibrate";

  class calibrateRequest : public ros::Msg
  {
    public:
      typedef int32_t _method_type;
      _method_type method;
      typedef int32_t _sample_width_type;
      _sample_width_type sample_width;
      typedef int32_t _sample_height_type;
      _sample_height_type sample_height;

    calibrateRequest():
      method(0),
      sample_width(0),
      sample_height(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_method;
      u_method.real = this->method;
      *(outbuffer + offset + 0) = (u_method.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_method.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_method.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_method.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->method);
      union {
        int32_t real;
        uint32_t base;
      } u_sample_width;
      u_sample_width.real = this->sample_width;
      *(outbuffer + offset + 0) = (u_sample_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sample_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sample_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sample_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sample_width);
      union {
        int32_t real;
        uint32_t base;
      } u_sample_height;
      u_sample_height.real = this->sample_height;
      *(outbuffer + offset + 0) = (u_sample_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sample_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sample_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sample_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sample_height);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_method;
      u_method.base = 0;
      u_method.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_method.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_method.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_method.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->method = u_method.real;
      offset += sizeof(this->method);
      union {
        int32_t real;
        uint32_t base;
      } u_sample_width;
      u_sample_width.base = 0;
      u_sample_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sample_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sample_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sample_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sample_width = u_sample_width.real;
      offset += sizeof(this->sample_width);
      union {
        int32_t real;
        uint32_t base;
      } u_sample_height;
      u_sample_height.base = 0;
      u_sample_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sample_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sample_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sample_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sample_height = u_sample_height.real;
      offset += sizeof(this->sample_height);
     return offset;
    }

    const char * getType(){ return CALIBRATE; };
    const char * getMD5(){ return "7b57c459896a8f1f8df45a385acfc123"; };

  };

  class calibrateResponse : public ros::Msg
  {
    public:
      uint32_t stdDevErrs_length;
      typedef float _stdDevErrs_type;
      _stdDevErrs_type st_stdDevErrs;
      _stdDevErrs_type * stdDevErrs;

    calibrateResponse():
      stdDevErrs_length(0), stdDevErrs(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stdDevErrs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stdDevErrs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stdDevErrs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stdDevErrs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stdDevErrs_length);
      for( uint32_t i = 0; i < stdDevErrs_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->stdDevErrs[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t stdDevErrs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stdDevErrs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stdDevErrs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stdDevErrs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->stdDevErrs_length);
      if(stdDevErrs_lengthT > stdDevErrs_length)
        this->stdDevErrs = (float*)realloc(this->stdDevErrs, stdDevErrs_lengthT * sizeof(float));
      stdDevErrs_length = stdDevErrs_lengthT;
      for( uint32_t i = 0; i < stdDevErrs_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_stdDevErrs));
        memcpy( &(this->stdDevErrs[i]), &(this->st_stdDevErrs), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return CALIBRATE; };
    const char * getMD5(){ return "cd6d27af348dbd9b7530b010497f18b0"; };

  };

  class calibrate {
    public:
    typedef calibrateRequest Request;
    typedef calibrateResponse Response;
  };

}
#endif
