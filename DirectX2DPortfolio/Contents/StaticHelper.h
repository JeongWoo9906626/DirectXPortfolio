#pragma once
#include "ContentsStruct.h"	
#include "Tile.h"


class StaticHelper
{
public:
	static std::map<FINT, std::list<std::shared_ptr<ATile>>> CurTileMap;
	static float TileSize;
	static class ATileMap* NewTileMap;
};