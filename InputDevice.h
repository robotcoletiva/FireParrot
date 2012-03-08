#ifndef   _INPUT_DEVICE_H
#define   _INPUT_DEVICE_H

#include <Common.h>

class InputDevice
{
        protected:
                FlightParameters m_flightParams;               
 
                struct DroneFeedback *m_data;
                
                virtual void PollInput() = 0;
                virtual void ProcessVideo();
                virtual void TrackSensors();
                
        public:
                InputDevice();
                virtual ~InputDevice();
                
                virtual FlightParameters Update(DroneFeedback* feedback);
};

#endif /* _INPUT_DEVICE_H */
