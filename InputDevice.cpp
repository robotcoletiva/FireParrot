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
int InputDevice::Update()
{
        return -1;
}
//
//
void InputDevice::ProcessVideo()
{
}
//
//
void InputDevice::TrackSensors()
{
}

#endif /* _INPUT_DEVICE_CPP */
