#ifndef DRONE_H
#define DRONE_H

#include <DroneLib/ARDrone.h>
#include <CImg.h>

/**
 * Drone
 * ======
 *
 * Provides an interface to the drone's various inputs and outputs
 */


namespace cuardrone
{
    struct DroneFeedback
    {
        float altitude;
        vec3_t flightDynamics; // Pitch, Yaw, Roll
        vec3_t speed; // Speed in the x,y,z dirs
        unsigned int batteryLevel;
        CImg<unsigned char> videoFrame;
    };

    class Drone
    {
        public:
            enum CameraType { CAMERA_FRONT, CAMERA_DOWN };
        private:
            /**
             * Allows us to send movement controls to the drone
             */
            ARDrone::Controller m_controller;            

            /**
             * Allows us to grab feedback from the drone's gyro etc.
             */
            ARDrone::NavigationDataReciever* m_navdataReciever;

            /**
             * Provides video output from the drone
             */
            ARDrone::VideoDataReciever m_videoReciever;

            /**
             * Stores all the relevant feedback we get from the drone
             * Dynamically allocated once
             */
            DroneFeedback* m_droneFeedback;

        public:
            Drone(std::string ipAddr);
            virtual ~Drone();
            
            /**
             * Tells the drone to take off from the ground
             */
            void TakeOff();
            /**
             * Tells the drone to land
             */
            void Land();
            /**
             * Issues the emergency shutdown command
             */
            void EmergencyShutdown();
            /**
             * Sends our new control parameters in the form of our vec4
             * { pitch, yaw, roll, thrust }
             */
            void SendControlParameters(vec4_t params);

            /**
             * Allows switching between front and downward facing cameras
             */
            void SetCameraPosition(CameraType t);
            
            /**
             * Returns the DroneFeedback structure which has all the feedback
             * info from the drone
             */
            DroneFeedback GetFeedback();
    };
}

#endif
