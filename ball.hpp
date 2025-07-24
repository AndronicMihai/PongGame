#pragma once

#include <raylib.h>



extern Color Verde;
extern Color Verde_Inchis;
extern Color Verde_Deschis;
extern Color Galben;
extern float timer;
class Ball {
public:
    float x, y;
    int radius;
    int speed_x, speed_y;
    int player2_score, player_score;
    Sound sound;

    Ball();
    Ball(float x, float y, int radius, int speed_x, int speed_y, int player2_score, int player_score);
    ~Ball();
    void Draw();
    bool Update();
    void Reset();
};