#include "PreCompile.h"
#include "MapTileText.h"
#include <EngineCore/DefaultSceneComponent.h>	
#include <EngineCore/SpriteRenderer.h>

MapTileText::MapTileText()
{

}

MapTileText::~MapTileText()
{

}

void MapTileText::BeginPlay()
{
	Super::BeginPlay();

	std::vector<int> AnimationOffFrameIndex = { 0, 3, 6 };
	std::vector<int> AnimationOnFrameIndex = { 1, 4, 7 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	Renderer->CreateAnimation("Off", "MapTile.png", AnimationInterIndex, AnimationOffFrameIndex, true);
	Renderer->CreateAnimation("On", "MapTile.png", AnimationInterIndex, AnimationOnFrameIndex, true);

	Renderer->ChangeAnimation("Off");
	Renderer->SetOrder(ERenderOrder::Words);

	SetActorType(ETileType::LWord);
	SetNounType(ENounType::MapTileText);

	SetIsBlock(true);
	SetIsPush(true);
	SetIsController(false);
	SetIsSink(false);
	SetIsDefeat(false);

	SetFirstStateInfo(GetTileInfo());
}

void MapTileText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
