#include "GameMap.h"
#include "../Platform/asserts.h"

void GameMap::create(int w, int h){
    *this = {};
    mapData.resize(w*h);

    this->w = w;
    this->h = h;

    for (auto &e : mapData) { e = {};}
}

Block &GameMap::getBlockUnsafe(int x, int y){
    permaAssertCommentDevelopement(mapData.size() == w * h, "Map data not initilized");
    permaAssertCommentDevelopement(x >= 0 && y >= 0 && x < w && y < h, "getBlockUnsafe out of bounds error");

    return mapData[x + y * w];
}

Block *GameMap::getBlockSafe(int x, int y){
    permaAssertCommentDevelopement(mapData.size() == w * h, "Map data not initilized");

    if (x < 0 || y < 0 || x >= w || y >= h){ return nullptr;}

    return &mapData[x + y * w];
}
