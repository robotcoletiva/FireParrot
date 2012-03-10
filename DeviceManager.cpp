#ifndef   _DEVICE_MANAGER_CPP
#define   _DEVICE_MANAGER_CPP

#include <DeviceManager.h>

#include <InputDevice.h>
#include <Drone.h>

namespace cuardrone
{
    //
    //      Constructor
    DeviceManager::DeviceManager(InputDevice* input, Drone* drone)
    {
        m_input = input;
        m_drone = drone;
    }
    //
    //      Destructor
    DeviceManager::~DeviceManager()
    {
    }
    //
    //
    void DeviceManager::Update()
    {
        FlightParameters p = m_input->Update(m_drone->GetFeedback());
        m_drone->Update(p);
    }
}
#endif /* _DEVICE_MANAGER_CPP */
