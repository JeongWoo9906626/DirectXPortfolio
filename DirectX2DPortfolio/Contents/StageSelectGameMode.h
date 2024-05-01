#pragma once
#include <EngineCore/GameMode.h>

class ASelector;
class ASelectTileMap;
class AStageSelectGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)

public:
	AStageSelectGameMode();
	~AStageSelectGameMode();

	AStageSelectGameMode(const AStageSelectGameMode& _Other) = delete;
	AStageSelectGameMode(AStageSelectGameMode&& _Other) noexcept = delete;
	AStageSelectGameMode& operator=(const AStageSelectGameMode& _Other) = delete;
	AStageSelectGameMode& operator=(AStageSelectGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel) override;
	void LevelStart(ULevel* _PrevLevel) override;

	void SetSelectTileMapSize(FINT _SelectTileMapSize);
	void StageTileMapUpdate();

private:
	ASelectTileMap* SelectTileMap = nullptr;
	ASelector* Selector = nullptr;
};