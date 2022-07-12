#include "structure.h"
#include <math.h>

void changeRectYPos(bool result, int &rectYpos, int pace)
{
    static bool direction = false;
    if (!result)
        direction = !direction;

    if (direction)
        rectYpos += pace;
    else
        rectYpos -= pace;
}

bool contain(sajjad::Vector2<int> &&period, int number)
{
    if (period.x <= number && number <= period.y)
        return true;

    return false;
}
bool isColided(int xpos, int ypos, int rectYpos, int rectXpos)
{
    if (contain({rectYpos - 20, rectYpos}, ypos) && contain({rectXpos - 10, rectXpos + 20 + 10}, xpos))
        return true;
    return false;
}

int sigmoid(int x)
{
    double d = 1/(1 + std::exp(-0.05 * (x - 50))) * 20 + 1;
    return int(d);
}