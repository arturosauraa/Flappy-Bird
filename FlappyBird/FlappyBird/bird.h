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
    void Draw();
    void Update();
    void Jump();
    float x,y,radius;
    float velocity, gravity;
    bool isJumping;
    bool gameOver;

private:
Pipe pipe;
};