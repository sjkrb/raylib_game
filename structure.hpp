#include "raylib.h"
#include <stdio.h>
#include <fstream>
#include <iostream>

namespace sajjad
{
    template <typename T>
    struct Vector2
    {
        T x;
        T y;
    };

    struct __attribute__((aligned(1), packed)) SavedData
    {
        int highScore;
        int number_of_trys;
    };

    enum state
    {
        right,
        left
    };
};

bool contain(sajjad::Vector2<int> &&period, int number);
void changeRectYPos(bool result, int &rectYpos);
bool isColided(int xpos, int ypos, int rectYpos, int rectXpos);