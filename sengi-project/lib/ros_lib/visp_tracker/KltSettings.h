#ifndef _ROS_visp_tracker_KltSettings_h
#define _ROS_visp_tracker_KltSettings_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace visp_tracker
{

  class KltSettings : public ros::Msg
  {
    public:
      typedef int64_t _max_features_type;
      _max_features_type max_features;
      typedef int64_t _window_size_type;
      _window_size_type window_size;
      typedef float _quality_type;
      _quality_type quality;
      typedef float _min_distance_type;
      _min_distance_type min_distance;
      typedef float _harris_type;
      _harris_type harris;
      typedef int64_t _size_block_type;
      _size_block_type size_block;
      typedef int64_t _pyramid_lvl_type;
      _pyramid_lvl_type pyramid_lvl;
      typedef int64_t _mask_border_type;
      _mask_border_type mask_border;

    KltSettings():
      max_features(0),
      window_size(0),
      quality(0),
      min_distance(0),
      harris(0),
      size_block(0),
      pyramid_lvl(0),
      mask_border(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_max_features;
      u_max_features.real = this->max_features;
      *(outbuffer + offset + 0) = (u_max_features.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_features.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_features.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_features.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_features.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_features.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_features.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_features.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_features);
      union {
        int64_t real;
        uint64_t base;
      } u_window_size;
      u_window_size.real = this->window_size;
      *(outbuffer + offset + 0) = (u_window_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_window_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_window_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_window_size.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_window_size.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_window_size.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_window_size.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_window_size.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->window_size);
      offset += serializeAvrFloat64(outbuffer + offset, this->quality);
      offset += serializeAvrFloat64(outbuffer + offset, this->min_distance);
      offset += serializeAvrFloat64(outbuffer + offset, this->harris);
      union {
        int64_t real;
        uint64_t base;
      } u_size_block;
      u_size_block.real = this->size_block;
      *(outbuffer + offset + 0) = (u_size_block.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_size_block.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_size_block.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_size_block.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_size_block.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_size_block.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_size_block.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_size_block.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->size_block);
      union {
        int64_t real;
        uint64_t base;
      } u_pyramid_lvl;
      u_pyramid_lvl.real = this->pyramid_lvl;
      *(outbuffer + offset + 0) = (u_pyramid_lvl.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pyramid_lvl.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pyramid_lvl.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pyramid_lvl.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pyramid_lvl.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pyramid_lvl.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pyramid_lvl.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pyramid_lvl.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pyramid_lvl);
      union {
        int64_t real;
        uint64_t base;
      } u_mask_border;
      u_mask_border.real = this->mask_border;
      *(outbuffer + offset + 0) = (u_mask_border.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mask_border.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mask_border.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mask_border.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_mask_border.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_mask_border.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_mask_border.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_mask_border.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->mask_border);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_max_features;
      u_max_features.base = 0;
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_features.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_features = u_max_features.real;
      offset += sizeof(this->max_features);
      union {
        int64_t real;
        uint64_t base;
      } u_window_size;
      u_window_size.base = 0;
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_window_size.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->window_size = u_window_size.real;
      offset += sizeof(this->window_size);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->quality));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_distance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->harris));
      union {
        int64_t real;
        uint64_t base;
      } u_size_block;
      u_size_block.base = 0;
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_size_block.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->size_block = u_size_block.real;
      offset += sizeof(this->size_block);
      union {
        int64_t real;
        uint64_t base;
      } u_pyramid_lvl;
      u_pyramid_lvl.base = 0;
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pyramid_lvl.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pyramid_lvl = u_pyramid_lvl.real;
      offset += sizeof(this->pyramid_lvl);
      union {
        int64_t real;
        uint64_t base;
      } u_mask_border;
      u_mask_border.base = 0;
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_mask_border.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->mask_border = u_mask_border.real;
      offset += sizeof(this->mask_border);
     return offset;
    }

    const char * getType(){ return "visp_tracker/KltSettings"; };
    const char * getMD5(){ return "7cd8ae2f3a31d26015e8c80e88eb027a"; };

  };

}
#endif