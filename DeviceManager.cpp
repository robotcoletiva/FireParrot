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
//      Pull, convert and send data
int DeviceManager::Update()
{
        m_input->Tick(); /* alert the input device that there is data */
        
        return -1;
}

#endif /* _DEVICE_MANAGER_CPP */
