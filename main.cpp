#include "structure.hpp"
#include "raylib.h"

int main()
{
    std::fstream file;
    file.open("gameData.bin", std::ios::in | std::ios::out | std::fstream::app);
    if (!file.is_open())
    {
        printf("can't open file\n");
        return 0;
    }

    sajjad::SavedData save_data;
    file.readsome((char *)&save_data, sizeof(sajjad::SavedData));

    int width{400}, height{300};
    InitWindow(width, height, "hello window");
    SetTargetFPS(60);
    int xpos{10};
    int rectYpos{height - 10};
    sajjad::state m_state = sajjad::state::right;

    int count = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        if (isColided(xpos, height / 2, rectYpos, width / 2))
        {
            DrawText("game over", width / 2, height / 2, 12, BLACK);

            if (count > save_data.highScore)
                save_data.highScore = count;
            char *highScore = new char[30];
            sprintf(highScore, "your high score is: %d", save_data.highScore);
            DrawText(highScore, 10, 10, 20, BLACK);

            save_data.number_of_trys++;
            if (IsKeyPressed(KEY_ENTER))
            {
                xpos = 0;
                rectYpos = height - 10;
            }

            count = 0;
        }
        else
        {
            if (IsKeyDown(KEY_RIGHT) && xpos <= width)
                xpos += 5;
            if (IsKeyDown(KEY_LEFT) && xpos >= 0)
                xpos -= 5;

            changeRectYPos(rectYpos <= height && rectYpos >= 0, rectYpos);

            DrawCircle(xpos, height / 2, 12, BLUE);
            DrawRectangle(width / 2, rectYpos, 20, 20, RED);

            if (IsKeyDown(KEY_LEFT) && m_state == sajjad::state::left && width / 2 - xpos > 0)
            {
                m_state = sajjad::state::right;
                count++;
            }

            if (IsKeyDown(KEY_RIGHT) && m_state == sajjad::state::right && width / 2 - xpos < 0)
            {
                m_state = sajjad::state::left;
                count++;
            }
            char *text = new char[100];
            sprintf(text, "%d", count);
            DrawText(text, 10, 10, 12, BLACK);
        }

        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();

    file.write((char *)&save_data, sizeof(sajjad::SavedData));
    return 0;
}






