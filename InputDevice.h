#ifndef   _INPUT_DEVICE_H
#define   _INPUT_DEVICE_H

class InputDevice
{
        protected:
                vec3_t m_vecDirection;
                vec_t m_dRotation;
                
                struct DroneFeedback *m_data;
                
                virtual void PollInput() = 0;
                virtual void ProcessVideo();
                virtual void TrackSensors();
                
        public:
                InputDevice();
                virtual ~InputDevice();
                
                virtual int Update(struct DroneFeedback*);
};

#endif /* _INPUT_DEVICE_H */
