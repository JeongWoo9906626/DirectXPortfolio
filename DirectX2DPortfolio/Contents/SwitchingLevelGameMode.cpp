#include "PreCompile.h"
#include "SwitchingLevelGameMode.h"
#include <EngineCore/Camera.h>
#include "StageTextInfo.h"
#include "StageNumberText.h"

ASwitchingLevelGameMode::ASwitchingLevelGameMode()
{
}

ASwitchingLevelGameMode::~ASwitchingLevelGameMode()
{
}

void ASwitchingLevelGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	std::shared_ptr<AStageNumberText> StageNumberText = GetWorld()->SpawnActor<AStageNumberText>("StageNumberText");
	std::shared_ptr<AStageTextInfo> StageTextInfo = GetWorld()->SpawnActor<AStageTextInfo>("StageTextInfo");
}

void ASwitchingLevelGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (CurChangeTime >= ChangeTime)
	{
		StaticHelper::IsStageNumberChange = false;
		StaticHelper::IsNumberDestroy = true;
		CurChangeTime = 0.0f;
		GEngine->ChangeLevel("TestLevel");
	}
	else
	{
		CurChangeTime += _DeltaTime;
		if (true == UEngineInput::IsDown(VK_SPACE))
		{
			StaticHelper::IsStageNumberChange = false;
			StaticHelper::IsNumberDestroy = true;
			CurChangeTime = 0.0f;
			GEngine->ChangeLevel("TestLevel");
		}
	}
}

void ASwitchingLevelGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
	
}

void ASwitchingLevelGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}