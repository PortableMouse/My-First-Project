#include <raylib.h>
#include "../GameLayer/GameMain.h"

void ImGuiShutdown();

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1600, 900, "window name");
    SetExitKey(KEY_NULL);
    SetTargetFPS(240);

    if (!initGame()){
        CloseWindow();
        return 0;
    }

    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        bool RunGame = updateGame();

        EndDrawing();
        if (!RunGame) break;
    }
    ImGuiShutdown();
    closeGame();
    CloseWindow();
    return 0;
}
