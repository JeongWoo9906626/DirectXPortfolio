#include "PreCompile.h"
#include "PushText.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

APushText::APushText()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	SetRoot(Root);

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
}

APushText::~APushText()
{
	
}

void APushText::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(40.0f, 40.0f, 20.0f));

	std::vector<int> AnimationFrameIndex = { 0, 3, 6 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	Renderer->CreateAnimation("PushText", "PushText.png", AnimationInterIndex, AnimationFrameIndex, true);
	Renderer->ChangeAnimation("PushText");
	Renderer->SetOrder(ERenderOrder::Words);

	SetActorType(ETileType::RWord);
	SetNounType(ENounType::PushText);

	SetIsBlock(true);
	SetIsPush(true);
	SetIsController(false);

	SetFirstStateInfo(GetTileInfo());
}

void APushText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
