#include "Barav2.hpp"
#include "raylib.h"
#include <iostream>
using namespace std;
void Barav2:: Update(int ball_y)
        {
            if(y+height/2>ball_y)
            y=y-speed;
            if(y+height/2<=ball_y)
            y=y+speed;
            LimiteEcran();

        }
        void Barav2::B2Reset()
        {
            y=GetScreenHeight()/2-height/2;
            x=10;
        }