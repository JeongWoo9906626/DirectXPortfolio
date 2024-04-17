#include "PreCompile.h"
#include "YouNoun.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

AYouNoun::AYouNoun()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	SetRoot(Root);
}

AYouNoun::~AYouNoun()
{

}

void AYouNoun::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(40.0f, 40.0f, 20.0f));

	std::vector<int> AnimationFrameIndex = { 4, 22, 40 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	Renderer->CreateAnimation("WallText", "Wall.png", AnimationInterIndex, AnimationFrameIndex, true);
	Renderer->ChangeAnimation("WallText");
	Renderer->SetOrder(ERenderOrder::Object);

	SetActorType(EActorType::Noun);
	SetNounType(ENounType::You);
}

void AYouNoun::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
