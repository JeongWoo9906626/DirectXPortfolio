#include "PreCompile.h"
#include "SinkText.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>

ASinkText::ASinkText()
{

}

ASinkText::~ASinkText()
{

}

void ASinkText::BeginPlay()
{
	Super::BeginPlay();

	std::vector<int> AnimationOffFrameIndex = { 1, 4, 7 };
	std::vector<int> AnimationOnFrameIndex = { 2, 5, 8 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };

	Renderer->CreateAnimation("Off", "SinkText.png", AnimationInterIndex, AnimationOffFrameIndex, true);
	Renderer->CreateAnimation("On", "SinkText.png", AnimationInterIndex, AnimationOnFrameIndex, true);

	Renderer->ChangeAnimation("Off");
	Renderer->SetOrder(ERenderOrder::Words);

	SetActorType(ETileType::RWord);
	SetNounType(ENounType::SinkText);

	SetIsBlock(true);
	SetIsPush(true);
	SetIsController(false);
	SetIsSink(false);
	SetIsDefeat(false);

	SetFirstStateInfo(GetTileInfo());
}

void ASinkText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
