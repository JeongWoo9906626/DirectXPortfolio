#pragma once
#include "Tile.h"

class AVerbTile : public ATile
{
	GENERATED_BODY(ATile)

public:
	AVerbTile();
	~AVerbTile();

	AVerbTile(const AVerbTile& _Other) = delete;
	AVerbTile(AVerbTile&& _Other) noexcept = delete;
	AVerbTile& operator=(const AVerbTile& _Other) = delete;
	AVerbTile& operator=(AVerbTile&& _Other) noexcept = delete;

	void WordsCheck();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


	bool HorizontalCheck(FINT _TilePos);
	bool VerticalCheck(FINT _TilePos);

	void UnLock();

private:
	ETileType HorizontalLeftType = ETileType::None;
	ETileType VerticalLeftType = ETileType::None;

	bool IsSentence = false;

	bool IsCharNoun = false;
	bool IsNoun = false;
};