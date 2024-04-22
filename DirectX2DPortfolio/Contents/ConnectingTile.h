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


	bool HorizontalCheck(FINT _TilePos);
	bool VerticalCheck(FINT _TilePos);

private:
	ETileType HorizontalLeftType = ETileType::None;
	ETileType VerticalLeftType = ETileType::None;

	bool IsSentence = false;

	bool IsCharNoun = false;
	bool IsNoun = false;
};