#ifndef   _DRONE_H
#define   _DRONE_H

#include <Common.h>

#include <dronelib/ARDrone.h>


namespace fireparrot
{
    /**
     * Provides an interface to the drone's various inputs and outputs
     */
    class Drone
    {
    private:
        /**
         * Allows us to send movement controls to the drone
         */
        ARDrone::Controller m_controller;            

        /**
         * Allows us to grab feedback from the drone's gyro etc.
         */
        ARDrone::NavigationDataReceiver* m_navdataReceiver;

        /**
         * Provides video output from the drone
         */
        ARDrone::VideoDataReceiver* m_videoReceiver;

        /**
         * Stores all the relevant feedback we get from the drone
         * Dynamically allocated once
         */
        DroneFeedback* m_droneFeedback;

        /**
         * The current camera position
         */
        CameraPosition m_currentCamera;
        
    public:
        Drone(std::string ipAddr);
        ~Drone();

        /**
         * Sends the flight parameters to the drone
         * \param p The flight parameters to send
         */        
        void Update(FlightParameters p);
        /**
         * Retrieves the feedback data
         * \returns A pointer to the feedback data to be given to the input device
         */
        DroneFeedback* GetFeedback();
    };
}
#endif /* _DRONE_H */
