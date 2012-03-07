#ifndef   _DEVICE_MANAGER_H
#define   _DEVICE_MANAGER_H

#include "./Drone.h"
#include "./InputDevice.h"

class DeviceManager
{
        private:
                Drone *m_drone;
                InputDevice *m_input;
        
        public:
                DeviceManager();
                ~DeviceManager();
                
                int Update();
};

#endif /* _DEVICE_MANAGER_H */
