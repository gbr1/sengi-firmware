#ifndef _ROS_visp_camera_calibration_ImageAndPoints_h
#define _ROS_visp_camera_calibration_ImageAndPoints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/Image.h"
#include "visp_camera_calibration/ImagePoint.h"

namespace visp_camera_calibration
{

  class ImageAndPoints : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef sensor_msgs::Image _image_type;
      _image_type image;
      uint32_t points_length;
      typedef visp_camera_calibration::ImagePoint _points_type;
      _points_type st_points;
      _points_type * points;

    ImageAndPoints():
      header(),
      image(),
      points_length(0), points(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->image.serialize(outbuffer + offset);
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
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->image.deserialize(inbuffer + offset);
      uint32_t points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->points_length);
      if(points_lengthT > points_length)
        this->points = (visp_camera_calibration::ImagePoint*)realloc(this->points, points_lengthT * sizeof(visp_camera_calibration::ImagePoint));
      points_length = points_lengthT;
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(visp_camera_calibration::ImagePoint));
      }
     return offset;
    }

    const char * getType(){ return "visp_camera_calibration/ImageAndPoints"; };
    const char * getMD5(){ return "0fea5fc0844344ec4ec1adadebd18f75"; };

  };

}
#endif