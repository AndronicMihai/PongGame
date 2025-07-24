#include "baraw.hpp"
#include "raylib.h"
#include <iostream>
using namespace std;

    void baraw::LimiteEcran()
    {
        if(y<=0)
        y=0;
        if(y+height>=GetScreenHeight())
        y=GetScreenHeight()-height;

    }
    baraw::baraw(): x(0), y(0), height(0), width(0), speed(0)
    {
    }
    baraw::~baraw()
    {
    }
    void baraw:: Draw()
    {
        DrawRectangleRounded(Rectangle{x,y,width,height},0.8,0,WHITE);
        
    }
    void baraw::Update()
    {
        if(IsKeyDown(KEY_W))
            y=y-speed;
        if(IsKeyDown(KEY_S))
            y=y+speed;
        LimiteEcran();
       
    }

