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

	std::vector<int> AnimationOnFrameIndex = { 1, 4, 7 };
	std::vector<int> AnimationOffFrameIndex = { 2, 5, 8 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };

	Renderer->CreateAnimation("Off", "StopText.png", AnimationInterIndex, AnimationOffFrameIndex, true);
	Renderer->CreateAnimation("On", "StopText.png", AnimationInterIndex, AnimationOnFrameIndex, true);

	Renderer->ChangeAnimation("Off");
	Renderer->SetOrder(ERenderOrder::Words);

	SetActorType(ETileType::RWord);
	SetNounType(ENounType::StopText);

	SetIsBlock(true);
	SetIsPush(true);
	SetIsController(false);
	SetIsSink(false);
	SetIsDefeat(false);

	SetFirstStateInfo(GetTileInfo());
}

void AStopText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
