#pragma once
#include <EngineCore/Actor.h>
#include "ContentsStruct.h"
#include "EnumHelper.h"
#include "StaticHelper.h"

class ATile;
class UFadeOutEffect;
class AInfoText;
class ATileMap : public AActor
{
	GENERATED_BODY(AActor)

public:
	ATileMap();
	~ATileMap();

	ATileMap(const ATileMap& _Other) = delete;
	ATileMap(ATileMap&& _Other) noexcept = delete;
	ATileMap& operator=(const ATileMap& _Other) = delete;
	ATileMap& operator=(ATileMap&& _Other) noexcept = delete;

	inline void SetTileSize(FINT _MapSize)
	{
		MapSize = _MapSize;
		FINT::MapSize = MapSize;
	}


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void TileInputCheck();
	void TileMoveCheck();
	void TileMoveSet();
	void TileWinCheck();
	void TileStateReset();
	void TileSentenceCheck();
	void TileAliveCheck();

	bool MoveEnd();
	void DefeatCheck(FINT _TilePosition);
	void SinkCheck(FINT _TilePosition, ETileType _TileType);
	void HotCheck(FINT _TilePosition);
	void WinCheck(FINT _TilePosition);

	bool ControllerCheck();

private:
	UEngineSoundPlayer BGM;
	UEngineSoundPlayer DeadBGM;
	UEngineSoundPlayer Sound;
	UEngineSoundPlayer StateSound;

	FINT MapSize = FINT();
	EInputType Input = EInputType::None;

	bool IsInput = false;
	bool IsBack = false;
	bool IsTileMove = false;
	bool MoveResult = false;

	bool BeforeResult = false;
	bool GameWin = false;
	bool IsSoundOn = false;
	
	float CurEndEffectTime = 0.0f;
	float EndEffectTime = 2.0f;

	float CurInfoTextTime = 0.0f;
	float InfoTextTime = 1.0f;

	bool AnimationEnd = false;
	bool AnimationEndInit = false;
	std::shared_ptr<UFadeOutEffect> FadeOut;
	std::shared_ptr<AInfoText> StageText;

	bool IsBGMFirst = false;
	bool IsBGMOff = false;
	bool IsBGMOn = false;
};

