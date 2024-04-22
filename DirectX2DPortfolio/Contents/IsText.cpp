#include "PreCompile.h"
#include "IsText.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

AIsText::AIsText()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	SetRoot(Root);

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
}

AIsText::~AIsText()
{
	
}

void AIsText::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(40.0f, 40.0f, 20.0f));

	std::vector<int> AnimationFrameIndex = { 0, 2, 4 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	Renderer->CreateAnimation("IsVerb", "IsText.png", AnimationInterIndex, AnimationFrameIndex, true);
	Renderer->ChangeAnimation("IsVerb");
	Renderer->SetOrder(ERenderOrder::Words);

	SetActorType(ETileType::Is);
	SetNounType(ENounType::None);

	SetIsBlock(true);
	SetIsPush(true);
	SetIsController(false);

	SetFirstStateInfo(GetTileInfo());
}

void AIsText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
