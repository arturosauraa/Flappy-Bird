#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include <deque>
#include "pipe.h"


class Bird
{
public:
    Bird();
    ~Bird();
    void Draw();
    void Update();
    void Jump();
    float x,y,radius;
    float velocity, gravity;
    bool isJumping;
    bool gameOver;
    Texture2D birdTexture;

private:
Pipe pipe;
};