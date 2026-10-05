#include <iostream>
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>

using namespace std;

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 450, "window name");
    rlImGuiSetup(true);
    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        rlImGuiBegin();
        ImGui::ShowDemoWindow();
        DrawText("Testing", 190, 200, 20, RED);
        rlImGuiEnd();
        EndDrawing();
    }
    rlImGuiShutdown();
    CloseWindow();
    return 0;
}
