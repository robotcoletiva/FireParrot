#ifndef   _INPUT_DEVICE_H
#define   _INPUT_DEVICE_H

#include <Common.h>

namespace cuardrone {
    class InputDevice
    {
            protected:
                    FlightParameters m_flightParams;               
     
                    DroneFeedback *m_data;
                    
                    virtual void PollInput() = 0;
                    virtual void ProcessVideo();
                    virtual void TrackSensors();
                    
            public:
                    InputDevice();
                    virtual ~InputDevice();
                    
                    virtual FlightParameters Update(DroneFeedback* feedback) = 0;
    };
}

#endif /* _INPUT_DEVICE_H */
