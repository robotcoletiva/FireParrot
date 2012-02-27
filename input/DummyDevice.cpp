#include <input/DummyDevice.h>

namespace cuardrone
{
    namespace input
    {
        DummyDevice::DummyDevice()
        {
            m_thrust = 0.25f; // 1/4 speed
            m_direction[0] = 0.0f; m_direction[1] = 1.0f;  // Forward at full velocity
            m_rotation = 0.1f;
        }

        DummyDevice::~DummyDevice()
        {
            /* empty */
        }

        float DummyDevice::GetThrust()
        {
            return m_thrust;
        }

        vec2_t* DummyDevice::GetDirection()
        {
            return &m_direction;
        }

        float DummyDevice::GetRotation()
        {
            return m_rotation;
        }
    }
}
