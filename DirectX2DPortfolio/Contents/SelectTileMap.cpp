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

	for (int X = 0; X < 20; X++)
	{
		for (int Y = 0; Y < 12; Y++)
		{
			FINT SelectPosition = FINT(X, Y);
			SelectMap[SelectPosition] = GetWorld()->SpawnActor<ASelectTile>("SelectTile").get();
		}
	}

	SelectMap[FINT(0, 0)]->SetAnimation(0, false);
	/*SelectMap[FINT(0, 1)]->SetAnimation(1, false);
	SelectMap[FINT(1, 0)]->SetAnimation(2, false);
	SelectMap[FINT(1, 1)]->SetAnimation(3, false);
	SelectMap[FINT(2, 0)]->SetAnimation(4, false);
	SelectMap[FINT(2, 1)]->SetAnimation(5, false);
	SelectMap[FINT(2, 2)]->SetAnimation(6, false);
	SelectMap[FINT(1, 2)]->SetAnimation(7, false);
	SelectMap[FINT(0, 2)]->SetAnimation(8, false);*/
	
	StaticHelper::CurSelectTileMap = SelectMap;
}

void ASelectTileMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void ASelectTileMap::StageChangeCheck()
{
}
