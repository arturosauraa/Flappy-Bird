#include "pipe.h"
#include <iostream>
#include "raylib.h"
#include "random"

Pipe::Pipe()
{
    x = 1200;
    width = 70;
    topY = 0;
    botY = 600;
    score = 0;
}

void Pipe::Draw()
{
    //Top Pipes

    for(int i = 0; i <= topPipePos.size(); i++)
    {
        topPipePos[i].x -= 2;
        

        DrawRectangle(topPipePos[i].x,topY, width, topPipePos[i].y, GREEN);
            
        if(topPipePos[i].x == 201 || topPipePos[i].x == 202 )
        {
            score++;
        }    


    }

    //Bottom Pipes

    for(int i = 0; i <= botPipePos.size(); i++)
    {
        botPipePos[i].x -= 2;
        
        DrawRectangle(botPipePos[i].x,botY - botPipePos[i].y , width, botPipePos[i].y, GREEN);
        
    }


}

void Pipe::Update()
{
    DrawText(TextFormat("%i", score), 100 , 100, 40, WHITE);
}

void Pipe::CreatePipes()
{

    float screenHeight = 600;
    float gap = (rand()%50) + 200;

    // Generate random heights for top and bottom pipes
    float minPipeHeight = 50.0; // Minimum height for pipes
    float maxPipeHeight = screenHeight - gap - minPipeHeight; // Adjusting maximum height considering gap

    float topHeight = minPipeHeight + static_cast<float>(rand() % static_cast<int>(maxPipeHeight - minPipeHeight));
    float bottomHeight = screenHeight - gap - topHeight;
    
    topPipePos.push_back(Vector2{x, topHeight});
    if(topPipePos.front().x < 0 )
    {
        topPipePos.pop_front();
    }

    
    //Bottom Pipes
    
    botPipePos.push_back(Vector2{x, bottomHeight});
    if(botPipePos.front().x < 0 )
    {
        botPipePos.pop_front();
    }

}


