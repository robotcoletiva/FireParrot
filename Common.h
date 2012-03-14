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
typedef vec_t vec4_t[4];        /* four-dimension ...    */

namespace fireparrot
{
    /**
     * Contains bitmasks which are used for the FlightParameters flags field
     * \sa DroneFeedback
     */
    enum FlightFlags
    {
        FLAG_TAKEOFF    = (1 << 0),
        FLAG_LAND       = (1 << 1),
        FLAG_EMERGENCY  = (1 << 2),
        FLAG_SWITCHCAM  = (1 << 3)
    };
    /**
     * Allows us to easily locate a component of the flight dynamics within the vec3/vec4
     */
    enum DynamicsParams
    {
        FLIGHT_PITCH    = 0,
        FLIGHT_YAW      = 1,
        FLIGHT_ROLL     = 2,
        FLIGHT_THRUST   = 3
    };
    /**
     * Represents either the forward facing or downward facing camera
     */
    enum CameraPosition
    {
        CAMERA_FRONT,
        CAMERA_DOWN
    };
    /**
     * Contains all the relevant feedback data from the drone
     */
    struct DroneFeedback
    {
        float altitude;                 /*!< The current altitude of the drone */ 
        vec3_t flightDynamics;          /*!< The current flight dynamics (pitch,yaw,roll) of the drone */
        vec3_t speed;                   /*!< Speed in the x,y,z dirs */
        unsigned int batteryLevel;      /*!< Current battery level of the drone */
        CImg<unsigned char> videoFrame; /*!< The most recent video frame stored in a CImg */
    };
    /**
     * Contains all input to be sent to the drone
     */
    struct FlightParameters
    {
        vec4_t flightDynamics;          /*!< The current flight dynamics (pitch,yaw,roll) of the drone */
        uint8_t flags;                  /*!< Flight flag bitmap. See FlightFlags */
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
