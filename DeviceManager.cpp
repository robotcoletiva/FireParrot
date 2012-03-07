#ifndef   _DEVICE_MANAGER_CPP
#define   _DEVICE_MANAGER_CPP

//
//      Constructor
DeviceManager::DeviceManager()
{
}
//
//      Deconstructor
DeviceManager::~DeviceManager()
{
}
//
//      Convert a direction and rotation into a 'vec4_t' storing flight dynamics
vec4_t Convert(vec3_t direction, vec_t drotation)
{
        /*
        **      Makes the assumption that the drone uses +1.0f for clockwise
        **      rotation around an axis.
        */
        
        return { -direction[0], -direction[1], drotation, direction[2] }
}
//
//      Pull, convert and send data
int DeviceManager::Update()
{
        // Pull new data from the drone (camera frames, etc).
        
        m_input->Tick();       // Alert the input device that there is data
        m_input->Update();     // Force the input device to update { x, y, z }
        
        // Generated flight dynamics and send them to the drone.
        m_drone->Update(Convert(m_input->m_flight, m_input->m_dRotation));
        
        return 0;
}

#endif /* _DEVICE_MANAGER_CPP */
