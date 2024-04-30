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

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetOrder(ERenderOrder::Object);
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

	int i = 0;
	while (i < 10)
	{
		int Index = i;
		std::string Number = std::to_string(i);

		std::vector<int> AnimationOnFrameIndex = { Index, Index + 10, Index + 20 };
		Index++;
		std::vector<int> AnimationOffFrameIndex = { Index, Index + 10, Index + 20 };

		Renderer->CreateAnimation(Number + "On", "Number.png", AnimationInterIndex, AnimationOnFrameIndex, true);
		Renderer->CreateAnimation(Number + "Off", "Number.png", AnimationInterIndex, AnimationOffFrameIndex, true);

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

	Renderer->ChangeAnimation(StageNumber + IsClear);
}