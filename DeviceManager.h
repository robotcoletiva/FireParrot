#ifndef   _DEVICE_MANAGER_H
#define   _DEVICE_MANAGER_H

#include <Common.h>


namespace cuardrone
{
    // Predefinitions
    class InputDevice;
    class Drone;
    
    class DeviceManager
    {
            private:
                    InputDevice *m_input;
                    Drone *m_drone;
                    
            public:
                    DeviceManager(InputDevice* dev, Drone* drone);
                    virtual ~DeviceManager();
                    
                    void Update();
    };
}
#endif /* _DEVICE_MANAGER_H */
