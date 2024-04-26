#include "PreCompile.h"
#include "RockText.h"
#include <EngineCore/DefaultSceneComponent.h>	
#include <EngineCore/SpriteRenderer.h>

ARockText::ARockText()
{

}

ARockText::~ARockText()
{

}

void ARockText::BeginPlay()
{
	Super::BeginPlay();

	std::vector<int> AnimationOffFrameIndex = { 0, 2, 4 };
	std::vector<int> AnimationOnFrameIndex = { 1, 3, 5 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	Renderer->CreateAnimation("Off", "RockText.png", AnimationInterIndex, AnimationOffFrameIndex, true);
	Renderer->CreateAnimation("On", "RockText.png", AnimationInterIndex, AnimationOnFrameIndex, true);

	Renderer->ChangeAnimation("Off");
	Renderer->SetOrder(ERenderOrder::Words);

	SetActorType(ETileType::LWord);
	SetNounType(ENounType::RockText);

	SetIsBlock(true);
	SetIsPush(true);
	SetIsController(false);
	SetIsSink(false);
	SetIsDefeat(false);

	SetFirstStateInfo(GetTileInfo());
}

void ARockText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
