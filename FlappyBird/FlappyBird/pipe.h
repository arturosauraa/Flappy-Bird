#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include <deque>


class Pipe
{
public:
    Pipe();
    void Draw();
    void Update();
    void CreatePipes();
    float x, topY, botY, width;
    float topHeight, botHeight;
    int score;

    std::deque<Vector2> topPipePos;
    std::deque<Vector2> botPipePos;

private:

};