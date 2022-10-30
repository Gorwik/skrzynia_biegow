#include <hFramework.h>

#include "Gear.cpp"
#include "Clutch.cpp"

class SemiAutomaticGear
{
    Gear gear = Gear();
    Clutch clutch = Clutch();

    static hFramework::hGPIO_super button_up;
    static hFramework::hGPIO_super button_down;
    

    public:
        SemiAutomaticGear()
        {
            button_up = hExt.pin1;
            button_down = hExt.pin2;
            button_up.setIn_pd();  // setting pin1 on hExt as the input with pull down resistor
            button_down.setIn_pd();  // setting pin1 on hExt as the input with pull down resistor
        }

    void main()
    {
        while (true)
        {
            if (button_up.read() && !button_down.read())
                change(1);
            else if (!button_up.read() && button_down.read())
                change(0);

            sys.delay(300);
        }
    }

    void change(bool dir)
    {
        int actual_position = gear.actual_position;
        if (dir)
        {
            if (actual_position < 4)
                clutch.clutch();
                gear.change(actual_position + 1);
                clutch.unclutch();
        }
        else
        {
            if (actual_position > 1)
                clutch.clutch();
                gear.change(gear.actual_position - 1);
                clutch.unclutch();
        }
    }
};
