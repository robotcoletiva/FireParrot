#ifndef XBOX_DEVICE_H
#define XBOX_DEVICE_H

#include <Common.h>

#include <InputDevice.h>

/**
 * XBoxDevice
 * ==========
 * 
 * This is an interface for the XBox 360 controller, using the gamepad
 * library by 'elanthis' <https://github.com/elanthis/gamepad>
 *
 * The controls are as follows:
 * Left stick = Pitch, Roll (Movement)
 * Right stick = Yaw (Rotation)
 * A = launch
 * B = land
 * Back = Emergency quit
 * Triggers = thrust
 */

namespace cuardrone
{
    class XBoxDevice : public InputDevice
    {
    private:

    protected:
        virtual void PollInput();
        virtual void ProcessVideo();
        virtual void TrackSensors();
        
    public:
        XBoxDevice() throw(DroneException);
        virtual ~XBoxDevice();
    };
}

#endif
