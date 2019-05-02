#ifndef _ROS_SERVICE_GPIO_h
#define _ROS_SERVICE_GPIO_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace orbus_interface
{

static const char GPIO[] = "orbus_interface/GPIO";

  class GPIORequest : public ros::Msg
  {
    public:
      uint32_t gpio_length;
      typedef uint8_t _gpio_type;
      _gpio_type st_gpio;
      _gpio_type * gpio;

    GPIORequest():
      gpio_length(0), gpio(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->gpio_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gpio_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gpio_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gpio_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gpio_length);
      for( uint32_t i = 0; i < gpio_length; i++){
      *(outbuffer + offset + 0) = (this->gpio[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gpio[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t gpio_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      gpio_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      gpio_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      gpio_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->gpio_length);
      if(gpio_lengthT > gpio_length)
        this->gpio = (uint8_t*)realloc(this->gpio, gpio_lengthT * sizeof(uint8_t));
      gpio_length = gpio_lengthT;
      for( uint32_t i = 0; i < gpio_length; i++){
      this->st_gpio =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_gpio);
        memcpy( &(this->gpio[i]), &(this->st_gpio), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return GPIO; };
    const char * getMD5(){ return "d022e8c8de5b6b763eac9a1e9fcd80b7"; };

  };

  class GPIOResponse : public ros::Msg
  {
    public:
      typedef const char* _information_type;
      _information_type information;

    GPIOResponse():
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

    const char * getType(){ return GPIO; };
    const char * getMD5(){ return "8f643f4492d5df4a7264b4dfdbe3626f"; };

  };

  class GPIO {
    public:
    typedef GPIORequest Request;
    typedef GPIOResponse Response;
  };

}
#endif
