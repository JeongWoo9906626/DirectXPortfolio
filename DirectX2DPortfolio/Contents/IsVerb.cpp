#include "PreCompile.h"
#include "IsVerb.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

AIsVerb::AIsVerb()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	SetRoot(Root);
	//InputOn();
}

AIsVerb::~AIsVerb()
{
	
}

void AIsVerb::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(40.0f, 40.0f, 20.0f));

	std::vector<int> AnimationFrameIndex = { 0, 2, 4 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	Renderer->CreateAnimation("IsVerb", "Is.png", AnimationInterIndex, AnimationFrameIndex, true);
	Renderer->ChangeAnimation("IsVerb");
	Renderer->SetOrder(ERenderOrder::Object);

	SetActorType(EActorType::Verb);
}

void AIsVerb::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}