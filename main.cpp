#include <iostream>
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>

using namespace std;

void ImGuiBuild();
void ImGuiShutdown();

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1600, 900, "window name");

    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Testing", 190, 200, 20, RED);
        ImGuiBuild();
        EndDrawing();
    }
    ImGuiShutdown();
    CloseWindow();
    return 0;
}

void ImGuiBuild(){
    bool static Initilized = false;
    if (!Initilized){
        rlImGuiSetup(true);
        Initilized = true;
    }
    rlImGuiBegin();
    ImGui::ShowDemoWindow();
    rlImGuiEnd();
}

void ImGuiShutdown(){
    rlImGuiShutdown();
}
