#ifndef   _DEVICE_MANAGER_CPP
#define   _DEVICE_MANAGER_CPP

#include "./DeviceManager.h"

//
//      Constructor
DeviceManager::DeviceManager()
{
}
//
//      Destructor
DeviceManager::~DeviceManager()
{
}
//
//
vec4_t DeviceManager::Convert(vec3_t, vec_t)
{
}
//
//
void DeviceManager::Update()
{
        m_input->Update();
        m_drone->Update(Convert(m_vecDirection, m_dRotation));
}

#endif /* _DEVICE_MANAGER_CPP */
