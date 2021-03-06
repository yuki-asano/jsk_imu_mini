#ifndef _ROS_SERVICE_GetTransformableMarkerColor_h
#define _ROS_SERVICE_GetTransformableMarkerColor_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/ColorRGBA.h"

namespace jsk_interactive_marker
{

static const char GETTRANSFORMABLEMARKERCOLOR[] = "jsk_interactive_marker/GetTransformableMarkerColor";

  class GetTransformableMarkerColorRequest : public ros::Msg
  {
    public:
      const char* target_name;

    GetTransformableMarkerColorRequest():
      target_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_target_name = strlen(this->target_name);
      memcpy(outbuffer + offset, &length_target_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->target_name, length_target_name);
      offset += length_target_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_target_name;
      memcpy(&length_target_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target_name-1]=0;
      this->target_name = (char *)(inbuffer + offset-1);
      offset += length_target_name;
     return offset;
    }

    const char * getType(){ return GETTRANSFORMABLEMARKERCOLOR; };
    const char * getMD5(){ return "2008933b3c7227647cbe00c74682331a"; };

  };

  class GetTransformableMarkerColorResponse : public ros::Msg
  {
    public:
      std_msgs::ColorRGBA color;

    GetTransformableMarkerColorResponse():
      color()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->color.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->color.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETTRANSFORMABLEMARKERCOLOR; };
    const char * getMD5(){ return "3e04b62b1b39cd97e873789f0bb130e7"; };

  };

  class GetTransformableMarkerColor {
    public:
    typedef GetTransformableMarkerColorRequest Request;
    typedef GetTransformableMarkerColorResponse Response;
  };

}
#endif
