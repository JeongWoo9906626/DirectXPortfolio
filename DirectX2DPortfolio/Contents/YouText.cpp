#include "PreCompile.h"
#include "YouText.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

AYouText::AYouText()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	SetRoot(Root);

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
}

AYouText::~AYouText()
{

}

void AYouText::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(40.0f, 40.0f, 20.0f));

	std::vector<int> AnimationFrameIndex = { 0, 3, 6 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	Renderer->CreateAnimation("YouText", "YouText.png", AnimationInterIndex, AnimationFrameIndex, true);
	Renderer->ChangeAnimation("YouText");
	Renderer->SetOrder(ERenderOrder::Words);

	SetActorType(ETileType::RWord);
	SetNounType(ENounType::YouText);

	SetIsBlock(true);
	SetIsPush(true);
	SetIsController(false);
	SetIsSink(false);
	SetIsDefeat(false);

	SetFirstStateInfo(GetTileInfo());
}

void AYouText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
