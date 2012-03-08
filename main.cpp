#include <DroneConfig.h>

#include <unistd.h>

#include <Drone.h>

int main(int argc, char** argv)
{
    cuardrone::Drone d("192.168.1.1");
    sleep(2);
    d.TakeOff();
    sleep(4);
    d.Land();
    sleep(2);
    return 0;
}
