/** \mainpage CU-ARDrone
 *
 * \section sec_intro Intro
 * CU-AR Drone is an extensible interface between the Parrot AR Drone and 
 * multiple input devices. This project's main goal is to create an interface 
 * between the drone and Coventry University's merlin flight simulator, 
 * and is a joint effort between members of the university's Computer Club.
 *
 * \section sec_building Building
 * This project uses the cmake build system (<http://www.cmake.org/>). If you have CMake installed, type `cmake .` within the root folder to generate project/make files for your platform.
 *
 * \section sec_deps Dependencies
 * Windows:
 *
 * + XInput
 *
 * Linux:
 *
 * + libudev
 * + commonc++ (<http://www.hyperrealm.com/main.php?s=commoncpp>)
 * + libX11
 *
 * \section sec_todo TODO
 * + Come up with a better project name!!!
 * + Change namespaces to reflect said project name
 *
 * \section sec_thanks Thanks
 * With thanks to Sean Middleditch (<https://github.com/elanthis>) for his gamepad library and Pongsak Suvanpong of the ARDrone forums for the temporary ardrone API.
 *
 * \section sec_more More info
 * Some more information about the projects development can be found in the Wiki:
 * <https://github.com/PhoenixClub/CU-ARDrone/wiki>
 */
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
