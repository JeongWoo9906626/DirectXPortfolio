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


	void HorizontalIsCheck(FINT _TilePos);
	void VerticalIsCheck(FINT _TilePos);
	
	void HorizontalAndCheck(FINT _TilePos, ETileType _TileType, ENounType _TextType);
	void VerticalAndCheck(FINT _TilePos, ETileType _TileType, ENounType _TextType);
	//void HorizontalAndCheck(FINT _TilePos);
	//void  VerticalAndCheck(FINT _TilePos);


private:
};