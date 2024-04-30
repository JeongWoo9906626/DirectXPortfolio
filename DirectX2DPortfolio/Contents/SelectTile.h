#pragma once
#include <EngineCore/Actor.h>
#include "ContentsStruct.h"

class SelectTileInfo
{
public:
	bool IsEnter = false;
	bool IsPrevStageClear = false;
	bool IsStageClear = false;
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
	void SetAnimation(int _StageNumber, bool _IsClear);

	SelectTileInfo SelectInfo;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* Renderer = nullptr;

private:

};