#include "PreCompile.h"
#include "StageSelectGameMode.h"
#include "SelectMap.h"
#include "Selector.h"
#include "TileMap.h"
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

	std::shared_ptr<ASelectMap> SelectMap = GetWorld()->SpawnActor<ASelectMap>("SelectMap");
	std::shared_ptr<ASelector> Selector = GetWorld()->SpawnActor<ASelector>("Selector");
	Selector->SetActorLocation(FVector(0.0f, 0.0f, 200.0f));
	Selector->SetActorScale3D(FVector(36.0f, 36.0f, 20.0f));
}

void AStageSelectGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	/*if (true == UEngineInput::IsDown(VK_SPACE))
	{
		GEngine->ChangeLevel("PlayLevel");
	}*/

	if (true == UEngineInput::IsDown('Q'))
	{
		StaticHelper::StageName = "Stage00";
		GEngine->ChangeLevel("TestLevel");
	}

	if (true == UEngineInput::IsDown('W'))
	{
		StaticHelper::StageName = "Test";
		GEngine->ChangeLevel("TestLevel");
	}
}

void AStageSelectGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void AStageSelectGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

}