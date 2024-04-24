#include "PreCompile.h"
#include "YouText.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

AYouText::AYouText()
{
	/*UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	SetRoot(Root);

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);*/
}

AYouText::~AYouText()
{

}

void AYouText::BeginPlay()
{
	Super::BeginPlay();

	//SetActorScale3D(FVector(40.0f, 40.0f, 20.0f));

	std::vector<int> AnimationOffFrameIndex = { 1, 4, 7 };
	std::vector<int> AnimationOnFrameIndex = { 2, 5, 8 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };

	Renderer->CreateAnimation("Off", "YouText.png", AnimationInterIndex, AnimationOffFrameIndex, true);
	Renderer->CreateAnimation("On", "YouText.png", AnimationInterIndex, AnimationOnFrameIndex, true);

	Renderer->ChangeAnimation("Off");
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
