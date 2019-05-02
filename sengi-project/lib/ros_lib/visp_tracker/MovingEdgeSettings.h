#ifndef _ROS_visp_tracker_MovingEdgeSettings_h
#define _ROS_visp_tracker_MovingEdgeSettings_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace visp_tracker
{

  class MovingEdgeSettings : public ros::Msg
  {
    public:
      typedef int64_t _mask_size_type;
      _mask_size_type mask_size;
      typedef int64_t _range_type;
      _range_type range;
      typedef float _threshold_type;
      _threshold_type threshold;
      typedef float _mu1_type;
      _mu1_type mu1;
      typedef float _mu2_type;
      _mu2_type mu2;
      typedef int64_t _sample_step_type;
      _sample_step_type sample_step;
      typedef int64_t _strip_type;
      _strip_type strip;
      typedef float _first_threshold_type;
      _first_threshold_type first_threshold;

    MovingEdgeSettings():
      mask_size(0),
      range(0),
      threshold(0),
      mu1(0),
      mu2(0),
      sample_step(0),
      strip(0),
      first_threshold(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_mask_size;
      u_mask_size.real = this->mask_size;
      *(outbuffer + offset + 0) = (u_mask_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mask_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mask_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mask_size.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_mask_size.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_mask_size.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_mask_size.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_mask_size.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->mask_size);
      union {
        int64_t real;
        uint64_t base;
      } u_range;
      u_range.real = this->range;
      *(outbuffer + offset + 0) = (u_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_range.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_range.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_range.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_range.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_range.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->range);
      offset += serializeAvrFloat64(outbuffer + offset, this->threshold);
      offset += serializeAvrFloat64(outbuffer + offset, this->mu1);
      offset += serializeAvrFloat64(outbuffer + offset, this->mu2);
      union {
        int64_t real;
        uint64_t base;
      } u_sample_step;
      u_sample_step.real = this->sample_step;
      *(outbuffer + offset + 0) = (u_sample_step.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sample_step.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sample_step.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sample_step.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_sample_step.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_sample_step.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_sample_step.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_sample_step.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->sample_step);
      union {
        int64_t real;
        uint64_t base;
      } u_strip;
      u_strip.real = this->strip;
      *(outbuffer + offset + 0) = (u_strip.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_strip.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_strip.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_strip.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_strip.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_strip.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_strip.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_strip.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->strip);
      offset += serializeAvrFloat64(outbuffer + offset, this->first_threshold);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_mask_size;
      u_mask_size.base = 0;
      u_mask_size.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mask_size.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mask_size.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mask_size.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_mask_size.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_mask_size.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_mask_size.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_mask_size.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->mask_size = u_mask_size.real;
      offset += sizeof(this->mask_size);
      union {
        int64_t real;
        uint64_t base;
      } u_range;
      u_range.base = 0;
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_range.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->range = u_range.real;
      offset += sizeof(this->range);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->threshold));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->mu1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->mu2));
      union {
        int64_t real;
        uint64_t base;
      } u_sample_step;
      u_sample_step.base = 0;
      u_sample_step.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sample_step.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sample_step.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sample_step.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_sample_step.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_sample_step.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_sample_step.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_sample_step.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->sample_step = u_sample_step.real;
      offset += sizeof(this->sample_step);
      union {
        int64_t real;
        uint64_t base;
      } u_strip;
      u_strip.base = 0;
      u_strip.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_strip.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_strip.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_strip.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_strip.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_strip.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_strip.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_strip.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->strip = u_strip.real;
      offset += sizeof(this->strip);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->first_threshold));
     return offset;
    }

    const char * getType(){ return "visp_tracker/MovingEdgeSettings"; };
    const char * getMD5(){ return "4e8f98b7dec6ffa099529044b3472486"; };

  };

}
#endif