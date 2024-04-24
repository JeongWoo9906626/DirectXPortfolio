#include "PreCompile.h"
#include "IsText.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

AIsText::AIsText()
{
	
}

AIsText::~AIsText()
{
	
}

void AIsText::BeginPlay()
{
	Super::BeginPlay();

	std::vector<int> AnimationOffFrameIndex = { 1, 3, 5 };
	std::vector<int> AnimationOnFrameIndex = { 0, 2, 4 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	Renderer->CreateAnimation("Off", "IsText.png", AnimationInterIndex, AnimationOffFrameIndex, true);
	Renderer->CreateAnimation("On", "IsText.png", AnimationInterIndex, AnimationOnFrameIndex, true);

	Renderer->ChangeAnimation("Off");
	Renderer->SetOrder(ERenderOrder::Words);

	SetActorType(ETileType::Is);
	SetNounType(ENounType::None);

	SetIsBlock(true);
	SetIsPush(true);
	SetIsController(false);
	SetIsSink(false);
	SetIsDefeat(false);

	SetFirstStateInfo(GetTileInfo());
}

void AIsText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
