#include "PreCompile.h"
#include "StaticHelper.h"
#include "TileMap.h"

std::map<FINT, std::list<ATile*>> StaticHelper::CurTileMap;
float StaticHelper::TileSize = 36.0f;
std::string StaticHelper::StageName = "";