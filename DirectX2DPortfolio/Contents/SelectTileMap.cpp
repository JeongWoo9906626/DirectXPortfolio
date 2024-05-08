#include "PreCompile.h"
#include "SelectTileMap.h"
#include "StaticHelper.h"
#include "SelectTile.h"

std::map<FINT, ASelectTile*> ASelectTileMap::SelectMap;

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
			SelectMap[SelectPosition] = GetWorld()->SpawnActor<ASelectTile>("SelectTile").get();
		}
	}

	// Walk

	SelectMap[FINT(1, 0)]->SetAnimation(0, false);
	SelectMap[FINT(1, 0)]->SetActorLocation(FINT(1, 0).GetSelectFINTToVector());
	SelectMap[FINT(1, 0)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(1, 0)]->SelectInfo.Type = ESelectTileType::Walk;
	SelectMap[FINT(1, 0)]->SelectInfo.Stage = "Walk";

	SelectMap[FINT(1, 1)]->SetAnimation(0, false);
	SelectMap[FINT(1, 1)]->SetActorLocation(FINT(1, 1).GetSelectFINTToVector());
	SelectMap[FINT(1, 1)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(1, 1)]->SelectInfo.Type = ESelectTileType::Walk;
	SelectMap[FINT(1, 1)]->SelectInfo.Stage = "Walk";

	SelectMap[FINT(3, 2)]->SetAnimation(0, false);
	SelectMap[FINT(3, 2)]->SetActorLocation(FINT(3, 2).GetSelectFINTToVector());
	SelectMap[FINT(3, 2)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(3, 2)]->SelectInfo.Type = ESelectTileType::Walk;
	SelectMap[FINT(3, 2)]->SelectInfo.Stage = "Walk";

	SelectMap[FINT(3, 4)]->SetAnimation(0, false);
	SelectMap[FINT(3, 4)]->SetActorLocation(FINT(3, 4).GetSelectFINTToVector());
	SelectMap[FINT(3, 4)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(3, 4)]->SelectInfo.Type = ESelectTileType::Walk;
	SelectMap[FINT(3, 4)]->SelectInfo.Stage = "Walk";

	SelectMap[FINT(4, 4)]->SetAnimation(0, false);
	SelectMap[FINT(4, 4)]->SetActorLocation(FINT(4, 4).GetSelectFINTToVector());
	SelectMap[FINT(4, 4)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(4, 4)]->SelectInfo.Type = ESelectTileType::Walk;
	SelectMap[FINT(4, 4)]->SelectInfo.Stage = "Walk";

	SelectMap[FINT(5, 4)]->SetAnimation(0, false);
	SelectMap[FINT(5, 4)]->SetActorLocation(FINT(5, 4).GetSelectFINTToVector());
	SelectMap[FINT(5, 4)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(5, 4)]->SelectInfo.Type = ESelectTileType::Walk;
	SelectMap[FINT(5, 4)]->SelectInfo.Stage = "Walk";

	SelectMap[FINT(6, 4)]->SetAnimation(0, false);
	SelectMap[FINT(6, 4)]->SetActorLocation(FINT(6, 4).GetSelectFINTToVector());
	SelectMap[FINT(6, 4)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(6, 4)]->SelectInfo.Type = ESelectTileType::Walk;
	SelectMap[FINT(6, 4)]->SelectInfo.Stage = "Walk";

	SelectMap[FINT(6, 5)]->SetAnimation(0, false);
	SelectMap[FINT(6, 5)]->SetActorLocation(FINT(6, 5).GetSelectFINTToVector());
	SelectMap[FINT(6, 5)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(6, 5)]->SelectInfo.Type = ESelectTileType::Walk;
	SelectMap[FINT(6, 5)]->SelectInfo.Stage = "Walk";


	// Stage

	SelectMap[FINT(0, 0)]->SetAnimation(0, false);
	SelectMap[FINT(0, 0)]->SetActorLocation(FINT(0, 0).GetSelectFINTToVector());
	SelectMap[FINT(0, 0)]->SelectInfo.IsEnter = true;
	SelectMap[FINT(0, 0)]->SelectInfo.Type = ESelectTileType::Stage;
	SelectMap[FINT(0, 0)]->SelectInfo.Stage = "Stage0" + std::to_string(0);
	SelectMap[FINT(0, 0)]->ShowOn();

	SelectMap[FINT(1, 2)]->SetAnimation(1, false);
	SelectMap[FINT(1, 2)]->SetActorLocation(FINT(1, 2).GetSelectFINTToVector());
	SelectMap[FINT(1, 2)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(1, 2)]->SelectInfo.Type = ESelectTileType::Stage;
	SelectMap[FINT(1, 2)]->SelectInfo.Stage = "Stage0" + std::to_string(1);
	
	SelectMap[FINT(1, 3)]->SetAnimation(2, false);
	SelectMap[FINT(1, 3)]->SetActorLocation(FINT(1, 3).GetSelectFINTToVector());
	SelectMap[FINT(1, 3)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(1, 3)]->SelectInfo.Type = ESelectTileType::Stage;
	SelectMap[FINT(1, 3)]->SelectInfo.Stage = "Stage0" + std::to_string(2);
	
	SelectMap[FINT(2, 2)]->SetAnimation(3, false);
	SelectMap[FINT(2, 2)]->SetActorLocation(FINT(2, 2).GetSelectFINTToVector());
	SelectMap[FINT(2, 2)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(2, 2)]->SelectInfo.Type = ESelectTileType::Stage;
	SelectMap[FINT(2, 2)]->SelectInfo.Stage = "Stage0" + std::to_string(3);

	SelectMap[FINT(2, 3)]->SetAnimation(4, false);
	SelectMap[FINT(2, 3)]->SetActorLocation(FINT(2, 3).GetSelectFINTToVector());
	SelectMap[FINT(2, 3)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(2, 3)]->SelectInfo.Type = ESelectTileType::Stage;
	SelectMap[FINT(2, 3)]->SelectInfo.Stage = "Stage0" + std::to_string(4);
	
	SelectMap[FINT(1, 4)]->SetAnimation(5, false);
	SelectMap[FINT(1, 4)]->SetActorLocation(FINT(1, 4).GetSelectFINTToVector());
	SelectMap[FINT(1, 4)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(1, 4)]->SelectInfo.Type = ESelectTileType::Stage;
	SelectMap[FINT(1, 4)]->SelectInfo.Stage = "Stage0" + std::to_string(5);

	SelectMap[FINT(3, 3)]->SetAnimation(6, false);
	SelectMap[FINT(3, 3)]->SetActorLocation(FINT(3, 3).GetSelectFINTToVector());
	SelectMap[FINT(3, 3)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(3, 3)]->SelectInfo.Type = ESelectTileType::Stage;
	SelectMap[FINT(3, 3)]->SelectInfo.Stage = "Stage0" + std::to_string(6);

	SelectMap[FINT(2, 4)]->SetAnimation(7, false);
	SelectMap[FINT(2, 4)]->SetActorLocation(FINT(2, 4).GetSelectFINTToVector());
	SelectMap[FINT(2, 4)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(2, 4)]->SelectInfo.Type = ESelectTileType::Stage;
	SelectMap[FINT(2, 4)]->SelectInfo.Stage = "Stage0" + std::to_string(7);

	SelectMap[FINT(6, 6)]->SetAnimation(8, false);
	SelectMap[FINT(6, 6)]->SetActorLocation(FINT(6, 6).GetSelectFINTToVector());
	SelectMap[FINT(6, 6)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(6, 6)]->SelectInfo.Type = ESelectTileType::Stage;
	SelectMap[FINT(6, 6)]->SelectInfo.Stage = "Stage0" + std::to_string(8);

	StaticHelper::CurSelectTileMap = SelectMap;
}

void ASelectTileMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void ASelectTileMap::StageChangeCheck()
{
}
