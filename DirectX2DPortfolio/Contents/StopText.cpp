#include "PreCompile.h"
#include "StopText.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>


AStopText::AStopText()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	SetRoot(Root);
	
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
}

AStopText::~AStopText()
{

}

void AStopText::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(40.0f, 40.0f, 20.0f));

	std::vector<int> AnimationFrameIndex = { 0, 3, 6 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	Renderer->CreateAnimation("StopText", "StopText.png", AnimationInterIndex, AnimationFrameIndex, true);
	Renderer->ChangeAnimation("StopText");
	Renderer->SetOrder(ERenderOrder::Object);

	SetActorType(ETileType::RWord);
	SetNounType(ENounType::StopText);

	SetIsBlock(true);
	SetIsPush(true);
	SetIsController(false);
}

void AStopText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
