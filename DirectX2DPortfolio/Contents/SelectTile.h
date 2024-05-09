#pragma once
#include <EngineCore/Actor.h>
#include "ContentsStruct.h"

class SelectTileInfo
{
public:
	bool IsEnter = false;
	bool IsPrevStageClear = false;
	bool IsStageClear = false;

	ESelectTileType Type = ESelectTileType::None;
	std::string StageText = "";
	std::string Stage = "";
};

class USpriteRenderer;
class ASelectTile : public AActor
{
	GENERATED_BODY(AActor)

public:
	ASelectTile();
	~ASelectTile();

	ASelectTile(const ASelectTile& _Other) = delete;
	ASelectTile(ASelectTile&& _Other) noexcept = delete;
	ASelectTile& operator=(const ASelectTile& _Other) = delete;
	ASelectTile& operator=(ASelectTile&& _Other) noexcept = delete;

	void SettingAnimation();
	void SetAnimation(int _StageNumber, bool _IsClear, FINT _TilePos = FINT(0, 0));
	void ShowOn();

	SelectTileInfo SelectInfo;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* LeftRenderer = nullptr;
	USpriteRenderer* RightRenderer = nullptr;
	USpriteRenderer* LineRenderer = nullptr;

	void NextLineCheck(FINT _TilePos);
	bool NextSelectTileTypeCheck(FINT _Position);
	void LineAnimationChange();

private:
	bool IsLeft = false;
	bool IsRight = false;
	bool IsTop = false;
	bool IsBottom = false;
};