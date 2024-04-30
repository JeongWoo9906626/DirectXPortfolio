#include "PreCompile.h"
#include "Selector.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

ASelector::ASelector()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	SetRoot(Root);

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
}

ASelector::~ASelector()
{

}

void ASelector::BeginPlay()
{
	Super::BeginPlay();

	Renderer->CreateAnimation("SelectMove", "Selector.png", 0.1f, true);
	Renderer->ChangeAnimation("SelectMove");
	Renderer->SetOrder(ERenderOrder::Player);
}

void ASelector::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown(VK_LEFT))
	{

	}
	if (true == UEngineInput::IsDown(VK_RIGHT))
	{

	}
	if (true == UEngineInput::IsDown(VK_UP))
	{

	}
	if (true == UEngineInput::IsDown(VK_DOWN))
	{

	}
	if (true == UEngineInput::IsDown(VK_SPACE))
	{

	}

}

