#pragma once
#include <EngineCore/Actor.h>
#include "ContentsStruct.h"
#include "EnumHelper.h"
#include "StaticHelper.h"

class ATile;
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
	void TileUpdate();
	void TileWinCheck();
	void TileStateReset();
	void TileSentenceCheck();
	void TileAliveCheck();

	bool MoveEnd();
	void DefeatCheck(FINT _TilePosition);
	void SinkCheck(FINT _TilePosition, ETileType _TileType);
	void WinCheck(FINT _TilePosition);

private:
	FINT MapSize = FINT();
	std::map<FINT, std::list<std::shared_ptr<ATile>>> Map;
	EInputType Input = EInputType::None;

	bool IsInput = false;
	bool IsBack = false;
	bool IsTileMove = false;
	bool MoveResult = false;

	bool BeforeResult = false;
	bool GameWin = false;
};

