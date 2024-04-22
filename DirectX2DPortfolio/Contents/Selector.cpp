#include "PreCompile.h"
#include "Selector.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

ASelector::ASelector()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	SetRoot(Root);
	InputOn();
}

ASelector::~ASelector()
{

}

void ASelector::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(FVector(1000.0f, 1000.0f, 20.0f));
	
	Renderer->CreateAnimation("SelectMove", "Selector.png", 0.1f, true);
	Renderer->ChangeAnimation("SelectMove");
	Renderer->SetOrder(ERenderOrder::Player);

	SetActorType(ETileType::Selector);
	SetNounType(ENounType::None);

	SetIsBlock(true);
	SetIsPush(true);
	SetIsController(true);
}

void ASelector::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	/*if (false == HasController)
	{
		if (true == UEngineInput::IsDown('T'))
		{
			FINT CurTilePos = GetTilePosition();
			std::list<std::shared_ptr<ATile>> TileActorList = StaticHelper::CurTileMap[CurTilePos];
			for (std::shared_ptr<ATile> TileActor : TileActorList)
			{
				if (EActorType::Selector == TileActor->GetActorType())
				{
					TileActor->SetHasController(true);
				}
			}
		}
	}
	else
	{
		if (true == UEngineInput::IsDown('T'))
		{
			FINT CurTilePos = GetTilePosition();
			std::list<std::shared_ptr<ATile>> TileActorList = StaticHelper::CurTileMap[CurTilePos];
			for (std::shared_ptr<ATile> TileActor : TileActorList)
			{
				if (EActorType::Selector == TileActor->GetActorType())
				{
					TileActor->SetHasController(false);
				}
			}
		}
	}*/
}

