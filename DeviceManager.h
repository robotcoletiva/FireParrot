#ifndef   _DEVICE_MANAGER_H
#define   _DEVICE_MANAGER_H

#include <Common.h>


namespace cuardrone
{
    // Predefinitions
    class InputDevice;
    class Drone;
    /**
     * Bridges the InputDevice to the Drone
     */
    class DeviceManager
    {
    private:
        /**
         * A pointer to the input device used to control the drone.
         */
        InputDevice *m_input;
        /**
         * A pointer to the drone object we're communicating with
         */
        Drone *m_drone;
            
    public:
        /**
         * Constructor.
         * \param dev A pointer to an InputDevice to use
         * \param drone A pointer to a Drone object to use
         */
        DeviceManager(InputDevice* dev, Drone* drone);
        virtual ~DeviceManager();
        
        /**
         * Must be called periodically. Synchronizes the input device
         * with the drone and sends back any feedback data from the drone
         *
         * Also calls the functions in InputDevice which allow for processing
         * of data and polling of input
         */
        void Update();
    };
}
#endif /* _DEVICE_MANAGER_H */
