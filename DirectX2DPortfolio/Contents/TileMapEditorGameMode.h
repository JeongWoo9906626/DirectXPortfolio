#pragma once
#include <EngineCore/GameMode.h>
#include "ContentsStruct.h"
#include "TileMap.h"

class ATileMap;
class ATileMapEditorGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)

public:
	ATileMapEditorGameMode();
	~ATileMapEditorGameMode();

	ATileMapEditorGameMode(const ATileMapEditorGameMode& _Other) = delete;
	ATileMapEditorGameMode(ATileMapEditorGameMode&& _Other) noexcept = delete;
	ATileMapEditorGameMode& operator=(const ATileMapEditorGameMode& _Other) = delete;
	ATileMapEditorGameMode& operator=(ATileMapEditorGameMode&& _Other) noexcept = delete;

	void SpawnTileActor(FINT _TilePos, ESpawnType _Type);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel) override;
	void LevelStart(ULevel* _PrevLevel) override;

private:
};