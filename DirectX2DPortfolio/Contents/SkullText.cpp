#include "PreCompile.h"
#include "SkullText.h"
#include <EngineCore/DefaultSceneComponent.h>	
#include <EngineCore/SpriteRenderer.h>

ASkullText::ASkullText()
{

}

ASkullText::~ASkullText()
{

}

void ASkullText::BeginPlay()
{
	Super::BeginPlay();

	std::vector<int> AnimationOffFrameIndex = { 0, 2, 4 };
	std::vector<int> AnimationOnFrameIndex = { 1, 3, 5 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	Renderer->CreateAnimation("Off", "SkullText.png", AnimationInterIndex, AnimationOffFrameIndex, true);
	Renderer->CreateAnimation("On", "SkullText.png", AnimationInterIndex, AnimationOnFrameIndex, true);

	Renderer->ChangeAnimation("Off");
	Renderer->SetOrder(ERenderOrder::Words);

	SetActorType(ETileType::LWord);
	SetNounType(ENounType::SkullText);

	SetIsBlock(true);
	SetIsPush(true);
	SetIsController(false);
	SetIsSink(false);
	SetIsDefeat(false);

	SetFirstStateInfo(GetTileInfo());
}

void ASkullText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
