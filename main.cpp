#include <Common.h>

#include <unistd.h>
#include <iostream>

#include <Drone.h>
#include <DeviceManager.h>
#include <XBoxDevice.h>

using namespace cuardrone;

int main(int argc, char** argv)
{
    try {
        Drone drone("192.168.1.1");
        XBoxDevice controller;
        DeviceManager manager(&controller, &drone);
        
        while (true)
        {
            manager.Update(); // Update as fast as we can
        }
        
    } catch (DroneException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
