#ifndef _ROS_SERVICE_srvtest_h
#define _ROS_SERVICE_srvtest_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace beginner_tutorials
{

static const char SRVTEST[] = "beginner_tutorials/srvtest";

  class srvtestRequest : public ros::Msg
  {
    public:
      int64_t A;

    srvtestRequest():
      A(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_A;
      u_A.real = this->A;
      *(outbuffer + offset + 0) = (u_A.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_A.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_A.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_A.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_A.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_A.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_A.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_A.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->A);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_A;
      u_A.base = 0;
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->A = u_A.real;
      offset += sizeof(this->A);
     return offset;
    }

    const char * getType(){ return SRVTEST; };
    const char * getMD5(){ return "cacada641c8116215aaa1be2ff0da518"; };

  };

  class srvtestResponse : public ros::Msg
  {
    public:
      int64_t B;

    srvtestResponse():
      B(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_B;
      u_B.real = this->B;
      *(outbuffer + offset + 0) = (u_B.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_B.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_B.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_B.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_B.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_B.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_B.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_B.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->B);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_B;
      u_B.base = 0;
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->B = u_B.real;
      offset += sizeof(this->B);
     return offset;
    }

    const char * getType(){ return SRVTEST; };
    const char * getMD5(){ return "bcfd7541e179b6902c80465b9e260b97"; };

  };

  class srvtest {
    public:
    typedef srvtestRequest Request;
    typedef srvtestResponse Response;
  };

}
#endif
