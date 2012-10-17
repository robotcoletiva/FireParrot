#ifndef   _INPUT_DEVICE_CPP
#define   _INPUT_DEVICE_CPP

#include <InputDevice.h>
namespace fireparrot
{
    //
    //      Constructor
    InputDevice::InputDevice()
    {
    }
    //
    //      Destructor
    InputDevice::~InputDevice()
    {
    }
    //
    //      Return failure upon an attempt to call. New InputDevices should
    //      implement their own.
    //      NB. Tom: Input devices don't necessarily need to implement their own,
    //      as processing is done in the ProcessVideo and TrackSensors functions.
    //      All this needs to really do is store the data locally.
    //      I've left the function virtual just incase a device wants to override
    //      it anyway
    FlightParameters InputDevice::Update(DroneFeedback *data)
    {
        m_data = data;
        PollInput();
        ProcessVideo();
        TrackSensors();
        return m_flightParams;
    }
    //
    //       Do nothing; child classes should implement their own video proccessing.
    void InputDevice::ProcessVideo()
    {
    }
    //
    //       Empty function definition.
    void InputDevice::TrackSensors()
    {
    }
}

#endif /* _INPUT_DEVICE_CPP */
