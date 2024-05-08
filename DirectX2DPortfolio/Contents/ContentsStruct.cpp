#include "PreCompile.h"
#include "ContentsStruct.h"
#include "StaticHelper.h"


FINT FINT::MapSize = FINT();
FINT FINT::SelectMapSize = FINT();

const FINT FINT::LEFT = FINT(-1, 0);
const FINT FINT::RIGHT = FINT(1, 0);
const FINT FINT::UP = FINT(0, 1);
const FINT FINT::DOWN = FINT(0, -1);

FVector FINT::GetFINTToVector()
{
	FINT TilePos = *this;
	FVector Result = FVector::Zero;
	Result.X = StaticHelper::TileSize * ((FINT::MapSize.X / -2.0f) + (TilePos.X)) + StaticHelper::TileSize / 2;
	Result.Y = StaticHelper::TileSize * ((FINT::MapSize.Y / -2.0f) + (TilePos.Y)) + StaticHelper::TileSize / 2;
	return Result;
}

FVector FINT::GetSelectFINTToVector()
{
	FINT TilePos = *this;
	FVector Result = FVector::Zero;
	Result.X = StaticHelper::TileSize * ((FINT::SelectMapSize.X / -2.0f) + (TilePos.X)) + StaticHelper::TileSize / 4 * 3;
	Result.Y = StaticHelper::TileSize * ((FINT::SelectMapSize.Y / -2.0f) + (TilePos.Y)) + StaticHelper::TileSize / 4;
	return Result;
}