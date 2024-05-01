#include "PreCompile.h"
#include "StaticHelper.h"
#include "TileMap.h"
#include "SelectTile.h"

std::map<FINT, std::list<ATile*>> StaticHelper::CurTileMap;
std::map<FINT, ASelectTile*> StaticHelper::CurSelectTileMap;
float StaticHelper::TileSize = 36.0f;
std::string StaticHelper::StageName = "";
bool StaticHelper::IsStageChange = false;