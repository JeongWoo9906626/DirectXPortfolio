#include "PreCompile.h"
#include "Rock.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>

ARock::ARock()
{

}

ARock::~ARock()
{

}

void ARock::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("Rock", "Rock.png", 0.1f, true);

	Renderer->ChangeAnimation("Rock");
	Renderer->SetOrder(ERenderOrder::Object);

	SetActorType(ETileType::Rock);
	SetNounType(ENounType::None);

	SetIsBlock(false);
	SetIsPush(false);
	SetIsController(false);
	SetIsSink(false);
	SetIsDefeat(false);

	SetFirstStateInfo(GetTileInfo());
}

void ARock::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
