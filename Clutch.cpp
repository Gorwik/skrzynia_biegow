#include <hFramework.h>

class Clutch
{
    const int angle = 5;
    const int power = 5;
    bool isClutched;
    static hFramework::hMotor hMot1;

    public:
        Clutch()
        {
            hMot1.setEncoderPolarity(Polarity::Reversed);  //changing encoder polarity (Polarity::Normal is default)
            hMot1.setMotorPolarity(Polarity::Normal);  //changing motor polarity
        }

    void clutch()
    {
        if (!isClutched)
            hMot1.rotRel(angle, power, true, INFINITE);
    };


    void unclutch()
    {
        if (isClutched)
            hMot1.rotRel(-angle, power, true, INFINITE);
    };
};