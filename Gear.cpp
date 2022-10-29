#include <hFramework.h>

class Gear{
    public:
        int actual_position;
    private:
        bool is_neutral;

        const int angle_left = 5;
        const int angle_right = 5;
        const int angle_neutral = 5;

        const int angle_linear_1_2 = 5;
        const int angle_linear_3_4 = 5;
        const int angle_linear_5_0 = 5;

        const int power = 5;

        static hFramework::hMotor hMot2;
        static hFramework::hMotor hMot3;

    public:
        Gear(){
            // actuator responsible for changing angle_rotate
            hMot2.setEncoderPolarity(Polarity::Reversed);  //changing encoder polarity (Polarity::Normal is default)
            hMot2.setMotorPolarity(Polarity::Normal);  //changing motor polarity
            //actuator responsible for displacement
            hMot3.setEncoderPolarity(Polarity::Reversed);  //changing encoder polarity (Polarity::Normal is default)
            hMot3.setMotorPolarity(Polarity::Normal);  //changing motor polarity
        }

    void change(int reach_position){
        change_to_neutral();
        change_gear(reach_position);
        actual_position = reach_position;
    }

    void change_to_neutral(){
        if (!is_neutral)
            hMot2.rotAbs(angle_neutral, power,true, INFINITE);
    }

    void rotate(bool dir){
        if (dir)
            hMot2.rotAbs(angle_left, power, true, INFINITE);
        else
            hMot2.rotAbs(angle_right, power, true, INFINITE);
    }

    void move_linear(int reach_position){
        if (reach_position == 1 || reach_position == 2)
            hMot3.rotAbs(angle_linear_1_2, power, true, INFINITE);
        else if (reach_position == 3 || reach_position == 4)
            hMot3.rotAbs(angle_linear_3_4, power, true, INFINITE);
        else if (reach_position == 5 || reach_position == 0)
            hMot3.rotAbs(angle_linear_5_0, power, true, INFINITE);
    }

    void change_gear(int reach_position){
        move_linear(reach_position);
        if (reach_position == 1 || reach_position == 3 || reach_position == 5)
            rotate(true);
        else if (reach_position == 2 || reach_position == 4 || reach_position == 0)
            rotate(false);
    }
};