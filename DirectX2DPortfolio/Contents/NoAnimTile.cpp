#include "PreCompile.h"
#include "NoAnimTile.h"
#include "StaticHelper.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

ANoAnimTile::ANoAnimTile()
{

}

ANoAnimTile::~ANoAnimTile()
{

}

void ANoAnimTile::BeginPlay()
{
	Super::BeginPlay();
}

void ANoAnimTile::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	NextCheck();
	TileAnimationChange();
}

void ANoAnimTile::NextCheck()
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

bool ANoAnimTile::NextTileTypeCheck(FINT _Position)
{
	std::list<ATile*> TileList = StaticHelper::CurTileMap[_Position];
	for (ATile* Tile : TileList)
	{
		if (this->GetTileType() == Tile->GetTileType())
		{
			if (false == Tile->IsRender)
			{
				return false;
			}
			return true;
		}
	}
	return false;
}

void ANoAnimTile::TileAnimationChange()
{
	if (true == IsLeft && true == IsRight && true == IsTop && true == IsBottom)
	{
		NextLink = ELinkNext::LeftRightTopBottom;
	}
	else if (true == IsLeft && false == IsRight && false == IsTop && false == IsBottom)
	{
		NextLink = ELinkNext::Left;
	}
	else if (false == IsLeft && true == IsRight && false == IsTop && false == IsBottom)
	{
		NextLink = ELinkNext::Right;
	}
	else if (false == IsLeft && false == IsRight && true == IsTop && false == IsBottom)
	{
		NextLink = ELinkNext::Top;
	}
	else if (false == IsLeft && false == IsRight && false == IsTop && true == IsBottom)
	{
		NextLink = ELinkNext::Bottom;
	}
	else if (true == IsLeft && true == IsRight && false == IsTop && false == IsBottom)
	{
		NextLink = ELinkNext::LeftRight;
	}
	else if (true == IsLeft && false == IsRight && true == IsTop && false == IsBottom)
	{
		NextLink = ELinkNext::LeftTop;
	}
	else if (true == IsLeft && false == IsRight && false == IsTop && true == IsBottom)
	{
		NextLink = ELinkNext::LeftBottom;
	}
	else if (false == IsLeft && true == IsRight && true == IsTop && false == IsBottom)
	{
		NextLink = ELinkNext::RightTop;
	}
	else if (false == IsLeft && true == IsRight && false == IsTop && true == IsBottom)
	{
		NextLink = ELinkNext::RightBottom;
	}
	else if (false == IsLeft && false == IsRight && true == IsTop && true == IsBottom)
	{
		NextLink = ELinkNext::TopBottom;
	}
	else if (true == IsLeft && true == IsRight && true == IsTop && false == IsBottom)
	{
		NextLink = ELinkNext::LeftRightTop;
	}
	else if(true == IsLeft && true == IsRight && false == IsTop && true == IsBottom)
	{
		NextLink = ELinkNext::LeftRightBottom;
	}
	else if (true == IsLeft && false == IsRight && true == IsTop && true == IsBottom)
	{
		NextLink = ELinkNext::LeftTopBottom;
	}
	else if (false == IsLeft && true == IsRight && true == IsTop && true == IsBottom)
	{
		NextLink = ELinkNext::RightTopBottom;
	}
	else if (false == IsLeft && false == IsRight && false == IsTop && false == IsBottom)
	{
		NextLink = ELinkNext::Nothing;
	}

	if (PrevLink != NextLink)
	{
		std::string AnimationName = "";
		switch (NextLink)
		{
		case ELinkNext::Nothing:
			AnimationName = "Nothing";
			break;
		case ELinkNext::Left:
			AnimationName = "Left";
			break;
		case ELinkNext::Right:
			AnimationName = "Right";
			break;
		case ELinkNext::Top:
			AnimationName = "Top";
			break;
		case ELinkNext::Bottom:
			AnimationName = "Bottom";
			break;
		case ELinkNext::LeftRight:
			AnimationName = "LeftRight";
			break;
		case ELinkNext::LeftTop:
			AnimationName = "LeftTop";
			break;
		case ELinkNext::LeftBottom:
			AnimationName = "LeftBottom";
			break;
		case ELinkNext::RightTop:
			AnimationName = "RightTop";
			break;
		case ELinkNext::RightBottom:
			AnimationName = "RightBottom";
			break;
		case ELinkNext::TopBottom:
			AnimationName = "TopBottom";
			break;
		case ELinkNext::LeftRightTop:
			AnimationName = "LeftRightTop";
			break;
		case ELinkNext::LeftRightBottom:
			AnimationName = "LeftRightBottom";
			break;
		case ELinkNext::LeftTopBottom:
			AnimationName = "LeftTopBottom";
			break;
		case ELinkNext::RightTopBottom:
			AnimationName = "RightTopBottom";
			break;
		case ELinkNext::LeftRightTopBottom:
			AnimationName = "LeftRightTopBottom";
			break;
		}

		Renderer->ChangeAnimation(AnimationName);
		PrevLink = NextLink;
		NextLink = ELinkNext::None;
	}
}
