#include <iostream>
#include <raylib.h>

using namespace std;

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 450, "window name");
    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Testing", 190, 200, 20, RED);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
