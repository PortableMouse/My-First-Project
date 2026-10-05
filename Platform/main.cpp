#include <iostream>
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>
#include "../GameLayer/GameMain.h"

void ImGuiBuild();
void ImGuiShutdown();

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1600, 900, "window name");
    SetExitKey(KEY_NULL);
    SetTargetFPS(240);

    if (!initGame()){
        return 0;
    }

    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        if (!updateGame()){
            CloseWindow();
        }
        ImGuiBuild();
        EndDrawing();
    }
    ImGuiShutdown();
    CloseWindow();
    closeGame();
    return 0;
}

void ImGuiBuild(){
    using namespace ImGui;
    bool static Initilized = false;
    if (!Initilized){
        rlImGuiSetup(true);
        ImGuiIO &io = GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        Initilized = true;
    }
    rlImGuiBegin();
    DockSpaceOverViewport(0, nullptr, ImGuiDockNodeFlags_PassthruCentralNode);
    Begin("test");
    Text("hello");
    if (Button("button")){
        std::cout << "Button\n";
    }
    SameLine();
    if (Button("button##2")){
        std::cout << "Different Button\n";
    }
    End();
    Begin("Second Window");
    Text("hello");
    Separator();
    NewLine();
    static float a = 0;
    SliderFloat("slider", &a, 0, 1);
    End();
    rlImGuiEnd();
}

void ImGuiShutdown(){
    rlImGuiShutdown();
}
