#include "bird.h"
#

Bird::Bird()
{
    x = 200;
    y = 300;
    radius = 15;
    velocity = 0;
    gravity = 0.1f;
    isJumping = false;
    gameOver = false;
}

void Bird::Draw()
{

    DrawCircle(x, y, radius, WHITE);
}

void Bird::Update()
{   

    if (IsKeyPressed(KEY_SPACE)) 
    {
        Jump();

    }


    if(!(y + radius  + 2>= GetScreenHeight() || y <= 0))
    {
        velocity += 0.1f;
        y += gravity + velocity;
    }
    if((y + radius  + 2>= GetScreenHeight()))
    {
        gameOver = true;
    }
    if( y <= 0)
    {
        y +=  5;
    }


}

void Bird::Jump()
{
    velocity = -5.0f;
}
