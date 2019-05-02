#ifndef _ROS_visp_tracker_KltPoints_h
#define _ROS_visp_tracker_KltPoints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "visp_tracker/KltPoint.h"

namespace visp_tracker
{

  class KltPoints : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t klt_points_positions_length;
      typedef visp_tracker::KltPoint _klt_points_positions_type;
      _klt_points_positions_type st_klt_points_positions;
      _klt_points_positions_type * klt_points_positions;

    KltPoints():
      header(),
      klt_points_positions_length(0), klt_points_positions(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->klt_points_positions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->klt_points_positions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->klt_points_positions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->klt_points_positions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->klt_points_positions_length);
      for( uint32_t i = 0; i < klt_points_positions_length; i++){
      offset += this->klt_points_positions[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t klt_points_positions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      klt_points_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      klt_points_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      klt_points_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->klt_points_positions_length);
      if(klt_points_positions_lengthT > klt_points_positions_length)
        this->klt_points_positions = (visp_tracker::KltPoint*)realloc(this->klt_points_positions, klt_points_positions_lengthT * sizeof(visp_tracker::KltPoint));
      klt_points_positions_length = klt_points_positions_lengthT;
      for( uint32_t i = 0; i < klt_points_positions_length; i++){
      offset += this->st_klt_points_positions.deserialize(inbuffer + offset);
        memcpy( &(this->klt_points_positions[i]), &(this->st_klt_points_positions), sizeof(visp_tracker::KltPoint));
      }
     return offset;
    }

    const char * getType(){ return "visp_tracker/KltPoints"; };
    const char * getMD5(){ return "681548d0f72044b7f086e3985d86f93c"; };

  };

}
#endif