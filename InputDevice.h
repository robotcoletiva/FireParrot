/**
 * InputDevice
 * ============
 *
 * This class is a generic interface which all input devices should implement. 
 * It makes a set of flight parameters available to the InputManager, which 
 * then get transformed into the correct form and sent to the Drone.
 */

#ifndef INPUT_DEVICE_H
#define INPUT_DEVICE_H

#include <string.h>

/**
 * NOTE: Temporary until Alex gets phi finished
 */
typedef float vec_t;            /* scalar                 */
typedef vec_t vec2_t[2];        /* two-dimensional vector */
typedef vec_t vec3_t[3];        /* three-dimension ...    */

namespace cuardrone
{
    class InputDevice
    {
    private:

    protected:
        /**
         * The most recent camera frame available
         */
        void* m_cameraFrame;
        /**
         * The most recent gyro reading
         */
        vec3_t m_gyroDynamics;

    public:
        InputDevice() { /* Not implemented */ }
        virtual ~InputDevice() { /* Not implemented */ }

        /**
         * Returns a float between -1 and 1 which represents thrust
         */
        virtual float GetThrust() = 0; /* Pure virtual */
        /**
         * Returns a normalized 3d vector which represents velocity
         * X = pitch, Y = roll
         */
        virtual vec2_t* GetVelocity() = 0; /* Pure virtual */
        /**
         * Returns a float between -1 and 1 which represents rotation (yaw)
         */
        virtual float GetRotation() = 0;
        /**
         * Stores the most recent camera frame
         * void* until we know the data type
         */
        void SetCameraFrame(void* cameraFrame) { m_cameraFrame = cameraFrame; }
        /**
         * Stores the more recent gyro reading available
         */
        void SetGyroDynamics(vec3_t* dynamics) { memcpy(&m_gyroDynamics, dynamics, sizeof(vec3_t)); }
    };
}

#endif
