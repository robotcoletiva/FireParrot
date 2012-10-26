#ifndef   _INPUT_DEVICE_H
#define   _INPUT_DEVICE_H

#include <Common.h>

namespace fireparrot
{
    /**
     * An interface which all control devices must implement.
     * Allows an input device to communicate with the drone.
     */
    class InputDevice
    {
    protected:
        /**
         * A local copy of the current flight parameters
         */
        FlightParameters m_flightParams;
        /**
         * A local pointer to the feedback from the drone
         */
        DroneFeedback *m_data;
        
        /**
         * Allows the input device to poll any hardware
         * and store the new flight parameters.
         */
        virtual void PollInput() = 0;
        /**
         * An area where you may read and process/display the image if necessary
         */
        virtual void ProcessVideo();
        /**
         * An area where you may process the sensors if necessary
         */
        virtual void TrackSensors();
            
    public:
        InputDevice();
        virtual ~InputDevice();
        
        /**
         * Copies the drone feedback locally and returns the output flight
         * parameters.
         * \param feedback A pointer to the DroneFeedback structure
         * \return A copy of the flight parameters to be passed to the drone
         */
        virtual FlightParameters Update(DroneFeedback* feedback);
    };
}

#endif /* _INPUT_DEVICE_H */
