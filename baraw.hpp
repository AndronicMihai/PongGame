#pragma once
#include <raylib.h>


extern Color Verde;
extern Color Verde_Inchis;
extern Color Verde_Deschis;
extern Color Galben;

class baraw
{
    
   
    protected:
    void LimiteEcran();
    public:
    baraw();
    baraw(float x, float y, float height, float width, float speed);
    ~baraw();
    float x,y;
    float height;
    float width;
    float speed;
    int score=0;
    void Draw();
    void Update();
    

};