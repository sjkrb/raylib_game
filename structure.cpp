#include "structure.hpp"
void changeRectYPos(bool result, int &rectYpos)
{
    static bool direction = false;
    if (!result)
        direction = !direction;

    if (direction)
        rectYpos += 10;
    else
        rectYpos -= 10;
}

bool isColided(int xpos, int ypos, int rectYpos, int rectXpos)
{
    if (contain({rectYpos - 10, rectYpos + 10}, ypos) && contain({rectXpos - 10, rectXpos + 10}, xpos))
        return true;
    return false;
}

bool contain(sajjad::Vector2<int> &&period, int number)
{
    if (period.x <= number && number <= period.y)
        return true;

    return false;
}