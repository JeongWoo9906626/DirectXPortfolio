#include "PreCompile.h"
#include "SelectTile.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

ASelectTile::ASelectTile()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Root->SetScale(FVector(86.0f, 86.0f, 20.0f));
	SetRoot(Root);

	LeftRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	LeftRenderer->SetupAttachment(Root);
	LeftRenderer->SetOrder(ERenderOrder::Object);
	LeftRenderer->AddPosition(FVector::Left * 0.07f);
	LeftRenderer->SetScale(FVector(0.6f, 1.0f));

	RightRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	RightRenderer->SetupAttachment(Root);
	RightRenderer->SetOrder(ERenderOrder::Object);
	RightRenderer->AddPosition(FVector::Right * 0.07f);
	RightRenderer->SetScale(FVector(0.6f, 1.0f));

	LineRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	LineRenderer->SetupAttachment(Root);
	LineRenderer->SetOrder(ERenderOrder::Object);
	LineRenderer->SetScale(FVector(0.8f, 0.8f));
}

ASelectTile::~ASelectTile()
{

}

void ASelectTile::BeginPlay()
{
	Super::BeginPlay();

	SettingAnimation();
}

void ASelectTile::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}



void ASelectTile::SettingAnimation()
{
	{
		std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };

		std::vector<int> AnimationZeroOnFrame = { 0, 10, 20 };
		std::vector<int> AnimationZeroOffFrame = { 1, 11, 21 };
		LeftRenderer->CreateAnimation(static_cast<std::string>("0") + "On", "Number.png", AnimationInterIndex, AnimationZeroOnFrame);
		LeftRenderer->CreateAnimation(static_cast<std::string>("0") + "Off", "Number.png", AnimationInterIndex, AnimationZeroOffFrame);
		LeftRenderer->SetActive(false);

		int i = 0;
		int Index = -1;
		std::vector<int> AnimationOnFrameIndex;
		std::vector<int> AnimationOffFrameIndex;

		while (i < 10)
		{
			Index += 1;
			std::string Number = std::to_string(i);

			if (i < 5)
			{
				AnimationOnFrameIndex = { Index, Index + 10, Index + 20 };
				Index++;
				AnimationOffFrameIndex = { Index, Index + 10, Index + 20 };
			}
			else
			{
				AnimationOnFrameIndex = { Index + 20, Index + 30, Index + 40 };
				Index++;
				AnimationOffFrameIndex = { Index + 20, Index + 30, Index + 40 };
			}

			RightRenderer->CreateAnimation(Number + "On", "Number.png", AnimationInterIndex, AnimationOnFrameIndex, true);
			RightRenderer->CreateAnimation(Number + "Off", "Number.png", AnimationInterIndex, AnimationOffFrameIndex, true);
			RightRenderer->SetActive(false);
			i++;
		}
	}

	{
		std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };

		std::vector<int> NothingIndex = { 2, 20, 38 };
		std::vector<int> RightIndex = { 3, 21, 39 };
		std::vector<int> TopIndex = { 4, 22, 40 };
		std::vector<int> RightTopIndex = { 5, 23, 41 };
		std::vector<int> LeftIndex = { 6, 24, 42 };
		std::vector<int> LeftRightIndex = { 7, 25, 43 };
		std::vector<int> LeftTopIndex = { 8, 26, 44 };
		std::vector<int> LeftRightTopIndex = { 9, 27, 45 };
		std::vector<int> BottomIndex = { 10, 28, 46 };
		std::vector<int> RightBottomIndex = { 11, 29, 47 };
		std::vector<int> TopBottomIndex = { 12, 30, 48 };
		std::vector<int> RightTopBottomIndex = { 13, 31, 49 };
		std::vector<int> LeftBottomIndex = { 14, 32, 50 };
		std::vector<int> LeftRightBottomIndex = { 15, 33, 51 };
		std::vector<int> LeftTopBottomIndex = { 16, 34, 52 };
		std::vector<int> LeftRightTopBottomIndex = { 17, 35, 53 };

		LineRenderer->CreateAnimation("LineLeftRightTopBottom", "Line.png", AnimationInterIndex, LeftRightTopBottomIndex, true);
		LineRenderer->CreateAnimation("LineLeftTopBottom", "Line.png", AnimationInterIndex, LeftTopBottomIndex, true);
		LineRenderer->CreateAnimation("LineLeftRightBottom", "Line.png", AnimationInterIndex, LeftRightBottomIndex, true);
		LineRenderer->CreateAnimation("LineLeftBottom", "Line.png", AnimationInterIndex, LeftBottomIndex, true);
		LineRenderer->CreateAnimation("LineRightTopBottom", "Line.png", AnimationInterIndex, RightTopBottomIndex, true);
		LineRenderer->CreateAnimation("LineTopBottom", "Line.png", AnimationInterIndex, TopBottomIndex, true);
		LineRenderer->CreateAnimation("LineRightBottom", "Line.png", AnimationInterIndex, RightBottomIndex, true);
		LineRenderer->CreateAnimation("LineBottom", "Line.png", AnimationInterIndex, BottomIndex, true);
		LineRenderer->CreateAnimation("LineLeftRightTop", "Line.png", AnimationInterIndex, LeftRightTopIndex, true);
		LineRenderer->CreateAnimation("LineLeftTop", "Line.png", AnimationInterIndex, LeftTopIndex, true);
		LineRenderer->CreateAnimation("LineLeftRight", "Line.png", AnimationInterIndex, LeftRightIndex, true);
		LineRenderer->CreateAnimation("LineLeft", "Line.png", AnimationInterIndex, LeftIndex, true);
		LineRenderer->CreateAnimation("LineRightTop", "Line.png", AnimationInterIndex, RightTopIndex, true);
		LineRenderer->CreateAnimation("LineTop", "Line.png", AnimationInterIndex, TopIndex, true);
		LineRenderer->CreateAnimation("LineRight", "Line.png", AnimationInterIndex, RightIndex, true);
		LineRenderer->CreateAnimation("LineNothing", "Line.png", AnimationInterIndex, NothingIndex, true);
		LineRenderer->AddPosition(FVector::Up * 0.1f);
		LineRenderer->SetActive(false);
	}


}

