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
	
	SetSelectTileMapSize(FINT(13, 10));
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
		StaticHelper::StageName = StaticHelper::CurSelectTileMap[MapPosition]->SelectInfo.Stage;
		GEngine->ChangeLevel("TestLevel");
		StaticHelper::IsStageChange = false;
	}

	/*if (true == UEngineInput::IsDown(VK_SPACE))
	{
		GEngine->ChangeLevel("PlayLevel");
	}*/

	/*if (true == UEngineInput::IsDown('Q'))
	{
		StaticHelper::StageName = "Stage00";
		GEngine->ChangeLevel("TestLevel");
	}

	if (true == UEngineInput::IsDown('E'))
	{
		StaticHelper::StageName = "Test";
		GEngine->ChangeLevel("TestLevel");
	}*/
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

std::string AStageSelectGameMode::FINTToStageName(FINT _MapPosition)
{
	return std::string();
}
