#pragma once

#include <raylib.h>


extern Color Verde;
extern Color Verde_Inchis;
extern Color Verde_Deschis;
extern Color Galben;

class Bara 
{
    
   
    protected:
    void LimiteEcran();
    public:
    Bara();
    Bara(float x, float y, float height, float width, float speed);
    ~Bara();
    float x,y;
    float height;
    float width;
    float speed;
    int score=0;
    void Draw();
    void Update();
    
    

};