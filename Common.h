#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <iostream>
#include <stdint.h>
#include <exception>

#include <CImg.h>
#include <DroneConfig.h>

using namespace cimg_library;

typedef float vec_t;            /* scalar                 */
typedef vec_t vec2_t[2];        /* two-dimensional vector */
typedef vec_t vec3_t[3];        /* three-dimension ...    */
typedef vec_t vec4_t[4];        /* three-dimension ...    */

namespace cuardrone
{
    enum FlightFlags
    {
        FLAG_TAKEOFF    = (1 << 0),
        FLAG_LAND       = (1 << 1),
        FLAG_EMERGENCY  = (1 << 2),
        FLAG_SWITCHCAM  = (1 << 3)
    };
    enum DynamicsParams
    {
        FLIGHT_PITCH    = 0,
        FLIGHT_YAW      = 1,
        FLIGHT_ROLL     = 2,
        FLIGHT_THRUST   = 3
    };
    enum CameraPosition
    {
        CAMERA_FRONT,
        CAMERA_DOWN
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
        vec4_t flightDynamics;
        uint8_t flags; // See FlightFlags
    };
    class DroneException : public std::exception
    {
    private:
        std::string m_what;
    public:
        DroneException(std::string what) : m_what(what) {}
        virtual ~DroneException() throw() { }

        const char* what() const throw() { return m_what.c_str(); }
    };
}

#endif
