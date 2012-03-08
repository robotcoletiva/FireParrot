#include <Drone.h>

namespace cuardrone
{
    Drone::Drone(std::string ipAddr)
    {
        m_controller.connectWithDroneAtAddress(ipAddr.c_str());
        m_navdataReciever = new ARDrone::NavigationDataReciever(&m_controller, ipAddr.c_str());
        m_videoReciever = new ARDrone::VideoDataReciever(&m_controller, ipAddr.c_str());
    
        m_droneFeedback = new DroneFeedback;
        
        m_controller->requestNavigationData();
        m_controller->requestVideoData();
        
        m_navdataReciever->start();
        m_videoReciever->start();
    }
    
    Drone::~Drone()
    {
        m_videoReciever->stop();
        m_navdataReciever->stop();
        
        delete m_droneFeedback;

        delete m_videoReciever;
        delete m_navdataReciever;
    }

    void Drone::TakeOff()
    {
        m_controller.takeOff();
    }

    void Drone::Land()
    {
        m_controller.land();
    }
    
    void Drone::EmergencyShutdown()
    {
        m_controller.sendEmergencyShutdown();
    }

    void Drone::SendControlParameters(vec4_t params)
    {
        m_controller.sendControlParameters(1, params[0], params[1], params[2], params[3]);
    }

    void Drone::SetCameraPosition(CameraType t)
    {
        switch (t)
        { 
        case Drone::CAMERA_FRONT:
            m_controller.switchToFrontCamera();
            break;
        case Drone::CAMERA_DOWN:
            m_controller.switchToDownCamera();
            break;
        }
    }

    DroneFeedback* Drone::GetFeedback()
    {
        static ARDrone::NavigationData data;
        static ARDrone::VideoDecoder::Image frame;

        m_navdataReciever->copyDataTo(data);
        m_videoReciever->copyDataTo(frame);

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
}
