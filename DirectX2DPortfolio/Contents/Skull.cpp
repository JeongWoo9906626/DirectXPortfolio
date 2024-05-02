#include "PreCompile.h"
#include "Skull.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>

ASkull::ASkull()
{

}

ASkull::~ASkull()
{

}

void ASkull::BeginPlay()
{
	Super::BeginPlay();

	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	std::vector<int> AnimationFrameIndex = { 3, 7, 11 };

	Renderer->CreateAnimation("Rock", "Skull.png", AnimationInterIndex, AnimationFrameIndex, true);
	Renderer->ChangeAnimation("Rock");
	Renderer->SetOrder(ERenderOrder::Object);

	SetActorType(ETileType::Skull);
	SetNounType(ENounType::None);

	SetIsBlock(false);
	SetIsPush(false);
	SetIsController(false);
	SetIsSink(false);
	SetIsDefeat(false);

	SetFirstStateInfo(GetTileInfo());
}

void ASkull::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
