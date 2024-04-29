#include "PreCompile.h"
#include "TestMap.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

ATestMap::ATestMap()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	SetRoot(Root);

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
}

ATestMap::~ATestMap()
{

}

void ATestMap::BeginPlay()
{
	Super::BeginPlay();

	//std::shared_ptr<ABackGround> BackGround = GetWorld()->SpawnActor<ABackGround>("BG");

	float ScreenX = GEngine->EngineWindow.GetWindowScale().X;
	float ScreenY = GEngine->EngineWindow.GetWindowScale().Y;

	SetActorScale3D(FVector(ScreenX * 1.295f, ScreenY * 2.37f, 100.0f));
}

void ATestMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}