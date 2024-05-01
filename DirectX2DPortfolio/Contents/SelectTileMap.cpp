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

	SelectMap[FINT(0, 0)]->SetAnimation(0, false);
	SelectMap[FINT(0, 0)]->SetActorLocation(FINT(0, 0).GetSelectFINTToVector());
	SelectMap[FINT(0, 0)]->SelectInfo.IsEnter = true;
	SelectMap[FINT(0, 0)]->SelectInfo.Stage = "Stage0" + std::to_string(0);

	SelectMap[FINT(0, 1)]->SetAnimation(1, false);
	SelectMap[FINT(0, 1)]->SetActorLocation(FINT(0, 1).GetSelectFINTToVector());
	SelectMap[FINT(0, 1)]->SelectInfo.IsEnter = true;
	SelectMap[FINT(0, 1)]->SelectInfo.Stage = "Stage0" + std::to_string(1);
	
	SelectMap[FINT(1, 0)]->SetAnimation(2, false);
	SelectMap[FINT(1, 0)]->SetActorLocation(FINT(1, 0).GetSelectFINTToVector());
	SelectMap[FINT(1, 0)]->SelectInfo.IsEnter = true;
	SelectMap[FINT(1, 0)]->SelectInfo.Stage = "Stage0" + std::to_string(2);
	
	SelectMap[FINT(1, 1)]->SetAnimation(3, false);
	SelectMap[FINT(1, 1)]->SetActorLocation(FINT(1, 1).GetSelectFINTToVector());
	SelectMap[FINT(1, 1)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(1, 1)]->SelectInfo.Stage = "Stage0" + std::to_string(3);

	SelectMap[FINT(2, 0)]->SetAnimation(4, false);
	SelectMap[FINT(2, 0)]->SetActorLocation(FINT(2, 0).GetSelectFINTToVector());
	SelectMap[FINT(2, 0)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(2, 0)]->SelectInfo.Stage = "Stage0" + std::to_string(4);
	
	SelectMap[FINT(2, 1)]->SetAnimation(5, false);
	SelectMap[FINT(2, 1)]->SetActorLocation(FINT(2, 1).GetSelectFINTToVector());
	SelectMap[FINT(2, 1)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(2, 1)]->SelectInfo.Stage = "Stage0" + std::to_string(5);

	SelectMap[FINT(2, 2)]->SetAnimation(6, false);
	SelectMap[FINT(2, 2)]->SetActorLocation(FINT(2, 2).GetSelectFINTToVector());
	SelectMap[FINT(2, 2)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(2, 2)]->SelectInfo.Stage = "Stage0" + std::to_string(6);

	SelectMap[FINT(1, 2)]->SetAnimation(7, false);
	SelectMap[FINT(1, 2)]->SetActorLocation(FINT(1, 2).GetSelectFINTToVector());
	SelectMap[FINT(1, 2)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(1, 2)]->SelectInfo.Stage = "Stage0" + std::to_string(7);

	SelectMap[FINT(0, 2)]->SetAnimation(8, false);
	SelectMap[FINT(0, 2)]->SetActorLocation(FINT(0, 2).GetSelectFINTToVector());
	SelectMap[FINT(0, 2)]->SelectInfo.IsEnter = false;
	SelectMap[FINT(0, 2)]->SelectInfo.Stage = "Stage0" + std::to_string(8);

	StaticHelper::CurSelectTileMap = SelectMap;
}

void ASelectTileMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void ASelectTileMap::StageChangeCheck()
{
}
