#pragma once
#include <raylib.h>

#ifndef RESOURCES_PATH
    #define RESOURCES_PATH "resources/"
#endif

struct AssetManager{

    Texture2D dirt = {};
    Texture2D textures = {};
    Texture2D frame = {};

    void loadAll();
};
