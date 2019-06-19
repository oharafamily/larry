
class MotorRelay {
    private:
     int _speedpinA, _speedpinB, _pinI1, _pinI2, _pinI3, _pinI4;

    public:
        MotorRelay(int speedpinA, int speedpinB, int pinI1, int pinI2, int pinI3, int pinI4) {
            _speedpinA = speedpinA;
            _speedpinB = speedpinB;
            _pinI1 = pinI1;
            _pinI2 = pinI2;
            _pinI3 = pinI3;
            _pinI4 = pinI4;
        };
        void forward(int s) {
            analogWrite(_speedPinA,s);//input a simulation value to set the speed
            analogWrite(_speedpinB,s);
            digitalWrite(_pinI4,HIGH);//turn DC Motor B move clockwise
            digitalWrite(_pinI3,LOW);
            digitalWrite(_pinI2,LOW);//turn DC Motor A move anticlockwise
            digitalWrite(_pinI1,HIGH);
        };
        void backward(int s) {
            analogWrite(_speedPinA,s);//input a simulation value to set the speed
            analogWrite(_speedpinB,s);
            digitalWrite(_pinI4,LOW);//turn DC Motor B move anticlockwise
            digitalWrite(_pinI3,HIGH);
            digitalWrite(_pinI2,HIGH);//turn DC Motor A move clockwise
            digitalWrite(_pinI1,LOW);
        };
        void left(int s) {
            analogWrite(_speedPinA,s);//input a simulation value to set the speed
            analogWrite(_speedpinB,s);
            digitalWrite(_pinI4,HIGH);//turn DC Motor B move clockwise
            digitalWrite(_pinI3,LOW);
            digitalWrite(_pinI2,HIGH);//turn DC Motor A move clockwise
            digitalWrite(_pinI1,LOW);
        };
        void right(int s) {
            analogWrite(_speedPinA,s);//input a simulation value to set the speed
            analogWrite(_speedpinB,s);
            digitalWrite(_pinI4,LOW);//turn DC Motor B move anticlockwise
            digitalWrite(_pinI3,HIGH);
            digitalWrite(_pinI2,LOW);//turn DC Motor A move clockwise
            digitalWrite(_pinI1,HIGH);
        };
        void stop() {
            digitalWrite(_speedPinA,LOW);// Unenble the pin, to stop the motor. this should be done to avid damaging the motor. 
            digitalWrite(_speedpinB,LOW);
            delay(1000);
        
        };
}