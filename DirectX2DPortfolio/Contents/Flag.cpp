#include "PreCompile.h"
#include "Flag.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>

AFlag::AFlag()
{

}

AFlag::~AFlag()
{

}

void AFlag::BeginPlay()
{
	Super::BeginPlay();

	std::vector<int> AnimationOffFrameIndex = { 0, 2, 4 };
	std::vector<int> AnimationOnFrameIndex = { 1, 3, 5 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	Renderer->CreateAnimation("On", "Flag.png", AnimationInterIndex, AnimationOnFrameIndex, true);
	Renderer->CreateAnimation("Off", "Flag.png", AnimationInterIndex, AnimationOffFrameIndex, true);
	
	Renderer->ChangeAnimation("On");
	Renderer->SetOrder(ERenderOrder::Object);

	SetActorType(ETileType::Flag);
	SetNounType(ENounType::None);

	SetIsBlock(false);
	SetIsPush(false);
	SetIsController(false);
	SetIsSink(false);
	SetIsDefeat(false);

	SetFirstStateInfo(GetTileInfo());
}

void AFlag::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
