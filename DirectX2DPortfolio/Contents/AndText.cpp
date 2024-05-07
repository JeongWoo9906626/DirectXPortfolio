#include "PreCompile.h"
#include "AndText.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>

AAndText::AAndText()
{

}

AAndText::~AAndText()
{

}

void AAndText::BeginPlay()
{
	Super::BeginPlay();

	std::vector<int> AnimationOnFrameIndex = { 0, 2, 4 };
	std::vector<int> AnimationOffFrameIndex = { 1, 3, 5 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	Renderer->CreateAnimation("Off", "AndText.png", AnimationInterIndex, AnimationOffFrameIndex, true);
	Renderer->CreateAnimation("On", "AndText.png", AnimationInterIndex, AnimationOnFrameIndex, true);

	Renderer->ChangeAnimation("Off");
	Renderer->SetOrder(ERenderOrder::Words);

	SetActorType(ETileType::And);
	SetNounType(ENounType::None);

	SetIsBlock(true);
	SetIsPush(true);
	SetIsController(false);
	SetIsSink(false);
	SetIsDefeat(false);

	SetFirstStateInfo(GetTileInfo());
}

void AAndText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
