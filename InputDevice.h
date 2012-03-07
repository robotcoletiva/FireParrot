#ifndef   _INPUT_DEVICE_H
#define   _INPUT_DEVICE_H

class InputDevice
{
        private:
                
        protected:
                vec3_t m_vecDirection;
                vec_t m_dRotation;
                
                virtual void PollInput() = 0;
                virtual void ProcessVideo();
                virtual void TrackSensors();
                
        public:
                InputDevice();
                ~InputDevice();
                
                virtual int Update();
};

#endif /* _INPUT_DEVICE_H */
