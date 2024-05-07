#include "PreCompile.h"
#include "BackGround.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "EnumHelper.h"

ABackGround::ABackGround()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Root");
	SetRoot(Root);

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetOrder(ERenderOrder::BackGround);
}

ABackGround::~ABackGround()
{

}

void ABackGround::BeginPlay()
{
	Super::BeginPlay();

	FVector WindowScale = GEngine->EngineWindow.GetWindowScale();
	float X = WindowScale.X;
	float Y = WindowScale.Y;

	Renderer->SetSprite("BackGround.png");
}

void ABackGround::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
