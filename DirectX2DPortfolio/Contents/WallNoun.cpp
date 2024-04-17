#include "PreCompile.h"
#include "WallNoun.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

AWallNoun::AWallNoun()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	SetRoot(Root);
	//InputOn();
}

AWallNoun::~AWallNoun()
{
	
}

void AWallNoun::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(40.0f, 40.0f, 20.0f));

	std::vector<int> AnimationFrameIndex = { 0, 18, 36 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	Renderer->CreateAnimation("WallText", "Wall.png", AnimationInterIndex, AnimationFrameIndex, true);
	Renderer->ChangeAnimation("WallText");
	Renderer->SetOrder(ERenderOrder::Object);

	SetActorType(EActorType::CharNoun);
	SetNounType(ENounType::Pillar);
}

void AWallNoun::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
