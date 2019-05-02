#ifndef _ROS_visp_camera_calibration_CalibPointArray_h
#define _ROS_visp_camera_calibration_CalibPointArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "visp_camera_calibration/CalibPoint.h"

namespace visp_camera_calibration
{

  class CalibPointArray : public ros::Msg
  {
    public:
      uint32_t points_length;
      typedef visp_camera_calibration::CalibPoint _points_type;
      _points_type st_points;
      _points_type * points;

    CalibPointArray():
      points_length(0), points(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->points_length);
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->points_length);
      if(points_lengthT > points_length)
        this->points = (visp_camera_calibration::CalibPoint*)realloc(this->points, points_lengthT * sizeof(visp_camera_calibration::CalibPoint));
      points_length = points_lengthT;
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(visp_camera_calibration::CalibPoint));
      }
     return offset;
    }

    const char * getType(){ return "visp_camera_calibration/CalibPointArray"; };
    const char * getMD5(){ return "46e7b53381d96d2d7cbbb7418f6dd696"; };

  };

}
#endif