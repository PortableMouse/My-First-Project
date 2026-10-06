#pragma once
#include <raylib.h>

#ifndef RESOURCES_PATH
    #define RESOURCES_PATH "resources/"
#endif

struct AssetManager{

    Texture2D dirt = {};

    void loadAll();
};
