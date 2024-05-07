#pragma once
#include "Tile.h"

class AConnectingTile : public ATile
{
	GENERATED_BODY(ATile)

public:
	AConnectingTile();
	~AConnectingTile();

	AConnectingTile(const AConnectingTile& _Other) = delete;
	AConnectingTile(AConnectingTile&& _Other) noexcept = delete;
	AConnectingTile& operator=(const AConnectingTile& _Other) = delete;
	AConnectingTile& operator=(AConnectingTile&& _Other) noexcept = delete;

	void WordsCheck();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


	bool HorizontalIsCheck(FINT _TilePos);
	bool VerticalIsCheck(FINT _TilePos);
	
	void HorizontalAndCheck(FINT _TilePos);
	void  VerticalAndCheck(FINT _TilePos);


private:
	ETileType HorizontalCharType = ETileType::None;
	ENounType HorizontalTextType = ENounType::None;

	ETileType VerticalCharType = ETileType::None;
	ENounType VerticalTextType = ENounType::None;
};