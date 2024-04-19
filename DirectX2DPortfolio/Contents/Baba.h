#pragma once
#include "Tile.h"

class ABaba : public ATile
{
	GENERATED_BODY(ATile)

public:
	ABaba();
	~ABaba();

	ABaba(const ABaba& _Other) = delete;
	ABaba(ABaba&& _Other) noexcept = delete;
	ABaba& operator=(const ABaba& _Other) = delete;
	ABaba& operator=(ABaba&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void MoveSet(EInputType _Input) override;
	void BackMoveSet() override;
	void ChangeMoveAnimation();
	void BackChangeMoveAnimation();

private:
	int AnimationIndex = 1;

	EActorDir PrevDir = EActorDir::None;
	EActorDir NextDir = EActorDir::None;
	EActorDir PlayerDir = EActorDir::None;

	std::stack<int> AnimationIndexHistory;
};