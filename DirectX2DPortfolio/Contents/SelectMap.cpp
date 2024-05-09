#include "PreCompile.h"
#include "SelectMap.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

ASelectMap::ASelectMap()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	SetRoot(Root);
}

ASelectMap::~ASelectMap()
{

}

void ASelectMap::BeginPlay()
{
	Super::BeginPlay();

	float ScreenX = GEngine->EngineWindow.GetWindowScale().X;
	float ScreenY = GEngine->EngineWindow.GetWindowScale().Y;

	//SetActorScale3D(FVector(1280.0f, 720.0f, 100.0f));

	Renderer->CreateAnimation("SelectMap", "SelectMap.png", 0.1f, true);
	Renderer->ChangeAnimation("SelectMap");
	Renderer->SetOrder(ERenderOrder::Map);
}

void ASelectMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
