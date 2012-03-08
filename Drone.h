#ifndef   _DRONE_H
#define   _DRONE_H

#include <Common.h>

class Drone
{
        public:
                Drone();
                ~Drone();
                
                DroneFeedback *Update(FlightParameters p);
};

#endif /* _DRONE_H */
