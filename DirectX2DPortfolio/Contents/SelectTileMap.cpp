#include "PreCompile.h"
#include "SelectTileMap.h"
#include "StaticHelper.h"
#include "SelectTile.h"

//std::map<FINT, ASelectTile*> ASelectTileMap::SelectMap;

ASelectTileMap::ASelectTileMap()
{
	InputOn();
}

ASelectTileMap::~ASelectTileMap()
{

}

void ASelectTileMap::BeginPlay()
{
	Super::BeginPlay();

	for (int X = 0; X < FINT::SelectMapSize.X; X++)
	{
		for (int Y = 0; Y < FINT::SelectMapSize.Y; Y++)
		{
			FINT SelectPosition = FINT(X, Y);
			StaticHelper::CurSelectTileMap[SelectPosition] = GetWorld()->SpawnActor<ASelectTile>("SelectTile").get();
		}
	}

	// Stage

	StaticHelper::CurSelectTileMap[FINT(0, 0)]->SetAnimation(0, false);
	StaticHelper::CurSelectTileMap[FINT(0, 0)]->SetActorLocation(FINT(0, 0).GetSelectFINTToVector());
	StaticHelper::CurSelectTileMap[FINT(0, 0)]->SelectInfo.IsEnter = true;
	StaticHelper::CurSelectTileMap[FINT(0, 0)]->SelectInfo.Type = ESelectTileType::Stage;
	StaticHelper::CurSelectTileMap[FINT(0, 0)]->SelectInfo.Stage = "Stage0" + std::to_string(0);
	StaticHelper::CurSelectTileMap[FINT(0, 0)]->SelectInfo.StageText = "BABA IS YOU";
	StaticHelper::CurSelectTileMap[FINT(0, 0)]->ShowOn();

	StaticHelper::CurSelectTileMap[FINT(1, 2)]->SetAnimation(1, false);
	StaticHelper::CurSelectTileMap[FINT(1, 2)]->SetActorLocation(FINT(1, 2).GetSelectFINTToVector());
	StaticHelper::CurSelectTileMap[FINT(1, 2)]->SelectInfo.IsEnter = false;
	StaticHelper::CurSelectTileMap[FINT(1, 2)]->SelectInfo.Type = ESelectTileType::Stage;
	StaticHelper::CurSelectTileMap[FINT(1, 2)]->SelectInfo.Stage = "Stage0" + std::to_string(1);
	StaticHelper::CurSelectTileMap[FINT(1, 2)]->SelectInfo.StageText = "WHERE DO I GO";

	StaticHelper::CurSelectTileMap[FINT(1, 3)]->SetAnimation(2, false);
	StaticHelper::CurSelectTileMap[FINT(1, 3)]->SetActorLocation(FINT(1, 3).GetSelectFINTToVector());
	StaticHelper::CurSelectTileMap[FINT(1, 3)]->SelectInfo.IsEnter = false;
	StaticHelper::CurSelectTileMap[FINT(1, 3)]->SelectInfo.Type = ESelectTileType::Stage;
	StaticHelper::CurSelectTileMap[FINT(1, 3)]->SelectInfo.Stage = "Stage0" + std::to_string(2);
	StaticHelper::CurSelectTileMap[FINT(1, 3)]->SelectInfo.StageText = "NOW WHAT IS THIS";

	StaticHelper::CurSelectTileMap[FINT(2, 2)]->SetAnimation(3, false);
	StaticHelper::CurSelectTileMap[FINT(2, 2)]->SetActorLocation(FINT(2, 2).GetSelectFINTToVector());
	StaticHelper::CurSelectTileMap[FINT(2, 2)]->SelectInfo.IsEnter = false;
	StaticHelper::CurSelectTileMap[FINT(2, 2)]->SelectInfo.Type = ESelectTileType::Stage;
	StaticHelper::CurSelectTileMap[FINT(2, 2)]->SelectInfo.Stage = "Stage0" + std::to_string(3);
	StaticHelper::CurSelectTileMap[FINT(2, 2)]->SelectInfo.StageText = "OUT OF REACH";

	StaticHelper::CurSelectTileMap[FINT(2, 3)]->SetAnimation(4, false);
	StaticHelper::CurSelectTileMap[FINT(2, 3)]->SetActorLocation(FINT(2, 3).GetSelectFINTToVector());
	StaticHelper::CurSelectTileMap[FINT(2, 3)]->SelectInfo.IsEnter = false;
	StaticHelper::CurSelectTileMap[FINT(2, 3)]->SelectInfo.Type = ESelectTileType::Stage;
	StaticHelper::CurSelectTileMap[FINT(2, 3)]->SelectInfo.Stage = "Stage0" + std::to_string(4);
	StaticHelper::CurSelectTileMap[FINT(2, 3)]->SelectInfo.StageText = "STILL OUT OF REACH";

	StaticHelper::CurSelectTileMap[FINT(1, 4)]->SetAnimation(5, false);
	StaticHelper::CurSelectTileMap[FINT(1, 4)]->SetActorLocation(FINT(1, 4).GetSelectFINTToVector());
	StaticHelper::CurSelectTileMap[FINT(1, 4)]->SelectInfo.IsEnter = false;
	StaticHelper::CurSelectTileMap[FINT(1, 4)]->SelectInfo.Type = ESelectTileType::Stage;
	StaticHelper::CurSelectTileMap[FINT(1, 4)]->SelectInfo.Stage = "Stage0" + std::to_string(5);
	StaticHelper::CurSelectTileMap[FINT(1, 4)]->SelectInfo.StageText = "VOLCANO";

	StaticHelper::CurSelectTileMap[FINT(3, 3)]->SetAnimation(6, false);
	StaticHelper::CurSelectTileMap[FINT(3, 3)]->SetActorLocation(FINT(3, 3).GetSelectFINTToVector());
	StaticHelper::CurSelectTileMap[FINT(3, 3)]->SelectInfo.IsEnter = false;
	StaticHelper::CurSelectTileMap[FINT(3, 3)]->SelectInfo.Type = ESelectTileType::Stage;
	StaticHelper::CurSelectTileMap[FINT(3, 3)]->SelectInfo.Stage = "Stage0" + std::to_string(6);
	StaticHelper::CurSelectTileMap[FINT(3, 3)]->SelectInfo.StageText = "OFF LIMITS";

	StaticHelper::CurSelectTileMap[FINT(2, 4)]->SetAnimation(7, false);
	StaticHelper::CurSelectTileMap[FINT(2, 4)]->SetActorLocation(FINT(2, 4).GetSelectFINTToVector());
	StaticHelper::CurSelectTileMap[FINT(2, 4)]->SelectInfo.IsEnter = false;
	StaticHelper::CurSelectTileMap[FINT(2, 4)]->SelectInfo.Type = ESelectTileType::Stage;
	StaticHelper::CurSelectTileMap[FINT(2, 4)]->SelectInfo.Stage = "Stage0" + std::to_string(7);
	StaticHelper::CurSelectTileMap[FINT(2, 4)]->SelectInfo.StageText = "GRASS YARD";

	StaticHelper::CurSelectTileMap[FINT(6, 6)]->SetAnimation(8, false);
	StaticHelper::CurSelectTileMap[FINT(6, 6)]->SetActorLocation(FINT(6, 6).GetSelectFINTToVector());
	StaticHelper::CurSelectTileMap[FINT(6, 6)]->SelectInfo.IsEnter = false;
	StaticHelper::CurSelectTileMap[FINT(6, 6)]->SelectInfo.Type = ESelectTileType::Stage;
	StaticHelper::CurSelectTileMap[FINT(6, 6)]->SelectInfo.Stage = "Stage0" + std::to_string(8);
	StaticHelper::CurSelectTileMap[FINT(6, 6)]->SelectInfo.StageText = "TURNS";

	// Walk
	int TileNum = 100;
	StaticHelper::CurSelectTileMap[FINT(1, 0)]->SetActorLocation(FINT(1, 0).GetSelectFINTToVector());
	StaticHelper::CurSelectTileMap[FINT(1, 0)]->SelectInfo.IsEnter = false;
	StaticHelper::CurSelectTileMap[FINT(1, 0)]->SelectInfo.Type = ESelectTileType::Walk;
	StaticHelper::CurSelectTileMap[FINT(1, 0)]->SelectInfo.Stage = "Walk";

	StaticHelper::CurSelectTileMap[FINT(1, 1)]->SetActorLocation(FINT(1, 1).GetSelectFINTToVector());
	StaticHelper::CurSelectTileMap[FINT(1, 1)]->SelectInfo.IsEnter = false;
	StaticHelper::CurSelectTileMap[FINT(1, 1)]->SelectInfo.Type = ESelectTileType::Walk;
	StaticHelper::CurSelectTileMap[FINT(1, 1)]->SelectInfo.Stage = "Walk";

	StaticHelper::CurSelectTileMap[FINT(3, 2)]->SetActorLocation(FINT(3, 2).GetSelectFINTToVector());
	StaticHelper::CurSelectTileMap[FINT(3, 2)]->SelectInfo.IsEnter = false;
	StaticHelper::CurSelectTileMap[FINT(3, 2)]->SelectInfo.Type = ESelectTileType::Walk;
	StaticHelper::CurSelectTileMap[FINT(3, 2)]->SelectInfo.Stage = "Walk";

	StaticHelper::CurSelectTileMap[FINT(3, 4)]->SetActorLocation(FINT(3, 4).GetSelectFINTToVector());
	StaticHelper::CurSelectTileMap[FINT(3, 4)]->SelectInfo.IsEnter = false;
	StaticHelper::CurSelectTileMap[FINT(3, 4)]->SelectInfo.Type = ESelectTileType::Walk;
	StaticHelper::CurSelectTileMap[FINT(3, 4)]->SelectInfo.Stage = "Walk";

	StaticHelper::CurSelectTileMap[FINT(4, 4)]->SetActorLocation(FINT(4, 4).GetSelectFINTToVector());
	StaticHelper::CurSelectTileMap[FINT(4, 4)]->SelectInfo.IsEnter = false;
	StaticHelper::CurSelectTileMap[FINT(4, 4)]->SelectInfo.Type = ESelectTileType::Walk;
	StaticHelper::CurSelectTileMap[FINT(4, 4)]->SelectInfo.Stage = "Walk";

	StaticHelper::CurSelectTileMap[FINT(5, 4)]->SetActorLocation(FINT(5, 4).GetSelectFINTToVector());
	StaticHelper::CurSelectTileMap[FINT(5, 4)]->SelectInfo.IsEnter = false;
	StaticHelper::CurSelectTileMap[FINT(5, 4)]->SelectInfo.Type = ESelectTileType::Walk;
	StaticHelper::CurSelectTileMap[FINT(5, 4)]->SelectInfo.Stage = "Walk";

	StaticHelper::CurSelectTileMap[FINT(6, 4)]->SetActorLocation(FINT(6, 4).GetSelectFINTToVector());
	StaticHelper::CurSelectTileMap[FINT(6, 4)]->SelectInfo.IsEnter = false;
	StaticHelper::CurSelectTileMap[FINT(6, 4)]->SelectInfo.Type = ESelectTileType::Walk;
	StaticHelper::CurSelectTileMap[FINT(6, 4)]->SelectInfo.Stage = "Walk";

	StaticHelper::CurSelectTileMap[FINT(6, 5)]->SetActorLocation(FINT(6, 5).GetSelectFINTToVector());
	StaticHelper::CurSelectTileMap[FINT(6, 5)]->SelectInfo.IsEnter = false;
	StaticHelper::CurSelectTileMap[FINT(6, 5)]->SelectInfo.Type = ESelectTileType::Walk;
	StaticHelper::CurSelectTileMap[FINT(6, 5)]->SelectInfo.Stage = "Walk";

	StaticHelper::CurSelectTileMap[FINT(1, 0)]->SetAnimation(TileNum, false, FINT(1, 0));
	StaticHelper::CurSelectTileMap[FINT(1, 1)]->SetAnimation(TileNum, false, FINT(1, 1));
	StaticHelper::CurSelectTileMap[FINT(3, 2)]->SetAnimation(TileNum, false, FINT(3, 2));
	StaticHelper::CurSelectTileMap[FINT(3, 4)]->SetAnimation(TileNum, false, FINT(3, 4));
	StaticHelper::CurSelectTileMap[FINT(4, 4)]->SetAnimation(TileNum, false, FINT(4, 4));
	StaticHelper::CurSelectTileMap[FINT(5, 4)]->SetAnimation(TileNum, false, FINT(5, 4));
	StaticHelper::CurSelectTileMap[FINT(6, 4)]->SetAnimation(TileNum, false, FINT(6, 4));
	StaticHelper::CurSelectTileMap[FINT(6, 5)]->SetAnimation(TileNum, false, FINT(6, 5));
}

void ASelectTileMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void ASelectTileMap::StageChangeCheck()
{
}
