#include "PreCompile.h"
#include "StageSelectGameMode.h"
#include "SelectMap.h"
#include "Selector.h"
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

	std::shared_ptr<ASelector> Selector = GetWorld()->SpawnActor<ASelector>("Selector");
	Selector->SetHasController(true);

	std::shared_ptr<ASelectMap> SelectMap = GetWorld()->SpawnActor<ASelectMap>("SelectMap");
}

void AStageSelectGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown(VK_SPACE))
	{
		GEngine->ChangeLevel("PlayLevel");
	}

	if (true == UEngineInput::IsDown('O'))
	{
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