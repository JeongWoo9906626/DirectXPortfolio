#pragma once
#include "Tile.h"

class ANoAnimTile : public ATile
{
	GENERATED_BODY(ATile)

public:
	ANoAnimTile();
	~ANoAnimTile();

	ANoAnimTile(const ANoAnimTile& _Other) = delete;
	ANoAnimTile(ANoAnimTile&& _Other) noexcept = delete;
	ANoAnimTile& operator=(const ANoAnimTile& _Other) = delete;
	ANoAnimTile& operator=(ANoAnimTile&& _Other) noexcept = delete;

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

	ELinkNext PrevLink = ELinkNext::None;
	ELinkNext NextLink = ELinkNext::None;
};