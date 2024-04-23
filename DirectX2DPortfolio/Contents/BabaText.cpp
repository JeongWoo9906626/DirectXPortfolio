#include "PreCompile.h"
#include "BabaText.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

ABabaText::ABabaText()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	SetRoot(Root);
}

ABabaText::~ABabaText()
{

}

void ABabaText::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(40.0f, 40.0f, 20.0f));

	std::vector<int> AnimationOffFrameIndex = { 1, 3, 5 };
	std::vector<int> AnimationOnFrameIndex = { 2, 4, 6 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	Renderer->CreateAnimation("Off", "BabaText.png", AnimationInterIndex, AnimationOffFrameIndex, true);
	Renderer->CreateAnimation("On", "BabaText.png", AnimationInterIndex, AnimationOnFrameIndex, true);

	Renderer->ChangeAnimation("Off");
	Renderer->SetOrder(ERenderOrder::Words);

	SetActorType(ETileType::LWord);
	SetNounType(ENounType::BabaText);

	SetIsBlock(true);
	SetIsPush(true);
	SetIsController(false);
	SetIsSink(false);
	SetIsDefeat(false);

	SetFirstStateInfo(GetTileInfo());
}

void ABabaText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
