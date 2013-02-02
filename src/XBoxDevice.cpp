#include <XBoxDevice.h>
#include <GLRenderFrame.h>

#include <cstring>

#include <gamepad/gamepad.h>

namespace fireparrot
{
    XBoxDevice::XBoxDevice() throw(DroneException)
    {
        GamepadInit();
        std::cout << "Gamepad init" << std::endl;
        if (!GamepadIsConnected(GAMEPAD_0))
        {
            throw DroneException("Unable to find gamepad!");
        }
        memset(&m_flightParams, 0, sizeof(m_flightParams));
        m_renderFrame = new GLRenderFrame(640, 480);
        m_renderFrame->StartRender();
    }

    XBoxDevice::~XBoxDevice()
    {
        m_renderFrame->StopRender();
        delete m_renderFrame;
        GamepadShutdown();
    }

    void XBoxDevice::PollInput()
    {
        GamepadUpdate(); // Update the status of the pad

        // Update flags
        if (GamepadButtonDown(GAMEPAD_0, BUTTON_A))
        {
            m_flightParams.flags |= FLAG_TAKEOFF;
        }
        if (GamepadButtonDown(GAMEPAD_0, BUTTON_B))
        {
            m_flightParams.flags |= FLAG_LAND;
        }
        if (GamepadButtonDown(GAMEPAD_0, BUTTON_BACK))
        {
            m_flightParams.flags |= FLAG_EMERGENCY;
        }
        if (GamepadButtonDown(GAMEPAD_0, BUTTON_RIGHT_SHOULDER))
        {
            m_flightParams.flags |= FLAG_SWITCHCAM;
        }


        // Update thrust
        float positiveThrust = GamepadTriggerLength(GAMEPAD_0, TRIGGER_RIGHT);
        float negativeThrust = GamepadTriggerLength(GAMEPAD_0, TRIGGER_LEFT);

        m_flightParams.flightDynamics[FLIGHT_THRUST] = positiveThrust - negativeThrust;

        // Update pitch, yaw, roll
        float xPos, yPos;
        xPos = yPos = 0.0f;
        GamepadStickNormXY(GAMEPAD_0, STICK_LEFT, &xPos, &yPos);
        m_flightParams.flightDynamics[FLIGHT_PITCH] = -yPos;
        m_flightParams.flightDynamics[FLIGHT_ROLL] = xPos;

        GamepadStickNormXY(GAMEPAD_0, STICK_RIGHT, &xPos, &yPos);
        m_flightParams.flightDynamics[FLIGHT_YAW] = xPos;
    }

    void XBoxDevice::ProcessVideo()
    {
        m_renderFrame->UpdateFrame(m_data->videoFrame);
    }

    void XBoxDevice::TrackSensors()
    {

    }
}
