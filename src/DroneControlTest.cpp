#include "ARDrone.h"

int main(int argc, char** argv)
{
    ARDrone::Controller controller;
    ARDrone::NavigationData navData;
    try 
    {
        controller.connectWithDroneAtAddress("192.168.1.1");
        ccxx::Thread::sleep(200);
        ARDrone::NavigationDataReceiver navDataReceiver(&controller, "192.168.1.1");
        navDataReceiver.start();
        ccxx::Thread::sleep(200);

        ARDrone::VideoDataReceiver vdoDataReceiver(&controller, "192.168.1.1");
        vdoDataReceiver.start();
        ccxx::Thread::sleep(200);

        controller.switchToFrontCamera();
        ARDrone::VideoDecoder::Image image;

        controller.takeOff();
        controller.hover();
        
        controller.sendControlParameters(1, 0, 0, 0.8, 0);
        
         
        for(int i = 0; i < 1000; i++)
        {
            controller.sendWatchDogReset();

            ccxx::Thread::sleep(200);

            navDataReceiver.copyDataTo(navData);
            std::cout << "->" << navData.orientation.pitch << ','
                << navData.orientation.roll << ','
                << navData.orientation.yaw << std::endl;

            std::cout << "Altitude: " << navData.altitude << std::endl;

            vdoDataReceiver.copyDataTo(image);

            //std::cout << "w->" << width << ",h->" << height << std::endl;

        } 
        
        ccxx::Thread::sleep(30000);
        controller.land();
        
        navDataReceiver.stop();
        vdoDataReceiver.stop();
    }
    catch(ccxx::Exception& ex) 
    {
        std::cout << ex.what() << std::endl;
    }


    return 0;
}
