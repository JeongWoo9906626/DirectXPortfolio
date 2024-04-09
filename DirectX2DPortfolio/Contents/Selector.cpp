#include "PreCompile.h"
#include "Selector.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>

ASelector::ASelector()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	InputOn();
}

ASelector::~ASelector()
{

}

void ASelector::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(1000.0f, 1000.0f, 20.0f));

	Renderer->CreateAnimation("SelectMove", "Selector.png", 0.1f, true);
	Renderer->ChangeAnimation("SelectMove");
}

void ASelector::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

