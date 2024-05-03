#pragma once
#include "Tile.h"

class AMapTile : public ATile
{
	GENERATED_BODY(ATile)

public:
	AMapTile();
	~AMapTile();

	AMapTile(const AMapTile& _Other) = delete;
	AMapTile(AMapTile&& _Other) noexcept = delete;
	AMapTile& operator=(const AMapTile& _Other) = delete;
	AMapTile& operator=(AMapTile&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};