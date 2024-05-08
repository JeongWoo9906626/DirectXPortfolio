#include "PreCompile.h"
#include "StageSelectGameMode.h"
#include "SelectMap.h"
#include "Selector.h"
#include "TileMap.h"
#include "SelectTileMap.h"
#include "SelectTile.h"
#include <EngineCore/Camera.h>

AStageSelectGameMode::AStageSelectGameMode()
{
	InputOn();
}

AStageSelectGameMode::~AStageSelectGameMode()
{

}

void AStageSelectGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	std::shared_ptr<ASelectMap>SelectMap = GetWorld()->SpawnActor<ASelectMap>("SelectMap");
	SelectMap->SetActorScale3D(FVector(1280.f * 1.5f, 720.f * 1.5f));

	SetSelectTileMapSize(FINT(16, 14));
	SelectTileMap = GetWorld()->SpawnActor<ASelectTileMap>("SelectTileMap").get();

	Selector = GetWorld()->SpawnActor<ASelector>("Selector").get();
	Selector->AddActorLocation(FVector(0.0f, 7.0f, 0.0f));
	Selector->SetActorScale3D(FVector(36.0f, 36.0f, 20.0f));
}

void AStageSelectGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == StaticHelper::IsStageChange)
	{
		FINT MapPosition = Selector->GetTilePosition();
		//StaticHelper::StageName = "Tests08";
		StaticHelper::StageName = StaticHelper::CurSelectTileMap[MapPosition]->SelectInfo.Stage;
		GEngine->ChangeLevel("TestLevel");
		StaticHelper::IsStageChange = false;
	}

	StageTileMapUpdate(_DeltaTime);
}

void AStageSelectGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void AStageSelectGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

}

void AStageSelectGameMode::SetSelectTileMapSize(FINT _SelectTileMapSize)
{
	FINT::SelectMapSize = _SelectTileMapSize;
}

void AStageSelectGameMode::StageTileMapUpdate(float _DeltaTime)
{
	FINT::SelectMapSize;
	StaticHelper::CurSelectTileMap;

	for (int X = 0; X < FINT::SelectMapSize.X; X++)
	{
		for (int Y = 0; Y < FINT::SelectMapSize.Y; Y++)
		{
			FINT Current = FINT(X, Y);
			FINT Up = Current + FINT(0, 1);
			FINT Right = Current + FINT(1, 0);

			ASelectTile* CurCheck = StaticHelper::CurSelectTileMap[Current];
			std::string StageName = CurCheck->SelectInfo.Stage;
			if (true == CurCheck->SelectInfo.IsStageClear)
			{
				if (ESelectTileType::Stage == CurCheck->SelectInfo.Type)
				{
					int StageNumber = stoi(StageName.substr(6, 1));
					CurCheck->SetAnimation(StageNumber, CurCheck->SelectInfo.IsStageClear);
				}
				if (CurStageOpenTime >= StageOpenTime)
				{
					if (ESelectTileType::Walk == StaticHelper::CurSelectTileMap[Up]->SelectInfo.Type)
					{
						if (Up.Y < FINT::SelectMapSize.Y)
						{
							ASelectTile* UpCheck = StaticHelper::CurSelectTileMap[Up];
							UpCheck->SelectInfo.IsEnter = true;
							UpCheck->SelectInfo.IsStageClear = true;
							UpCheck->ShowOn();
						}
					}
					if (ESelectTileType::Walk == StaticHelper::CurSelectTileMap[Right]->SelectInfo.Type)
					{
						if (Right.X < FINT::SelectMapSize.X)
						{
							ASelectTile* RightCheck = StaticHelper::CurSelectTileMap[Right];
							RightCheck->SelectInfo.IsEnter = true;
							RightCheck->SelectInfo.IsStageClear = true;
							RightCheck->ShowOn();
						}
					}

					if (ESelectTileType::Stage == StaticHelper::CurSelectTileMap[Up]->SelectInfo.Type)
					{
						if (Up.Y < FINT::SelectMapSize.Y)
						{
							ASelectTile* UpCheck = StaticHelper::CurSelectTileMap[Up];
							UpCheck->SelectInfo.IsEnter = true;
							UpCheck->ShowOn();
						}
					}
					if (ESelectTileType::Stage == StaticHelper::CurSelectTileMap[Right]->SelectInfo.Type)
					{
						if (Right.X < FINT::SelectMapSize.X)
						{
							ASelectTile* RightCheck = StaticHelper::CurSelectTileMap[Right];
							RightCheck->SelectInfo.IsEnter = true;
							RightCheck->ShowOn();
						}
					}
					CurStageOpenTime = 0.0f;
				}
				CurStageOpenTime += _DeltaTime;
			}
		}
	}
}

