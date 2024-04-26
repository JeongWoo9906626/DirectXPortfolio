#include "PreCompile.h"
#include "StaticHelper.h"
#include "TileMap.h"

std::map<FINT, std::list<std::shared_ptr<ATile>>> StaticHelper::CurTileMap;
float StaticHelper::TileSize = 36.0f;
ATileMap* StaticHelper::NewTileMap = nullptr;