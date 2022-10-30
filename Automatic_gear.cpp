#include <hFramework.h>

#include "Gear.cpp"
#include "Clutch.cpp"
#include "Engine.cpp"

class AutomaticGear
{
    Gear gear = Gear();
    Clutch clutch = Clutch();
    static Engine motor;
    int power;
    int encoder_value[3];
    const int d_time = 300;
    const int coefficient = 1;
    const int lim_acc_up = 1;
    const int lim_acc_down = 1;
    const int lim_power_up = 900;
    const int lim_power_down = 300;
    const int lim_speed = 1;

    void main()
    {
        while (true)
        {
            power = motor.get_power();
            change_gear();
            if (check_speed())
            {
                clutch.unclutch();
                gear.parking_position();
                break;
            }
        }
    }


    int check_acceleration()
    {
        for(int i = 0; i < 3; i++)
        {
            encoder_value[i] = motor.get_encoder_value();
            sys.delay(d_time);
        }
        int acceleration = coefficient * (encoder_value[2] - 2*encoder_value[1] + encoder_value[0]);

        return acceleration;
    }


    void change_gear()
    {
        int acc = abs(check_acceleration());
        if (acc < lim_acc_up)
        {
            int actual_position = gear.actual_position;
            if (power >= lim_power_up && actual_position < 4)
            {
                clutch.unclutch();
                gear.change_gear(actual_position + 1);
                clutch.clutch();
            }
        }

        else if (acc < -lim_acc_down || power < lim_power_down) 
        {
            int actual_position = gear.actual_position;
            if (actual_position > 1)
            {
                clutch.unclutch();
                gear.change_gear(actual_position -1);
                clutch.clutch();
            }
        }
    }


    bool check_speed()
    {
        int speed1 = abs(encoder_value[2] - encoder_value[1]);
        int speed2 = abs(encoder_value[1] - encoder_value[0]);
        int speed3 = abs(encoder_value[2] - encoder_value[0]);

        if (speed1 <= lim_speed && speed2 <= lim_speed && speed3 <= lim_speed)
            return true;
        else
            return false;
    }
};