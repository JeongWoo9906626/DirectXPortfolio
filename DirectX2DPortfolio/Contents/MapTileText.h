#pragma once
#include "Tile.h"

class AMapTileText : public ATile
{
	GENERATED_BODY(ATile)

public:
	AMapTileText();
	~AMapTileText();

	AMapTileText(const AMapTileText& _Other) = delete;
	AMapTileText(AMapTileText&& _Other) noexcept = delete;
	AMapTileText& operator=(const AMapTileText& _Other) = delete;
	AMapTileText& operator=(AMapTileText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};