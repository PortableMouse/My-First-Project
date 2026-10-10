#include <iostream>
#include <raylib.h>
#include "GameMain.h"
#include "../Platform/asserts.h"
#include "assetManager.h"
#include "GameMap.h"
#include "Helpers.h"
#include <cmath>
#include <imgui.h>
#include <rlImGui.h>

void ImGuiBuild();

struct GameData{
    GameMap gameMap;
    Camera2D camera;
} gameData;

AssetManager assetManager;

bool initGame(){

    assetManager.loadAll();

    gameData.gameMap.create(30, 10);

    for (int y = 0; y < gameData.gameMap.h; y++)
        for (int x = 0; x < gameData.gameMap.w; x++){
            if (y < (int)(gameData.gameMap.h / 2)){
                gameData.gameMap.getBlockUnsafe(x, y).type = Block::dirt;
            }else {
                gameData.gameMap.getBlockUnsafe(x, y).type = Block::air;
            }
        }

    gameData.camera.target = {0, 0};
    gameData.camera.rotation = 0.0f;
    gameData.camera.zoom = 100.0f;
    return true;
}

bool updateGame(){

    float deltaTime = GetFrameTime();
    if (deltaTime > 1.f / 5) {deltaTime = 1 / 5.f;}

    gameData.camera.offset = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};

    ClearBackground({75, 75, 150,255});

    if (IsKeyDown(KEY_LEFT)) gameData.camera.target.x -= 7.f * deltaTime;
    if (IsKeyDown(KEY_RIGHT)) gameData.camera.target.x += 7.f * deltaTime;
    if (IsKeyDown(KEY_UP)) gameData.camera.target.y -= 7.f * deltaTime;
    if (IsKeyDown(KEY_DOWN)) gameData.camera.target.y += 7.f * deltaTime;

    Vector2 worldPos = GetScreenToWorld2D(GetMousePosition(), gameData.camera);
    int blockX = (int)std::floor(worldPos.x);
    int blockY = (int)std::floor(worldPos.y);

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        auto b = gameData.gameMap.getBlockSafe(blockX, blockY);
        if (b){
            *b = {};
        }
    }

    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)){
        auto b = gameData.gameMap.getBlockSafe(blockX, blockY);
        if (b){
            b->type = Block::dirt;
        }
    }

    BeginMode2D(gameData.camera);

    for (int y = 0; y < gameData.gameMap.h; y++)
        for (int x = 0; x < gameData.gameMap.w; x++){

            auto &b = gameData.gameMap.getBlockUnsafe(x, y);

            if (b.type != Block::air){

                DrawTexturePro(
                    assetManager.textures,
                    getTextureAtlas(b.type, 0, 32, 32),
                    {(float)x, (float)y, 1, 1},
                    {0,0},
                    0.0f,
                    WHITE
                );
            }
        }

    DrawTexturePro(
        assetManager.frame,
        {0, 0, (float)assetManager.frame.width, (float)assetManager.frame.height},
        {(float)blockX, (float)blockY, 1, 1},
        {0, 0},
        0.0f,
        WHITE
        );
    EndMode2D();
    ImGuiBuild();
    return true;
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
    ImGui::Begin("Dev Kit");

    ImGui::End();
    rlImGuiEnd();
}

void ImGuiShutdown(){
    rlImGuiShutdown();
}

void closeGame(){
}
