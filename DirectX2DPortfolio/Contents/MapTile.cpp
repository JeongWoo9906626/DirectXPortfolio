#include "PreCompile.h"
#include "MapTile.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>

AMapTile::AMapTile()
{

}

AMapTile::~AMapTile()
{

}

void AMapTile::BeginPlay()
{
	Super::BeginPlay();

	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	std::vector<int> AnimationFrameIndex = { 2, 5, 8 };
	Renderer->CreateAnimation("MapTile", "MapTile.png", AnimationInterIndex, AnimationFrameIndex, true);

	Renderer->ChangeAnimation("On");
	Renderer->SetOrder(ERenderOrder::Object);

	SetActorType(ETileType::MapTile);
	SetNounType(ENounType::None);

	SetIsBlock(false);
	SetIsPush(false);
	SetIsController(false);
	SetIsSink(false);
	SetIsDefeat(false);

	SetFirstStateInfo(GetTileInfo());
}

void AMapTile::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
