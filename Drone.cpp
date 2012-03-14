#include <Drone.h>
namespace fireparrot
{
    Drone::Drone(std::string ipAddr)
    {
        m_controller.connectWithDroneAtAddress(ipAddr.c_str());
        m_navdataReceiver = new ARDrone::NavigationDataReceiver(&m_controller, ipAddr.c_str());
        m_videoReceiver = new ARDrone::VideoDataReceiver(&m_controller, ipAddr.c_str());
    
        m_droneFeedback = new DroneFeedback;
        
        m_controller.requestNavigationData();
        m_controller.requestVideoData();
        
        m_navdataReceiver->start();
        m_videoReceiver->start();
    }
    
    Drone::~Drone()
    {
        m_videoReceiver->stop();
        m_navdataReceiver->stop();
        
        delete m_droneFeedback;

        delete m_videoReceiver;
        delete m_navdataReceiver;
    }

    DroneFeedback* Drone::GetFeedback()
    {
        static ARDrone::NavigationData data;
        static ARDrone::VideoDecoder::Image frame;
        
        // Store feedback and return
        m_navdataReceiver->copyDataTo(data);
//        m_videoReceiver->copyDataTo(frame);

        m_droneFeedback->altitude = data.altitude;
        m_droneFeedback->batteryLevel = data.batteryLevel;
        m_droneFeedback->flightDynamics[0] = data.orientation.pitch;
        m_droneFeedback->flightDynamics[1] = data.orientation.yaw;
        m_droneFeedback->flightDynamics[2] = data.orientation.roll;
        m_droneFeedback->speed[0] = data.speed.vx;
        m_droneFeedback->speed[1] = data.speed.vy;
        m_droneFeedback->speed[2] = data.speed.vz;
        m_droneFeedback->videoFrame.assign(frame.data, frame.width, frame.height, 1, 3);
        return m_droneFeedback;
    }

    void Drone::Update(FlightParameters p)
    {
        // Process flags
        if ((p.flags & FLAG_TAKEOFF) != 0)
        {
            m_controller.takeOff();
        }

        if ((p.flags & FLAG_LAND) != 0)
        {
            m_controller.land();
        }
        if ((p.flags & FLAG_EMERGENCY) != 0)
        {
            m_controller.sendEmergencyShutdown();
        }
        if ((p.flags & FLAG_SWITCHCAM) != 0)
        {
            switch (m_currentCamera)
            {
            case CAMERA_FRONT:
                m_controller.switchToDownCamera();
                m_currentCamera = CAMERA_DOWN;
                break;
            case CAMERA_DOWN:
                m_controller.switchToFrontCamera();
                m_currentCamera = CAMERA_FRONT;
                break;
            }
        }
        // Send control params
        m_controller.sendControlParameters(1, p.flightDynamics[FLIGHT_PITCH], 
                p.flightDynamics[FLIGHT_ROLL], p.flightDynamics[FLIGHT_YAW],
                p.flightDynamics[FLIGHT_THRUST]);
    }
}
