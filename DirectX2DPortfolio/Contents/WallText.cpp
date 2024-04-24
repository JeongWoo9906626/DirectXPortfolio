#include "PreCompile.h"
#include "WallText.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

AWallText::AWallText()
{
	
}

AWallText::~AWallText()
{
	
}

void AWallText::BeginPlay()
{
	Super::BeginPlay();

	std::vector<int> AnimationOffFrameIndex = { 0, 18, 36 };
	std::vector<int> AnimationOnFrameIndex = { 1, 19, 37 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	Renderer->CreateAnimation("Off", "Wall.png", AnimationInterIndex, AnimationOffFrameIndex, true);
	Renderer->CreateAnimation("On", "Wall.png", AnimationInterIndex, AnimationOnFrameIndex, true);

	Renderer->ChangeAnimation("Off");
	Renderer->SetOrder(ERenderOrder::Words);

	SetActorType(ETileType::LWord);
	SetNounType(ENounType::PillarText);

	SetIsBlock(true);
	SetIsPush(true);
	SetIsController(false);
	SetIsSink(false);
	SetIsDefeat(false);

	SetFirstStateInfo(GetTileInfo());
}

void AWallText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
