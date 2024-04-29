#pragma once
#include "ContentsStruct.h"	
#include "Tile.h"


class StaticHelper
{
public:
	static std::map<FINT, std::list<ATile*>> CurTileMap;
	static float TileSize;
	static std::string StageName;
};