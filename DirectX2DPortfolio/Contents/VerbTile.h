#pragma once
#include "ActorBase.h"

class AVerbTile : public AActorBase
{
	GENERATED_BODY(AActorBase)

public:
	AVerbTile();
	~AVerbTile();

	AVerbTile(const AVerbTile& _Other) = delete;
	AVerbTile(AVerbTile&& _Other) noexcept = delete;
	AVerbTile& operator=(const AVerbTile& _Other) = delete;
	AVerbTile& operator=(AVerbTile&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void WordsCheck();

	bool HorizontalCheck(FINT _TilePos);
	bool VerticalCheck(FINT _TilePos);

	void UnLock();

private:
	EActorType HorizontalLeftType = EActorType::None;
	EActorType VerticalLeftType = EActorType::None;

	bool IsSentence = false;

	bool IsCharNoun = false;
	bool IsNoun = false;
};