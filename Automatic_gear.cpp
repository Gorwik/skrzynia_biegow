#include <hFramework.h>

#include "Gear.cpp"
#include "Clutch.cpp"

class AutomaticGear{
    Gear gear = Gear();
    Clutch clutch = Clutch();
    static hFramework::hMotor hMot4;
    int power;
    int encoder_value[3];
    const int d_time = 300;
    const int coefficient = 1;
    const int lim_acc = 1;
    const int lim_power = 900;

    void main(){
        while (true){
            
        }
    }

    int check_acceleration(){
        for(int i = 0; i < 3; i++){
            encoder_value[i] = hMot1.getEncoderCnt();
            sys.delay(d_time);
        }
        int acceleration = coefficient * (encoder_value[2] - 2*encoder_value[1] + encoder_value[0]);

        return acceleration;
    }

    void change_gear(){
        int acc = check_acceleration();
        if (acc > lim_acc)
        {
            int actual_position = gear.actual_position;
            if (power >= lim_power && actual_position < 4)
                gear.change_gear(actual_position + 1);
        }

        else if (acc < lim_acc)
        {
            int actual_position = gear.actual_position;
            if (power >= lim_power && actual_position > 1)
                gear.change_gear(actual_position -1);
        }

        
    }
};