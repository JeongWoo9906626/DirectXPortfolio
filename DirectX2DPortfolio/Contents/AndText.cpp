#include "PreCompile.h"
#include "AndText.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

AndText::AndText()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	SetRoot(Root);
}

AndText::~AndText()
{

}

void AndText::BeginPlay()
{
	Super::BeginPlay();

	/*SetActorScale3D(FVector(40.0f, 40.0f, 20.0f));

	std::vector<int> AnimationFrameIndex = { 0, 18, 36 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };
	Renderer->CreateAnimation("AndText", "And.png", AnimationInterIndex, AnimationFrameIndex, true);
	Renderer->ChangeAnimation("AndText");
	Renderer->SetOrder(ERenderOrder::Object);

	SetActorType(ETileType::And);
	SetNounType(ENounType::None);
	
	SetIsBlock(true);
	SetIsPush(true);
	SetIsController(false);

	SetFirstStateInfo(GetTileInfo());
	*/
}

void AndText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
