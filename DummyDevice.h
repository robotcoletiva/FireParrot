/**
 * DummyDevice
 * ==========
 *
 * This is a dummy implementation of the InputDevice class which provides some 
 * meaningless data output. Used for testing the device interface.
 */

#ifndef DUMMY_DEVICE_H
#define DUMMY_DEVICE_H

#include <InputDevice.h>

namespace cuardrone
{
    class DummyDevice : public InputDevice
    {
    private:
        float m_thrust;
        vec2_t m_velocity;
        float m_rotation;

    public:
        DummyDevice();
        virtual ~DummyDevice();

        float GetThrust();
        vec2_t* GetVelocity();
        float GetRotation();
    };
}

#endif
