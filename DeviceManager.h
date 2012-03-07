#ifndef   _DEVICE_MANAGER_H
#define   _DEVICE_MANAGER_H

#include "./Drone.h"
#include "./InputDevice.h"

class DeviceManager
{
        private:
                Drone *m_drone;
                InputDevice *m_input;
                
                vec4_t Convert(vec3_t, vec_t);
        
        public:
                DeviceManager();
                ~DeviceManager();
                
                int Update();
};

#endif /* _DEVICE_MANAGER_H */
