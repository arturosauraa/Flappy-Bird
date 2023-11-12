#include <raylib.h>
#include <iostream>

#include "pipe.h"
#include "bird.h"

using namespace std;



double lastUpdateTime = 0;

bool eventTriggered(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}


int main()
{
    int screen_width = 1200;
    int screen_height = 600;
    InitWindow(screen_width, screen_height, "Flappy Bird");
    SetTargetFPS(60);

    Pipe pipe = Pipe();
    Bird bird = Bird();
    
    while(WindowShouldClose() == false)
    {
        BeginDrawing();

        if(eventTriggered(2))
        {
            if(!bird.gameOver)
            {
            pipe.CreatePipes();
            }
        }
        if(!bird.gameOver)
        {
        pipe.Update();
        bird.Update();
        }

        for(Vector2 pipeTop: pipe.topPipePos)
        {
            Rectangle rec = {(int)pipeTop.x, 0, 70,(int)pipeTop.y};
            if(CheckCollisionCircleRec(Vector2{bird.x,bird.y}, bird.radius, Rectangle(rec)))
            {
                bird.gameOver = true;
            }
        }
        for(Vector2 pipeBot: pipe.botPipePos)
        {
            Rectangle rec = {(int)pipeBot.x, 600 - (int)pipeBot.y, 70,(int)pipeBot.y};
            if(CheckCollisionCircleRec(Vector2{bird.x,bird.y}, bird.radius, Rectangle(rec)))
            {
                bird.gameOver = true;
            }
        }




        ClearBackground(BLACK);
        if(!bird.gameOver)
        {
            pipe.Draw();
        }
        if(bird.gameOver)
        {
            DrawText("Game Over", screen_width / 2 - 200, screen_height / 2 - 50, 80, WHITE);
        }

        bird.Draw();
        

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
} 