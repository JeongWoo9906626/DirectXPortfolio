#include "PreCompile.h"
#include "NoAnimTile.h"
#include "StaticHelper.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

NoAnimTile::NoAnimTile()
{

}

NoAnimTile::~NoAnimTile()
{

}

void NoAnimTile::BeginPlay()
{
	Super::BeginPlay();
}

void NoAnimTile::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	NextCheck();
	TileAnimationChange();
}

void NoAnimTile::NextCheck()
{
	FINT MyTilePosition = this->GetTilePosition();

	FINT LeftTilePosition = MyTilePosition + FINT::LEFT;
	IsLeft = NextTileTypeCheck(LeftTilePosition);

	FINT RightTilePosition = MyTilePosition + FINT::RIGHT;
	IsRight = NextTileTypeCheck(RightTilePosition);

	FINT TopTilePosition = MyTilePosition + FINT::UP;
	IsTop = NextTileTypeCheck(TopTilePosition);

	FINT BottomTilePosition = MyTilePosition + FINT::DOWN;
	IsBottom = NextTileTypeCheck(BottomTilePosition);
}

bool NoAnimTile::NextTileTypeCheck(FINT _Position)
{
	std::list<std::shared_ptr<ATile>> TileList = StaticHelper::CurTileMap[_Position];
	for (std::shared_ptr<ATile> Tile : TileList)
	{
		if (this->GetTileType() == Tile->GetTileType())
		{
			return true;
		}
	}
	return false;
}

void NoAnimTile::TileAnimationChange()
{
	if (true == IsLeft && true == IsRight && true == IsTop && true == IsBottom)
	{
		NextNo = ENoNext::Nothing;
	}
	else if (true == IsLeft && false == IsRight && false == IsTop && false == IsBottom)
	{
		NextNo = ENoNext::Left;
	}
	else if (false == IsLeft && true == IsRight && false == IsTop && false == IsBottom)
	{
		NextNo = ENoNext::Right;
	}
	else if (false == IsLeft && false == IsRight && true == IsTop && false == IsBottom)
	{
		NextNo = ENoNext::Top;
	}
	else if (false == IsLeft && false == IsRight && false == IsTop && true == IsBottom)
	{
		NextNo = ENoNext::Bottom;
	}
	else if (true == IsLeft && true == IsRight && false == IsTop && false == IsBottom)
	{
		NextNo = ENoNext::LeftRight;
	}
	else if (true == IsLeft && false == IsRight && true == IsTop && false == IsBottom)
	{
		NextNo = ENoNext::LeftTop;
	}
	else if (true == IsLeft && false == IsRight && false == IsTop && true == IsBottom)
	{
		NextNo = ENoNext::LeftBottom;
	}
	else if (false == IsLeft && true == IsRight && true == IsTop && false == IsBottom)
	{
		NextNo = ENoNext::RightTop;
	}
	else if (false == IsLeft && true == IsRight && false == IsTop && true == IsBottom)
	{
		NextNo = ENoNext::RightBottom;
	}
	else if (false == IsLeft && false == IsRight && true == IsTop && true == IsBottom)
	{
		NextNo = ENoNext::TopBottom;
	}
	else if (true == IsLeft && true == IsRight && true == IsTop && false == IsBottom)
	{
		NextNo = ENoNext::LeftRightTop;
	}
	else if(true == IsLeft && true == IsRight && false == IsTop && true == IsBottom)
	{
		NextNo = ENoNext::LeftRightBottom;
	}
	else if (true == IsLeft && false == IsRight && true == IsTop && true == IsBottom)
	{
		NextNo = ENoNext::LeftTopBottom;
	}
	else if (false == IsLeft && true == IsRight && true == IsTop && true == IsBottom)
	{
		NextNo = ENoNext::RightTopBottom;
	}
	else if (false == IsLeft && false == IsRight && false == IsTop && false == IsBottom)
	{
		NextNo = ENoNext::LeftRightTopBottom;
	}

	if (PrevNo != NextNo)
	{
		std::string AnimationName = "";
		switch (NextNo)
		{
		case ENoNext::Nothing:
			AnimationName = "Nothing";
			break;
		case ENoNext::Left:
			AnimationName = "Left";
			break;
		case ENoNext::Right:
			AnimationName = "Right";
			break;
		case ENoNext::Top:
			AnimationName = "Top";
			break;
		case ENoNext::Bottom:
			AnimationName = "Bottom";
			break;
		case ENoNext::LeftRight:
			AnimationName = "LeftRight";
			break;
		case ENoNext::LeftTop:
			AnimationName = "LeftTop";
			break;
		case ENoNext::LeftBottom:
			AnimationName = "LeftBottom";
			break;
		case ENoNext::RightTop:
			AnimationName = "RightTop";
			break;
		case ENoNext::RightBottom:
			AnimationName = "RightBottom";
			break;
		case ENoNext::TopBottom:
			AnimationName = "TopBottom";
			break;
		case ENoNext::LeftRightTop:
			AnimationName = "LeftRightTop";
			break;
		case ENoNext::LeftRightBottom:
			AnimationName = "LeftRightBottom";
			break;
		case ENoNext::LeftTopBottom:
			AnimationName = "LeftTopBottom";
			break;
		case ENoNext::RightTopBottom:
			AnimationName = "RightTopBottom";
			break;
		case ENoNext::LeftRightTopBottom:
			AnimationName = "LeftRightTopBottom";
			break;
		}

		Renderer->ChangeAnimation(AnimationName);
		PrevNo = NextNo;
		NextNo = ENoNext::None;
	}
}
