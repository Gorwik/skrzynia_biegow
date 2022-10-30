#include <hFramework.h>

#include "Gear.cpp"
#include "Clutch.cpp"

class ManualGear
{
    Gear gear = Gear();
    Clutch clutch = Clutch();
    static hFramework::hMotor hMot4;
    int power;
    bool clutch_pressed;
    bool unclutch_pressed;
    bool change_gear_pressed;
    int position;

    void main()
    {
        while(true)
        {
            if (clutch_pressed)
            {
                clutch.clutch();
                clutch_pressed = false;
            }
            else if (unclutch_pressed)
            {
                clutch.unclutch();
                unclutch_pressed = false;
            }
            else if (change_gear_pressed)
            {
                gear.change(position);
                change_gear_pressed = false;
            }
        }
    }
};