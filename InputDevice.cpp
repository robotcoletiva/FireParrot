#ifndef   _INPUT_DEVICE_CPP
#define   _INPUT_DEVICE_CPP

#include "./InputDevice.h"

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
vec4_t InputDevice::Update(struct DroneFeedback *data)
{
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

#endif /* _INPUT_DEVICE_CPP */
