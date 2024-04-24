#pragma once
#include "Tile.h"

class NoAnimTile : public ATile
{
	GENERATED_BODY(ATile)

public:
	NoAnimTile();
	~NoAnimTile();

	NoAnimTile(const NoAnimTile& _Other) = delete;
	NoAnimTile(NoAnimTile&& _Other) noexcept = delete;
	NoAnimTile& operator=(const NoAnimTile& _Other) = delete;
	NoAnimTile& operator=(NoAnimTile&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void NextCheck();
	bool NextTileTypeCheck(FINT _Position);
	void TileAnimationChange();

private:
	bool IsLeft = false;
	bool IsRight = false;
	bool IsTop = false;
	bool IsBottom = false;

	ENoNext PrevNo = ENoNext::None;
	ENoNext NextNo = ENoNext::None;
};