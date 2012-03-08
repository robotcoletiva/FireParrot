#ifndef   _DRONE_H
#define   _DRONE_H

class Drone
{
        public:
                Drone();
                ~Drone();
                
                struct DroneFeedback *Update(vec4_t);
};

#endif /* _DRONE_H */
