#ifndef _ROS_sengi_ros_Feedback_h
#define _ROS_sengi_ros_Feedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sengi_ros/JointFeedback.h"

namespace sengi_ros
{

  class Feedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      sengi_ros::JointFeedback drivers[2];

    Feedback():
      header(),
      drivers()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 2; i++){
      offset += this->drivers[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 2; i++){
      offset += this->drivers[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    const char * getType(){ return "sengi_ros/Feedback"; };
    const char * getMD5(){ return "23c8e1f51ba6794177a0678435d8b615"; };

  };

}
#endif