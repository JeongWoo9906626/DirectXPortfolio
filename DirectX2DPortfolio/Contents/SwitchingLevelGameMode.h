#pragma once
#include <EngineCore/GameMode.h>

// Ό³Έν :
class AStageNumberText;
class ASwitchingLevelGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)

public:
	// constrcuter destructer
	ASwitchingLevelGameMode();
	~ASwitchingLevelGameMode();

	// delete Function
	ASwitchingLevelGameMode(const ASwitchingLevelGameMode& _Other) = delete;
	ASwitchingLevelGameMode(ASwitchingLevelGameMode&& _Other) noexcept = delete;
	ASwitchingLevelGameMode& operator=(const ASwitchingLevelGameMode& _Other) = delete;
	ASwitchingLevelGameMode& operator=(ASwitchingLevelGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel) override;
	void LevelStart(ULevel* _PrevLevel) override;


private:
	float ChangeTime = 2.0f;
	float CurChangeTime = 0.0f;
};

