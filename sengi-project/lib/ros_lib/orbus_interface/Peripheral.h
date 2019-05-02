#ifndef _ROS_orbus_interface_Peripheral_h
#define _ROS_orbus_interface_Peripheral_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace orbus_interface
{

  class Peripheral : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t gpio_length;
      typedef uint8_t _gpio_type;
      _gpio_type st_gpio;
      _gpio_type * gpio;

    Peripheral():
      header(),
      gpio_length(0), gpio(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      offset += this->header.deserialize(inbuffer + offset);
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

    const char * getType(){ return "orbus_interface/Peripheral"; };
    const char * getMD5(){ return "169401bf99118227b9e36599910f7117"; };

  };

}
#endif