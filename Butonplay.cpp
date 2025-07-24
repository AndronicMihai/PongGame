#include "Butonplay.hpp"
#include "raylib.h"
#include <iostream>
using namespace std;
Butonplay::Butonplay(const char *imagine, Vector2 positionimagine,float scale)
{
    Image image=LoadImage(imagine);
    int original_width=image.width;
    int original_height=image.height;
    int new_width=static_cast<int>(original_width*scale);
    int new_height=static_cast<int>(original_height*scale);
    ImageResize(&image,new_width,new_height);
    texture=LoadTextureFromImage(image);
    UnloadImage(image);
    position=positionimagine;
}
Butonplay::~Butonplay()
{
    UnloadTexture(texture);
}
void Butonplay::Draw()
{
    DrawTexture(texture,position.x,position.y,WHITE);
}

bool Butonplay::eapasat(Vector2 mouse_position, bool apasat)
{
    Rectangle rect={position.x,position.y,static_cast<float>(texture.width),static_cast<float>(texture.height)};
    return CheckCollisionPointRec(mouse_position, rect) && apasat;
}
