#include "PreCompile.h"
#include "Baba.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

ABaba::ABaba()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	SetRoot(Root);
}

ABaba::~ABaba()
{

}

void ABaba::BeginPlay()
{
	Super::BeginPlay();

	SetActorType(ETileType::Baba);
	//HasController = true;
	SetActorScale3D(FVector(200.0f, 200.0f, 20.0f));

	// Move_Right 0 ~ 4
	{
		int AnimationNumber = 0;
		for (int x = 0; x < 4; x++)
		{
			std::vector<int> AnimationFrameIndex;
			std::vector<float> AnimationInterIndex;
			for (int y = 0; y < 3; y++)
			{
				int Index = (y * 17) + x + 1;
				AnimationFrameIndex.push_back(Index);
				AnimationInterIndex.push_back(0.1f);
			}
			Renderer->CreateAnimation("BabaMove_Right" + std::to_string(AnimationNumber), "Baba.png", AnimationInterIndex, AnimationFrameIndex, true);
			AnimationNumber++;
		}
	}

	// Move_Left 0 ~ 4
	{
		int AnimationNumber = 0;
		for (int x = 0; x < 4; x++)
		{
			std::vector<int> AnimationFrameIndex;
			std::vector<float> AnimationInterIndex;
			for (int y = 0; y < 3; y++)
			{
				int Index = (y * 17) + x + 9;
				AnimationFrameIndex.push_back(Index);
				AnimationInterIndex.push_back(0.1f);
			}
			Renderer->CreateAnimation("BabaMove_Left" + std::to_string(AnimationNumber), "Baba.png", AnimationInterIndex, AnimationFrameIndex, true);
			AnimationNumber++;
		}
	}

	// Move_Up 0 ~ 4
	{
		int AnimationNumber = 0;
		for (int x = 0; x < 4; x++)
		{
			std::vector<int> AnimationFrameIndex;
			std::vector<float> AnimationInterIndex;
			for (int y = 0; y < 3; y++)
			{
				int Index = (y * 17) + x + 5;
				AnimationFrameIndex.push_back(Index);
				AnimationInterIndex.push_back(0.1f);
			}
			Renderer->CreateAnimation("BabaMove_Up" + std::to_string(AnimationNumber), "Baba.png", AnimationInterIndex, AnimationFrameIndex, true);
			AnimationNumber++;
		}
	}

	// Move_Down 0 ~ 4
	{
		int AnimationNumber = 0;
		for (int x = 0; x < 4; x++)
		{
			std::vector<int> AnimationFrameIndex;
			std::vector<float> AnimationInterIndex;
			for (int y = 0; y < 3; y++)
			{
				int Index = (y * 17) + x + 13;
				AnimationFrameIndex.push_back(Index);
				AnimationInterIndex.push_back(0.1f);
			}
			Renderer->CreateAnimation("BabaMove_Down" + std::to_string(AnimationNumber), "Baba.png", AnimationInterIndex, AnimationFrameIndex, true);
			AnimationNumber++;
		}
	}

	Renderer->ChangeAnimation("BabaMove_Down0");
	Renderer->SetOrder(ERenderOrder::Player);
}

void ABaba::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ABaba::MoveSet(EInputType _Input) {
	Super::MoveSet(_Input);

	EActorDir Dir = EActorDir::None;
	switch (_Input)
	{
	case EInputType::L:
		Dir = EActorDir::Left;
		break;
	case EInputType::R:
		Dir = EActorDir::Right;
		break;
	case EInputType::U:
		Dir = EActorDir::Up;
		break;
	case EInputType::D:
		Dir = EActorDir::Down;
		break;
	}
	NextDir = Dir;

	ChangeMoveAnimation();
}

void ABaba::BackMoveSet()
{
	Super::BackMoveSet();

	EActorDir Dir = GetPrevDir();
	NextDir = Dir;

	AnimationIndexHistory.pop();
	if (true == AnimationIndexHistory.empty())
	{
		Renderer->ChangeAnimation("BabaMove_Down0");
		return;
	}
	BackChangeMoveAnimation();
}

void ABaba::ChangeMoveAnimation()
{
	if (false == GetIsController())
	{
		int InsertIndexNumber = AnimationIndexHistory.top();
		AnimationIndexHistory.push(InsertIndexNumber);
	}
	else
	{
		if (true == AnimationIndexHistory.empty())
		{
			AnimationIndexHistory.push(1);
		}
		else
		{
			if (AnimationIndexHistory.top() >= 3)
			{
				AnimationIndexHistory.push(0);
			}
			else
			{
				int InsertIndexNumber = AnimationIndexHistory.top() + 1;
				AnimationIndexHistory.push(InsertIndexNumber);
			}
		}
	}

	AnimationIndex = AnimationIndexHistory.top();

	if (true == GetIsController())
	{
		switch (NextDir)
		{
		case EActorDir::Left:
			Renderer->ChangeAnimation("BabaMove_Left" + std::to_string(AnimationIndex));
			break;
		case EActorDir::Right:
			Renderer->ChangeAnimation("BabaMove_Right" + std::to_string(AnimationIndex));
			break;
		case EActorDir::Up:
			Renderer->ChangeAnimation("BabaMove_Up" + std::to_string(AnimationIndex));
			break;
		case EActorDir::Down:
			Renderer->ChangeAnimation("BabaMove_Down" + std::to_string(AnimationIndex));
			break;
		}
	}
	

	PrevDir = NextDir;
	NextDir = EActorDir::None;
}

void ABaba::BackChangeMoveAnimation()
{
	int HistoryIndex = AnimationIndexHistory.top();
	if (true == GetIsController())
	{
		switch (NextDir)
		{
		case EActorDir::Left:
			Renderer->ChangeAnimation("BabaMove_Left" + std::to_string(HistoryIndex));
			break;
		case EActorDir::Right:
			Renderer->ChangeAnimation("BabaMove_Right" + std::to_string(HistoryIndex));
			break;
		case EActorDir::Up:
			Renderer->ChangeAnimation("BabaMove_Up" + std::to_string(HistoryIndex));
			break;
		case EActorDir::Down:
			Renderer->ChangeAnimation("BabaMove_Down" + std::to_string(HistoryIndex));
			break;
		}
	}
}
