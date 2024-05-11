#include "PreCompile.h"
#include "StaticHelper.h"
#include "TileMap.h"
#include "SelectTile.h"
#include "Selector.h"

std::map<FINT, std::list<ATile*>> StaticHelper::CurTileMap;
std::map<FINT, ASelectTile*> StaticHelper::CurSelectTileMap;
float StaticHelper::TileSize = 36.0f;
std::string StaticHelper::StageNumber = "";
std::string StaticHelper::StageText = "";
bool StaticHelper::IsStageChange = false;
ASelector* StaticHelper::CurSelector;
bool StaticHelper::IsStageNumberChange = false;
bool StaticHelper::IsNumberDestroy = false;