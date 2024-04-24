#include "PreCompile.h"
#include "Wall.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

AWall::AWall()
{

}

AWall::~AWall()
{

}

void AWall::BeginPlay()
{
	Super::BeginPlay();

	std::vector<int> AnimationFrameIndex = { 2, 20, 38 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	Renderer->CreateAnimation("WallMove", "Wall.png", AnimationInterIndex, AnimationFrameIndex, true);
	Renderer->ChangeAnimation("WallMove");
	Renderer->SetOrder(ERenderOrder::Object);

	SetActorType(ETileType::Pillar);
	SetNounType(ENounType::None);

	SetIsBlock(false);
	SetIsPush(false);
	SetIsController(false);
	SetIsSink(false);
	SetIsDefeat(false);

	SetFirstStateInfo(GetTileInfo());
}

void AWall::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
