#include "PreCompile.h"
#include "TestGameMode.h"
#include "TestMap.h"
#include <EngineCore/Camera.h>
#include "StaticHelper.h"
#include "Tile.h"
#include "Baba.h"
#include "Selector.h"
#include "Wall.h"
#include "WallNoun.h"
#include "IsVerb.h"
#include "YouNoun.h"


ATestGameMode::ATestGameMode()
{

}

ATestGameMode::~ATestGameMode()
{

}

void ATestGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	{
		FINT::MapSize = FINT(10, 10);
	}

	{
		FINT Pos = FINT(1, 1);
		std::shared_ptr<ATile> Player = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ABaba>("Baba"));
		Player->SetTileSetting(Pos, true, true, true);
		Player->SetTileLocation();
		//Player->SetActorType(EActorType::Baba);
		TileMap[Pos].push_back(Player);
	}
	{
		FINT TestPos = FINT(2, 2);
		std::shared_ptr<ATile> WallText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWallNoun>("WallNoun"));
		WallText->SetTileSetting(TestPos, true, false, true);
		WallText->SetTileLocation();
		//Test->SetActorType(EActorType::Selector);
		TileMap[TestPos].push_back(WallText);
	}
	{
		FINT TestPos = FINT(2, 3);
		std::shared_ptr<ATile> IsText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AIsVerb>("IsVerb"));
		IsText->SetTileSetting(TestPos, true, false, true);
		IsText->SetTileLocation();
		//Test2->SetActorType(EActorType::Selector);
		TileMap[TestPos].push_back(IsText);
	}

	{
		FINT TestPos = FINT(2, 4);
		std::shared_ptr<ATile> Wall = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWall>("Wall"));
		Wall->SetTileSetting(TestPos, false, false, true);
		Wall->SetTileLocation();
		//Wall->SetActorType(EActorType::Pillar);
		TileMap[TestPos].push_back(Wall);
	}

	{
		FINT TestPos = FINT(3, 3);
		std::shared_ptr<ATile> YouNoun = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AYouNoun>("YouNoun"));
		YouNoun->SetTileSetting(TestPos, true, false, true);
		YouNoun->SetTileLocation();
		//Wall->SetActorType(EActorType::Pillar);
		TileMap[TestPos].push_back(YouNoun);
	}

	StaticHelper::CurTileMap = TileMap;

	GetWorld()->SpawnActor<ATestMap>("TestMap");
}

void ATestGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown('O'))
	{
		GEngine->ChangeLevel("SelectLevel");
	}

	StaticHelper::CurTileMap = TileMap;
	TileUpdate();
}

void ATestGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void ATestGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}

void ATestGameMode::TileUpdate()
{
	std::map<FINT, std::list<std::shared_ptr<ATile>>> NewTileMap;
	for (std::pair<FINT, std::list<std::shared_ptr<ATile>>> Iterator : TileMap)
	{
		FINT CurMapTilePos = Iterator.first;
		std::list<std::shared_ptr<ATile>> TileActorList = Iterator.second;

		for (std::shared_ptr<ATile> TileActor : TileActorList)
		{
			FINT TilePos = TileActor->GetTilePosition();
			if (TilePos != CurMapTilePos)
			{
				NewTileMap[TilePos].push_back(TileActor);
			}
			else
			{
				NewTileMap[TilePos].push_back(TileActor);
			}
		}
	}

	TileMap.clear();
	TileMap = NewTileMap;
	NewTileMap.clear();
}
