#include "PreCompile.h"
#include "FadeActor.h"
#include <EngineCore/EngineCore.h>
#include <EngineCore/EngineDebugMsgWindow.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "EnumHelper.h"

AFadeActor::AFadeActor()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	SetRoot(Root);

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	Renderer->SetOrder(ERenderOrder::Effect);
}

AFadeActor::~AFadeActor()
{

}

void AFadeActor::BeginPlay()
{
	Super::BeginPlay();
	Renderer->SetSprite("FadeActor.png");
}

void AFadeActor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FVector Scale = GetActorScale3D();
	if (Scale.X > 1280 * 3 || Scale.Y > 720 * 3)
	{
		Destroy();
	}

	AddActorScale3D(FVector(1280 * _DeltaTime * 1.5f, 720 * _DeltaTime * 1.5f));
}