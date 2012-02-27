#include <input/DummyDevice.h>

namespace cuardrone
{
    namespace input
    {
        DummyDevice::DummyDevice()
        {
            m_thrust = 0.25f; // 1/4 speed
            m_velocity[0] = 0.0f; 
            m_velocity[1] = 1.0f;  // Forward at full velocity
            m_rotation = 0.1f; // Slow clockwise rotation
        }

        DummyDevice::~DummyDevice()
        {
            /* empty */
        }

        float DummyDevice::GetThrust()
        {
            return m_thrust;
        }

        vec2_t* DummyDevice::GetVelocity()
        {
            return &m_velocity;
        }
        
        float DummyDevice::GetRotation()
        {
            return m_rotation;
        }
    }
}
