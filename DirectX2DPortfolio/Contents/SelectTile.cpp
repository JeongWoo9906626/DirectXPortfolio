#include "PreCompile.h"
#include "SelectTile.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

ASelectTile::ASelectTile()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Root->SetScale(FVector(54.0f, 54.0f, 20.0f));
	SetRoot(Root);

	LeftRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	LeftRenderer->SetupAttachment(Root);
	LeftRenderer->SetOrder(ERenderOrder::Object);
	LeftRenderer->AddPosition(FVector::Left * 0.07f);
	LeftRenderer->SetScale(FVector(0.5f, 1.0f));


	RightRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	RightRenderer->SetupAttachment(Root);
	RightRenderer->SetOrder(ERenderOrder::Object);
	RightRenderer->AddPosition(FVector::Right * 0.07f);
	RightRenderer->SetScale(FVector(0.5f, 1.0f));
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

void ASelectTile::SetAnimation(int _StageNumber, bool _IsClear)
{
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
	LeftRenderer->SetActive(true);
	RightRenderer->SetActive(true);
}