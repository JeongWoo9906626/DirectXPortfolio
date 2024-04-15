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
		//for (int y = 0; y < FINT::MapSize.Y; y++)
		//{
		//	for (int x = 0; x < FINT::MapSize.X; x++)
		//	{
		//		FINT Pos = FINT(x, y);
		//		std::shared_ptr<ATile> NewTile = std::make_shared<ATile>();
		//		/*NewTile->SetTileSetting(Pos, false, false, false);
		//		NewTile->SetActorType(EActorType::Empty);*/
		//		TileMap[Pos].push_back(nullptr);
		//	}
		//}
	}

	{
		FINT Pos = FINT(1, 1);
		std::shared_ptr<ATile> Player = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ABaba>("Baba"));
		Player->SetTileSetting(Pos, true, true, false);
		Player->SetTileLocation();
		Player->SetActorType(EActorType::Baba);
		TileMap[Pos].push_back(Player);
	}
	{
		FINT TestPos = FINT(2, 2);
		std::shared_ptr<ATile> Test = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ASelector>("Test"));
		Test->SetTileSetting(TestPos, false, false, false);
		Test->SetTileLocation();
		Test->SetActorType(EActorType::Selector);
		TileMap[TestPos].push_back(Test);
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
				for (std::shared_ptr<ATile> TileActorIter : NewTileMap[CurMapTilePos])
				{
					NewTileMap[CurMapTilePos].push_back(TileActorIter);
					TileActorIter->SetPosition(CurMapTilePos);
				}
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
