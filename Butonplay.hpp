#pragma once
#include <raylib.h>
class Butonplay
{
    public:
    Butonplay(const char* imagine, Vector2 positionimagine,float scale);
    ~Butonplay();
    void Draw();
    bool eapasat(Vector2 mouse_position,bool apasat );
    
    
    private:
    Texture2D texture;
    Vector2 position;


};