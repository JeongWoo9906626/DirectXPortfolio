#pragma once
#include "Tile.h"

class MapTileText : public ATile
{
	GENERATED_BODY(ATile)

public:
	MapTileText();
	~MapTileText();

	MapTileText(const MapTileText& _Other) = delete;
	MapTileText(MapTileText&& _Other) noexcept = delete;
	MapTileText& operator=(const MapTileText& _Other) = delete;
	MapTileText& operator=(MapTileText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};