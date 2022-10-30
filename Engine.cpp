#include <hFramework.h>

class Engine
{
    int power;
    const int angle = 200;
    static hFramework::hMotor hMot4;

    public:
        Engine(int pow)
        {
            power = pow;
            hMot4.setEncoderPolarity(Polarity::Reversed);  //changing encoder polarity (Polarity::Normal is default)
            hMot4.setMotorPolarity(Polarity::Normal);  //changing motor polarity
        }

    void main()
    {
        while (true)
        {
            hMot4.rotRel(angle, power,false, INFINITE);
            sys.delay(200);
        }
        
    }

    void set_power(int pow)
    {
        power = pow;
    }

    int get_power()
    {
        return power;
    }

    int get_encoder_value()
    {
        return hMot4.getEncoderCnt();
    }
};