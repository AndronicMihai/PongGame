#pragma once

#include <raylib.h>
#include <Bara.hpp>


extern Color Verde;
extern Color Verde_Inchis;
extern Color Verde_Deschis;
extern Color Galben;
class Barav2:public Bara{
    public:
    void Update(int ball_y);
    void B2Reset();
        

};