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

/**
 * NOTE: Temporary until Alex gets phi finished
 */
typedef float vec_t;            /* scalar                 */
typedef vec_t vec2_t[2];        /* two-dimensional vector */

namespace cuardrone
{
    namespace input
    {
        class InputDevice
        {
        private:
            
        public:
            InputDevice() { /* Not implemented */ }
            virtual ~InputDevice() { /* Not implemented */ }

            /**
             * Returns a float between -1 and 1 which represents thrust
             */
            virtual float GetThrust() = 0; /* Pure virtual */
            /**
             * Returns a normalized 2d vector which represents direction
             * TODO: Come up with a better name?
             */
            virtual vec2_t* GetDirection() = 0; /* Pure virtual */
            /**
             * Returns a float between -1 and 1 which represents rotation (yaw)
             */
            virtual float GetRotation() = 0; /* Pure virtual */
        };
    }
}

#endif
