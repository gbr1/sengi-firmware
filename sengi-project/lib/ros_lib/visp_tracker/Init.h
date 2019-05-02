#ifndef _ROS_SERVICE_Init_h
#define _ROS_SERVICE_Init_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "visp_tracker/TrackerSettings.h"
#include "visp_tracker/KltSettings.h"
#include "visp_tracker/MovingEdgeSettings.h"
#include "geometry_msgs/Transform.h"

namespace visp_tracker
{

static const char INIT[] = "visp_tracker/Init";

  class InitRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Transform _initial_cMo_type;
      _initial_cMo_type initial_cMo;
      typedef visp_tracker::TrackerSettings _tracker_param_type;
      _tracker_param_type tracker_param;
      typedef visp_tracker::MovingEdgeSettings _moving_edge_type;
      _moving_edge_type moving_edge;
      typedef visp_tracker::KltSettings _klt_param_type;
      _klt_param_type klt_param;

    InitRequest():
      initial_cMo(),
      tracker_param(),
      moving_edge(),
      klt_param()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->initial_cMo.serialize(outbuffer + offset);
      offset += this->tracker_param.serialize(outbuffer + offset);
      offset += this->moving_edge.serialize(outbuffer + offset);
      offset += this->klt_param.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->initial_cMo.deserialize(inbuffer + offset);
      offset += this->tracker_param.deserialize(inbuffer + offset);
      offset += this->moving_edge.deserialize(inbuffer + offset);
      offset += this->klt_param.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return INIT; };
    const char * getMD5(){ return "72f45c4391731722797b61d639ff8889"; };

  };

  class InitResponse : public ros::Msg
  {
    public:
      typedef bool _initialization_succeed_type;
      _initialization_succeed_type initialization_succeed;

    InitResponse():
      initialization_succeed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_initialization_succeed;
      u_initialization_succeed.real = this->initialization_succeed;
      *(outbuffer + offset + 0) = (u_initialization_succeed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->initialization_succeed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_initialization_succeed;
      u_initialization_succeed.base = 0;
      u_initialization_succeed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->initialization_succeed = u_initialization_succeed.real;
      offset += sizeof(this->initialization_succeed);
     return offset;
    }

    const char * getType(){ return INIT; };
    const char * getMD5(){ return "8e1a436e960986e0760f2970d0c88bf4"; };

  };

  class Init {
    public:
    typedef InitRequest Request;
    typedef InitResponse Response;
  };

}
#endif