void ASelectTile::SetAnimation(int _StageNumber, bool _IsClear, FINT _TilePos)
{
	if (100 == _StageNumber)
	{
		NextLineCheck(_TilePos);
		return;
	}

	std::string StageNumber = std::to_string(_StageNumber);
	std::string IsClear = "";
	if (true == _IsClear)
	{
		IsClear = "Off";
	}
	else
	{
		IsClear = "On";
	}

	LeftRenderer->ChangeAnimation(static_cast<std::string>("0") + IsClear);
	RightRenderer->ChangeAnimation(StageNumber + IsClear);
}

void ASelectTile::ShowOn()
{
	if (ESelectTileType::Walk == this->SelectInfo.Type)
	{
		LineRenderer->SetActive(true);
	}
	else
	{
		LeftRenderer->SetActive(true);
		RightRenderer->SetActive(true);
	}
}

void ASelectTile::NextLineCheck(FINT _TilePos)
{
	FINT MyTilePosition = _TilePos;

	FINT LeftTilePosition = MyTilePosition + FINT::LEFT;
	IsLeft = NextSelectTileTypeCheck(LeftTilePosition);

	FINT RightTilePosition = MyTilePosition + FINT::RIGHT;
	IsRight = NextSelectTileTypeCheck(RightTilePosition);

	FINT TopTilePosition = MyTilePosition + FINT::UP;
	IsTop = NextSelectTileTypeCheck(TopTilePosition);

	FINT BottomTilePosition = MyTilePosition + FINT::DOWN;
	IsBottom = NextSelectTileTypeCheck(BottomTilePosition);

	LineAnimationChange();
}

bool ASelectTile::NextSelectTileTypeCheck(FINT _Position)
{
	if (_Position.X < 0 || _Position.Y < 0 || _Position.X >= FINT::SelectMapSize.X || _Position.Y >= FINT::SelectMapSize.Y)
	{
		return false;
	}

	ASelectTile* Tile = StaticHelper::CurSelectTileMap[_Position];
	if (ESelectTileType::None == Tile->SelectInfo.Type)
	{
		return false;
	}
	else
	{
		return true;
	}

}

void ASelectTile::LineAnimationChange()
{
	std::string AnimationName = "";
	FVector AddVector = FVector::Zero;
	if (true == IsLeft && true == IsRight && true == IsTop && true == IsBottom)
	{
		AnimationName = "LineLeftRightTopBottom";
	}
	else if (true == IsLeft && false == IsRight && false == IsTop && false == IsBottom)
	{
		AnimationName = "LineLeft";
	}
	else if (false == IsLeft && true == IsRight && false == IsTop && false == IsBottom)
	{
		AnimationName = "LineRight";
	}
	else if (false == IsLeft && false == IsRight && true == IsTop && false == IsBottom)
	{
		AnimationName = "LineTop";
	}
	else if (false == IsLeft && false == IsRight && false == IsTop && true == IsBottom)
	{
		AnimationName = "LineBottom";
	}
	else if (true == IsLeft && true == IsRight && false == IsTop && false == IsBottom)
	{
		AnimationName = "LineLeftRight";
	}
	else if (true == IsLeft && false == IsRight && true == IsTop && false == IsBottom)
	{
		AnimationName = "LineLeftTop";
	}
	else if (true == IsLeft && false == IsRight && false == IsTop && true == IsBottom)
	{
		AnimationName = "LineLeftBottom";
	}
	else if (false == IsLeft && true == IsRight && true == IsTop && false == IsBottom)
	{
		AnimationName = "LineRightTop";
	}
	else if (false == IsLeft && true == IsRight && false == IsTop && true == IsBottom)
	{
		AnimationName = "LineRightBottom";
	}
	else if (false == IsLeft && false == IsRight && true == IsTop && true == IsBottom)
	{
		AnimationName = "LineTopBottom";
	}
	else if (true == IsLeft && true == IsRight && true == IsTop && false == IsBottom)
	{
		AnimationName = "LineLeftRightTop";
	}
	else if (true == IsLeft && true == IsRight && false == IsTop && true == IsBottom)
	{
		AnimationName = "LineLeftRightBottom";
	}
	else if (true == IsLeft && false == IsRight && true == IsTop && true == IsBottom)
	{
		AnimationName = "LineLeftTopBottom";
	}
	else if (false == IsLeft && true == IsRight && true == IsTop && true == IsBottom)
	{
		AnimationName = "LineRightTopBottom";
	}
	else if (false == IsLeft && false == IsRight && false == IsTop && false == IsBottom)
	{
		AnimationName = "LineNothing";
	}

	LineRenderer->ChangeAnimation(AnimationName);
}
