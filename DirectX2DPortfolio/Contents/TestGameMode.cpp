#include "PreCompile.h"
#include "TestGameMode.h"
#include "TestMap.h"
#include <EngineCore/Camera.h>
#include "StaticHelper.h"
#include "Tile.h"
#include "Baba.h"
#include "Selector.h"


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
		std::shared_ptr<ATile> Player = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ABaba>("Player"));
		Player->SetTileSetting(Pos, true, true, false);
		Player->SetTileLocation();
		Player->SetActorType(EActorType::Baba);
		TileMap[Pos].push_back(Player);
	}
	{
		FINT TestPos = FINT(2, 2);
		std::shared_ptr<ATile> Test = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ASelector>("Test1"));
		Test->SetTileSetting(TestPos, true, false, true);
		Test->SetTileLocation();
		Test->SetActorType(EActorType::Selector);
		TileMap[TestPos].push_back(Test);
	}
	{
		FINT TestPos = FINT(2, 3);
		std::shared_ptr<ATile> Test2 = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ASelector>("Test2"));
		//std::shared_ptr<ATile> PlayerTest = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ABaba>("Baba"));
		Test2->SetTileSetting(TestPos, true, false, true);
		Test2->SetTileLocation();
		Test2->SetActorType(EActorType::Selector);
		TileMap[TestPos].push_back(Test2);
	}

	{
		FINT TestPos = FINT(2, 4);
		std::shared_ptr<ATile> PlayerTest2 = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ABaba>("Baba2"));
		PlayerTest2->SetTileSetting(TestPos, false, false, true);
		PlayerTest2->SetTileLocation();
		PlayerTest2->SetActorType(EActorType::Baba);
		TileMap[TestPos].push_back(PlayerTest2);
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
