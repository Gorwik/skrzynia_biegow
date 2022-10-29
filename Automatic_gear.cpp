#include <hFramework.h>

#include "Gear.cpp"
#include "Clutch.cpp"

class AutomaticGear{
    Gear gear = Gear();
    Clutch clutch = Clutch();
    static hFramework::hMotor hMot4;
    int power;
    int encoder_value[3];

    void main(){
        while (true){
            
        }
    }

    bool check_acceleration(){
        for(int i = 0; i < 3; i++){
            encoder_value[i] = hMot1.getEncoderCnt();
            sys.delay(300);
        }
        int acceleration = encoder_value[2] - 2*encoder_value[1] + encoder_value[0];
    }
};