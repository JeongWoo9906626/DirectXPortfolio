#include "PreCompile.h"
#include "Selector.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"
#include "SelectTile.h"

ASelector::ASelector()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	SetRoot(Root);

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
}

ASelector::~ASelector()
{

}

void ASelector::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("SelectMove", "Selector.png", 0.1f, true);
	Renderer->ChangeAnimation("SelectMove");
	Renderer->SetOrder(ERenderOrder::Player);

	FVector StartPos = FINT(0, 0).GetSelectFINTToVector();
	SetActorLocation(StartPos);

	StaticHelper::CurSelector = this;
}

void ASelector::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == StaticHelper::IsStageChange)
	{
		StaticHelper::CurSelector = this;
		return;
	}

	if (false == IsInput)
	{
		InputCheck();
	}
	else
	{
		if (true == IsMove)
		{
			if (CurMoveTime <= 0.0f)
			{
				IsMove = false;
				IsInput = false;
				CurMoveTime = 0.0f;
				TilePosition = NextPos;
				StaticHelper::CurSelector = this;
				return;
			}

			CurMoveTime -= _DeltaTime;

			FVector MoveVector = Lerp(CurMoveTime);
			SetActorLocation(MoveVector);
		}
		else
		{
			IsInput = false;
		}
	}
}

void ASelector::InputCheck()
{
	if (true == UEngineInput::IsDown(VK_LEFT))
	{
		Input = EInputType::L;
		IsInput = true;
		MoveCheck();

	}
	if (true == UEngineInput::IsDown(VK_RIGHT))
	{
		Input = EInputType::R;
		IsInput = true;
		MoveCheck();

	}
	if (true == UEngineInput::IsDown(VK_UP))
	{
		Input = EInputType::U;
		IsInput = true;
		MoveCheck();

	}
	if (true == UEngineInput::IsDown(VK_DOWN))
	{
		Input = EInputType::D;
		IsInput = true;
		MoveCheck();

	}
	if (true == UEngineInput::IsDown(VK_SPACE))
	{
		if (ESelectTileType::Stage == StaticHelper::CurSelectTileMap[TilePosition]->SelectInfo.Type)
		{
			StaticHelper::IsStageChange = true;
			
		}
		IsInput = false;
		return;
	}
}

void ASelector::MoveCheck()
{
	StaticHelper::CurSelectTileMap;

	PrevPos = TilePosition;
	FINT NextPosCheck = FINT();
	switch (Input)
	{
	case EInputType::L:
		NextPosCheck = PrevPos + FINT(-1, 0);
		break;
	case EInputType::R:
		NextPosCheck = PrevPos + FINT(1, 0);
		break;
	case EInputType::U:
		NextPosCheck = PrevPos + FINT(0, 1);
		break;
	case EInputType::D:
		NextPosCheck = PrevPos + FINT(0, -1);
		break;
	}

	if (NextPosCheck.X < 0 || NextPosCheck.X >= FINT::SelectMapSize.X || NextPosCheck.Y < 0 || NextPosCheck.Y >= FINT::SelectMapSize.Y)
	{
		return;
	}


	ASelectTile* NextCheck = StaticHelper::CurSelectTileMap[NextPosCheck];
	if (true == NextCheck->SelectInfo.IsEnter)
	{
		IsMove = true;
		CurMoveTime = MoveTime;
	}
}

FVector ASelector::Lerp(float _CurMoveTime)
{
	PrevPos = TilePosition;
	
	switch (Input)
	{
	case EInputType::L:
		NextPos = PrevPos + FINT(-1, 0);
		break;
	case EInputType::R:
		NextPos = PrevPos + FINT(1, 0);
		break;
	case EInputType::U:
		NextPos = PrevPos + FINT(0, 1);
		break;
	case EInputType::D:
		NextPos = PrevPos + FINT(0, -1);
		break;
	}

	FVector PrevVector = PrevPos.GetSelectFINTToVector();
	FVector NextVector = NextPos.GetSelectFINTToVector();
	float t = (MoveTime - _CurMoveTime) / MoveTime;

	FVector CurPos;
	CurPos.X = PrevVector.X * (1 - t) + NextVector.X * t;
	CurPos.Y = PrevVector.Y * (1 - t) + NextVector.Y * t + 7.0f;

	CurPos.X = static_cast<int>(std::lround(CurPos.X));
	CurPos.Y = static_cast<int>(std::lround(CurPos.Y));

	return CurPos;
}