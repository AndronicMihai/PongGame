#include "bara.hpp"
#include "raylib.h"
#include <iostream>
using namespace std;

    void Bara::LimiteEcran()
    {
        if(y<=0)
        y=0;
        if(y+height>=GetScreenHeight())
        y=GetScreenHeight()-height;

    }
    Bara::Bara(): x(0), y(0), height(0), width(0), speed(0)
    {
    }
    Bara::~Bara()
    {
    }
    void Bara:: Draw()
    {
        DrawRectangleRounded(Rectangle{x,y,width,height},0.8,0,WHITE);
        
    }
    void Bara::Update()
    {
        if(IsKeyDown(KEY_UP))
            y=y-speed;
        if(IsKeyDown(KEY_DOWN))
            y=y+speed;
        LimiteEcran();
       
    }
    
   

