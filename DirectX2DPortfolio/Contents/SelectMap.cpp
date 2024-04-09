#include "PreCompile.h"
#include "SelectMap.h"
#include <EngineCore/SpriteRenderer.h>

ASelectMap::ASelectMap()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
}

ASelectMap::~ASelectMap()
{

}

void ASelectMap::BeginPlay()
{
	Super::BeginPlay();

	float ScreenX = GEngine->EngineWindow.GetWindowScale().X;
	float ScreenY = GEngine->EngineWindow.GetWindowScale().Y;

	SetActorScale3D(FVector(ScreenX * 1.295f, ScreenY * 2.37f, 100.0f));

	Renderer->CreateAnimation("SelectMap", "SelectMap.png", 0.1f, true);
	Renderer->ChangeAnimation("SelectMap");
	Renderer->SetOrder(ERenderOrder::Map);
}

void ASelectMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
