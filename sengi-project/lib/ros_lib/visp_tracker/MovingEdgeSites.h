#ifndef _ROS_visp_tracker_MovingEdgeSites_h
#define _ROS_visp_tracker_MovingEdgeSites_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "visp_tracker/MovingEdgeSite.h"

namespace visp_tracker
{

  class MovingEdgeSites : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t moving_edge_sites_length;
      typedef visp_tracker::MovingEdgeSite _moving_edge_sites_type;
      _moving_edge_sites_type st_moving_edge_sites;
      _moving_edge_sites_type * moving_edge_sites;

    MovingEdgeSites():
      header(),
      moving_edge_sites_length(0), moving_edge_sites(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->moving_edge_sites_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->moving_edge_sites_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->moving_edge_sites_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->moving_edge_sites_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->moving_edge_sites_length);
      for( uint32_t i = 0; i < moving_edge_sites_length; i++){
      offset += this->moving_edge_sites[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t moving_edge_sites_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      moving_edge_sites_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      moving_edge_sites_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      moving_edge_sites_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->moving_edge_sites_length);
      if(moving_edge_sites_lengthT > moving_edge_sites_length)
        this->moving_edge_sites = (visp_tracker::MovingEdgeSite*)realloc(this->moving_edge_sites, moving_edge_sites_lengthT * sizeof(visp_tracker::MovingEdgeSite));
      moving_edge_sites_length = moving_edge_sites_lengthT;
      for( uint32_t i = 0; i < moving_edge_sites_length; i++){
      offset += this->st_moving_edge_sites.deserialize(inbuffer + offset);
        memcpy( &(this->moving_edge_sites[i]), &(this->st_moving_edge_sites), sizeof(visp_tracker::MovingEdgeSite));
      }
     return offset;
    }

    const char * getType(){ return "visp_tracker/MovingEdgeSites"; };
    const char * getMD5(){ return "5293e8601467590a0dabbb34da47310c"; };

  };

}
#endif