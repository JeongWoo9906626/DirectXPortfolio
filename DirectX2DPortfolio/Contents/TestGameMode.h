#pragma once
#include <EngineCore/GameMode.h>
#include "ContentsStruct.h"

class ATile;
class ATestGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)

public:
	ATestGameMode();
	~ATestGameMode();

	ATestGameMode(const ATestGameMode& _Other) = delete;
	ATestGameMode(ATestGameMode&& _Other) noexcept = delete;
	ATestGameMode& operator=(const ATestGameMode& _Other) = delete;
	ATestGameMode& operator=(ATestGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel) override;
	void LevelStart(ULevel* _PrevLevel) override;

	void TileUpdate();

private:
	std::map<FINT, std::shared_ptr<ATile>> TileMap;

};