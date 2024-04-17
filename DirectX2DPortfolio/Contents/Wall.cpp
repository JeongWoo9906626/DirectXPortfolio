#include "PreCompile.h"
#include "Wall.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

AWall::AWall()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	SetRoot(Root);
	InputOn();
}

AWall::~AWall()
{

}

void AWall::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(40.0f, 40.0f, 20.0f));

	std::vector<int> AnimationFrameIndex = { 2, 20, 38 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	Renderer->CreateAnimation("WallMove", "Wall.png", AnimationInterIndex, AnimationFrameIndex, true);
	Renderer->ChangeAnimation("WallMove");
	Renderer->SetOrder(ERenderOrder::Object);

	SetActorType(EActorType::Pillar);
}

void AWall::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
