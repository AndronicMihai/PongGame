#include "ball.hpp"
#include "raylib.h"
#include "GameState.hpp"
#include <iostream>
using namespace std;


Ball::Ball(): x(0), y(0), radius(0), speed_x(0), speed_y(0), player2_score(0), player_score(0)
{
    sound=LoadSound("Sounds/minge.wav");
}

Ball::~Ball()
{
    UnloadSound(sound);
}
void Ball:: Draw()
{
    DrawCircle( x, y, radius,Galben);
}
bool Ball:: Update()
{
    SetSoundVolume(sound, 1.0f); 
    x+=speed_x;
        y+=speed_y;
        if(y+radius>=GetScreenHeight() || y-radius<=0)
        {
            speed_y=speed_y*-1;
            PlaySound(sound);
        }
        if(x+radius>=GetScreenWidth())
        {
            player2_score++;
            game_state=game_state2;
            timer=1.5f;
            Reset();
            return true;
        }
        if(x-radius<=0)
        {
            player_score++;
            game_state=game_state2;
            timer=1.5f;
            Reset();
            return true;
        }
        return false;

}
void Ball:: Reset()
{
    x=GetScreenWidth()/2;
        y=GetScreenHeight()/2;
        int variante[2]={-1,1};
        speed_x*=variante[GetRandomValue(0,1)];
        speed_y*=variante[GetRandomValue(0,1)];
        
        PlaySound(sound);

}