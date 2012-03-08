#ifndef COMMON_H
#define COMMON_H

#include <CImg.h>

using namespace cimg_library;

typedef float vec_t;            /* scalar                 */
typedef vec_t vec2_t[2];        /* two-dimensional vector */
typedef vec_t vec3_t[3];        /* three-dimension ...    */
typedef vec_t vec4_t[4];        /* three-dimension ...    */

namespace cuardrone
{
    enum FlightFlags
    {
        FLAG_TAKEOFF    = 0x1;
        FLAG_LAND       = 0x2;
        FLAG_EMERGENCY  = 0x4;
    };
    struct DroneFeedback
    {
        float altitude;
        vec3_t flightDynamics; // Pitch, Yaw, Roll
        vec3_t speed; // Speed in the x,y,z dirs
        unsigned int batteryLevel;
        CImg<unsigned char> videoFrame;
    };
    struct FlightParameters
    {
        vec3_t flightDynamics;
        uint8_t flags; // See FlightFlags
    };
}

#endif
