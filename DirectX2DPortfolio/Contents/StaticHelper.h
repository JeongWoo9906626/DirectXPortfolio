#pragma once
#include "ContentsStruct.h"	
#include "Tile.h"


class StaticHelper
{
public:
	static std::map<FINT, std::list<ATile*>> CurTileMap;
	static std::map<FINT, class ASelectTile*> CurSelectTileMap;
	static float TileSize;
	static std::string StageNumber;
	static std::string StageText;
	static bool IsStageChange;
	static class ASelector* CurSelector;
	static bool IsStageNumberChange;
	static bool IsNumberDestroy;
	static bool IsStageTextChange;
	static bool IsTextDestroy;
};