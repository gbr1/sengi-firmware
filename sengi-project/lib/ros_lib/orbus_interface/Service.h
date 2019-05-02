#ifndef _ROS_SERVICE_Service_h
#define _ROS_SERVICE_Service_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace orbus_interface
{

static const char SERVICE[] = "orbus_interface/Service";

  class ServiceRequest : public ros::Msg
  {
    public:
      typedef const char* _service_type;
      _service_type service;

    ServiceRequest():
      service("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_service = strlen(this->service);
      varToArr(outbuffer + offset, length_service);
      offset += 4;
      memcpy(outbuffer + offset, this->service, length_service);
      offset += length_service;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_service;
      arrToVar(length_service, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_service; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_service-1]=0;
      this->service = (char *)(inbuffer + offset-1);
      offset += length_service;
     return offset;
    }

    const char * getType(){ return SERVICE; };
    const char * getMD5(){ return "1cbcfa13b08f6d36710b9af8741e6112"; };

  };

  class ServiceResponse : public ros::Msg
  {
    public:
      typedef const char* _information_type;
      _information_type information;

    ServiceResponse():
      information("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_information = strlen(this->information);
      varToArr(outbuffer + offset, length_information);
      offset += 4;
      memcpy(outbuffer + offset, this->information, length_information);
      offset += length_information;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_information;
      arrToVar(length_information, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_information; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_information-1]=0;
      this->information = (char *)(inbuffer + offset-1);
      offset += length_information;
     return offset;
    }

    const char * getType(){ return SERVICE; };
    const char * getMD5(){ return "8f643f4492d5df4a7264b4dfdbe3626f"; };

  };

  class Service {
    public:
    typedef ServiceRequest Request;
    typedef ServiceResponse Response;
  };

}
#endif
