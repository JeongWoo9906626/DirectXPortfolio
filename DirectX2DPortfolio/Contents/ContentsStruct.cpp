#include "PreCompile.h"
#include "ContentsStruct.h"
#include "StaticHelper.h"


FINT FINT::MapSize = FINT();

const FINT FINT::LEFT = FINT(-1, 0);
const FINT FINT::RIGHT = FINT(1, 0);
const FINT FINT::UP = FINT(0, 1);
const FINT FINT::DOWN = FINT(0, -1);

FVector FINT::GetFINTToVector()
{
	FINT::MapSize.X / 2;
	FINT::MapSize.Y / 2;

	FINT TilePos = *this;
	FVector Result = FVector::Zero;
	Result.X = StaticHelper::TileSize * ((FINT::MapSize.X / -2.0f) + (TilePos.X));
	Result.Y = StaticHelper::TileSize * ((FINT::MapSize.Y / -2.0f) + (TilePos.Y));
	return Result;
}
