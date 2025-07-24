#include <iostream>
#include <raylib.h>
#include <cstring>
#include "ball.hpp"
#include "Bara.hpp"
#include "Barav2.hpp"
#include "Butonplay.hpp"
#include "GameState.hpp"
#include "baraw.hpp"
#include "Persoana.hpp"
Color Verde = Color {38,185,154,255};
Color Verde_Inchis = Color{20,160,133,255};
Color Verde_Deschis =Color{129,204,184,255};
Color Galben = Color {243,213,91,255};


using namespace std;

GameState game_state=MENU;
GameState game_state2=TIMERGOL2;
float timer=5.0f;   
Ball ball;
Bara player;
baraw playerw;
Barav2 player2;


int main () {
    InitAudioDevice();
    char player1[50]="Guest1";
    char player3[50]="Guest2";
    Persoana p1;
    Persoana p2;
    char inputText[50]= "";
            int nr=0;
    const int screen_witdh=1200;
    const int screen_height=800;
    {
    ball.y=screen_height/2;
    ball.x=screen_witdh/2;
    ball.radius=20;
    ball.speed_x=7;
    ball.speed_y=7;
    ball.player2_score=0;
    ball.player_score=0;
    }
    {

        player.height=120;
        player.width=25;
        player.x=screen_witdh-player.width-10;
        player.y=screen_height/2-player.height/2;
        player.speed=6;

    }
    {   
        player2.height=120;
        player2.width=25;
        player2.x=10;
        player2.y=screen_height/2-player2.height/2;
        player2.speed=6;
    }
    {
        playerw.height=120;
        playerw.width=25;
        playerw.x=10;
        playerw.y=screen_height/2-player2.height/2;
        playerw.speed=6;
    }
    
    InitWindow(screen_witdh,screen_height,"Primu meu joc");
    
     
    Texture2D background=LoadTexture("Graphics/BACKGRD.png");
    Texture2D Meniujoc=LoadTexture("Graphics/MeniuJOC2.png");
    
    Butonplay butonvs={"Graphics/Butonvs.png",{screen_witdh/2-120,screen_height/2-150},0.65};
    Butonplay playbutton={"Graphics/Start.png",{450,300},0.65};
    Butonplay buton1vs1={"Graphics/Buton1vs1.png",{screen_witdh/2-120,screen_height/2},0.65};
    Butonplay back={"Graphics/Back.png",{screen_witdh-100,screen_height/2+320},0.65};
    Butonplay back2={"Graphics/Back.png",{screen_witdh/2,0},0.65};
    Butonplay logbutton={"Graphics/LOGIN.png",{450,420},0.65};
    Butonplay butonSTATS={"Graphics/STATS.png",{450,540},0.65};

SetTargetFPS(60);
while(WindowShouldClose()==false)
{
    Vector2 mouse_position=GetMousePosition();
    bool apasat=IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
    
    BeginDrawing();

    switch (game_state){
        case MENU:
        {
            //cout<<"IN MENIU\n";
            DrawTexture(background,0,0,WHITE);
            playbutton.Draw();
            if(playbutton.eapasat(mouse_position,apasat))
            {
                game_state=MENU2;
                //timer=5.0f;
            }
            logbutton.Draw();
            if(logbutton.eapasat(mouse_position,apasat))
            {
                game_state=login;
            }
           butonSTATS.Draw();
            if(butonSTATS.eapasat(mouse_position,apasat))
            {
                game_state=STATSS;
            }
        } break;
        case STATSS:
        {
            ClearBackground(Verde_Deschis);
            DrawText(TextFormat("Nume: %s",p1.getNume()),screen_witdh/2-200,screen_height/2-50,30,WHITE);
            DrawText(TextFormat("Victorii: %i",p1.getVictorii()),screen_witdh/2-200,screen_height/2+100,30,WHITE);
            DrawText(TextFormat("Infrangeri: %i",p1.getInfrangeri()),screen_witdh/2-200,screen_height/2+150,30,WHITE);
            back.Draw();
            if(back.eapasat(mouse_position,apasat))
            {
                game_state=MENU;
            }
        }break;
        case login:
        {
            ClearBackground(Verde_Deschis);
            DrawText("Introdu numele:",screen_witdh/2-200,screen_height/2-50,30,WHITE);
            DrawText(inputText, screen_witdh / 2 - 200, screen_height / 2, 30, WHITE);
            int key=GetCharPressed();
            if(key>0)
            {
                if(key>=32 && key<=125 && nr<50)
                {
                    inputText[nr]=key;
                    nr++;
                    inputText[nr]='\0';
                }
                
                
            }
            if(IsKeyPressed(KEY_BACKSPACE) && nr>0)
                {
                    nr--;
                    inputText[nr]='\0';
                }
            if(IsKeyPressed(KEY_ENTER))
            {
                p1.setNume(inputText);
                p1.incarcaDinFisier("Statistici.txt",inputText);
                game_state=MENU;
            }
            if(IsKeyPressed(KEY_ESCAPE))
            {
                game_state=MENU;
            }
           
            
            
            
        }break;
        case TIMER:
        {
            ClearBackground(Verde_Deschis);
            DrawText(TextFormat("Incepe jocul in %.1f secunde",timer),screen_witdh/2-200,screen_height/2-50,30,WHITE);
            timer-=GetFrameTime();
            if(timer<=0.0f)
            {
                game_state=JOC;
            }
        }break;
        case TIMERpvp:
        {
            ClearBackground(Verde_Deschis);
            DrawText(TextFormat("Incepe jocul in %.1f secunde",timer),screen_witdh/2-200,screen_height/2-50,30,WHITE);
            timer-=GetFrameTime();
            if(timer<=0.0f)
            {
                game_state=JOC2;
            }
        }break;
        case JOC:{
                
                        ClearBackground(Verde_Deschis);
                        if( ball.Update())
                       {player.y=GetScreenHeight()/2-player.height/2;
                        player2.y=GetScreenHeight()/2;
                     }
                        player.Update();
                        player2.Update(ball.y);
                        //cout<<"Dupa player2 update\n";
                            if(CheckCollisionCircleRec(Vector2{ball.x,ball.y},ball.radius,Rectangle{player.x,player.y,player.width,player.height}))
                                {
                                    ball.speed_x*=-1;
                                }
                            if(CheckCollisionCircleRec(Vector2{ball.x,ball.y},ball.radius,Rectangle{player2.x,player2.y,player2.width,player2.height}))
                                {
                                    ball.speed_x*=-1;
                                }
                            DrawRectangle(screen_witdh/2,0,screen_witdh/2,screen_height,Verde_Inchis);
                           // cout<<"INainte de player draw\n";
                            player.Draw();
                            player2.Draw();
                            back2.Draw();
                            if(back2.eapasat(mouse_position,apasat))
                            {
                                
                                ball.player2_score=0;
                                ball.player_score=0;   
                               game_state=MENU2;
                               p1.salveazaInFisier("Statistici.txt");
                            }

                            
                            
                            //cout<<"Dupa player draw\n";
                            DrawCircle(screen_witdh/2,screen_height/2,200,Verde);
                           //cout<<"Dupa draw circle\n";
                            DrawLine(screen_witdh/2,0,screen_witdh/2,screen_height,WHITE);
                            ball.Draw();
                        //cout<<"Dupa draw ball\n";
                            DrawText(TextFormat("%i",ball.player2_score),screen_witdh/4-20,20,80,WHITE);
                            DrawText(TextFormat("%i",ball.player_score),3*screen_witdh/4-20,20,80,WHITE);
                        //cout<<"Dupa draw text/n";
                        if(ball.player_score==5)
                        {
                            strcpy(player1,p1.getNume());
                            ball.player2_score=0;
                            ball.player_score=0; 
                            game_state=victorie;
                            p1.adaugaVictorie();
                            timer=2.5f;
                            p1.salveazaInFisier("Statistici.txt");
                        }
                        if(ball.player2_score==5)
                        {
                            strcpy(player1,"Player 2");
                            p1.adaugaInfrangere();
                            ball.player2_score=0;
                            ball.player_score=0; 
                            game_state=victorie;
                            timer=2.5f;
                            p1.salveazaInFisier("Statistici.txt");
                        }
                    
                 }break;
        case JOC2:
        {
            ClearBackground(Verde_Deschis);
                       if( ball.Update())
                       {player.y=GetScreenHeight()/2-player.height/2;
                        playerw.y=screen_height/2-player2.height/2;
                     }
                        player.Update();
                        playerw.Update();
                        //cout<<"Dupa player2 update\n";
                            if(CheckCollisionCircleRec(Vector2{ball.x,ball.y},ball.radius,Rectangle{player.x,player.y,player.width,player.height}))
                                {
                                    ball.speed_x*=-1;
                                }
                            if(CheckCollisionCircleRec(Vector2{ball.x,ball.y},ball.radius,Rectangle{playerw.x,playerw.y,playerw.width,playerw.height}))
                                {
                                    ball.speed_x*=-1;
                                }
                            DrawRectangle(screen_witdh/2,0,screen_witdh/2,screen_height,Verde_Inchis);
                           // cout<<"INainte de player draw\n";
                            player.Draw();
                            playerw.Draw();
                            back2.Draw();
                            if(back2.eapasat(mouse_position,apasat))
                            {
                                //tre sa modific scoru
                                ball.player2_score=0;
                                ball.player_score=0;   
                               game_state=MENU2;
                               p1.salveazaInFisier("Statistici.txt");
                            }
                            
                            
                            //cout<<"Dupa player draw\n";
                            DrawCircle(screen_witdh/2,screen_height/2,200,Verde);
                           //cout<<"Dupa draw circle\n";
                            DrawLine(screen_witdh/2,0,screen_witdh/2,screen_height,WHITE);
                            ball.Draw();
                        //cout<<"Dupa draw ball\n";
                            DrawText(TextFormat("%i",ball.player2_score),screen_witdh/4-20,20,80,WHITE);
                            DrawText(TextFormat("%i",ball.player_score),3*screen_witdh/4-20,20,80,WHITE);
                        //cout<<"Dupa draw text/n";
                        if(ball.player_score==5)
                        {
                            strcpy(player1,p1.getNume());
                            p1.adaugaVictorie();
                            ball.player2_score=0;
                            ball.player_score=0; 
                            game_state=victorie;
                            timer=2.5f;
                            p1.salveazaInFisier("Statistici.txt");
                        }
                        if(ball.player2_score==5)
                        {
                            strcpy(player1,"Player 2");
                            p1.adaugaInfrangere();
                            ball.player2_score=0;
                            ball.player_score=0; 
                            game_state=victorie;
                            timer=2.5f;
                            p1.salveazaInFisier("Statistici.txt");
                        }

        }break;
        case TIMERGOL2:
        {
            if(timer<=1.5f && timer>=1.0f)
            {
                ClearBackground(Verde_Deschis);
                DrawText(TextFormat("GOOOOOOOL"),screen_witdh/2-200,screen_height/2-50,80,WHITE);
            }
            if(timer<1.0f)
            {
                ClearBackground(Verde_Deschis);
                DrawText(TextFormat("GET BACK READY"),screen_witdh/2-350,screen_height/2-50,80,WHITE);
            }
            timer-=GetFrameTime();
            if(timer<=0.0f)
            {
                game_state=JOC;
            }
        }break;
        case TIMERGOLPVP:
        {
            if(timer<=1.5f && timer>=1.0f)
            {
                ClearBackground(Verde_Deschis);
                DrawText(TextFormat("GOOOOOOOL"),screen_witdh/2-200,screen_height/2-50,80,WHITE);
            }
            if(timer<1.0f)
            {
                ClearBackground(Verde_Deschis);
                DrawText(TextFormat("GET BACK READY"),screen_witdh/2-350,screen_height/2-50,80,WHITE);
            }
            timer-=GetFrameTime();
            if(timer<=0.0f)
            {
                game_state=JOC2;
            }
        }break;

        case MENU2:
        {
            DrawTexture(Meniujoc,0,0,WHITE);
                    butonvs.Draw();
                    buton1vs1.Draw();
                    back.Draw();
                    if(back.eapasat(mouse_position,apasat))
                    {
                        game_state=MENU;
                    }
                    if(butonvs.eapasat(mouse_position,apasat))
                    {
                        game_state2=TIMERGOL2;
                       game_state=TIMER;
                       timer=5.0f;
                        
                    }
                    if(buton1vs1.eapasat(mouse_position,apasat))
                    {
                        game_state2=TIMERGOLPVP;
                        game_state=TIMERpvp;
                        timer=5.0f;
                    }
        }break;
        case victorie:
        {
            ClearBackground(Verde_Deschis);
            DrawText(player1,screen_witdh/2-200,screen_height/2-50,80,WHITE);
            DrawText(TextFormat("WON"),screen_witdh/2-200,screen_height/2+50,80,WHITE);
            timer-=GetFrameTime();
            if(timer<=0.0f)
            {
                game_state=MENU2;
            }
        }break;
        
    
    }

    EndDrawing();
}





CloseWindow();
CloseAudioDevice();
return 0;
}
