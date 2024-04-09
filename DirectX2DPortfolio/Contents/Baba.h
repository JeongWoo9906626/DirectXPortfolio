#pragma once
#include "ActorBase.h"

class ABaba : public AActorBase
{
	GENERATED_BODY(AActorBase)

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

	void MoveSet() override;
	void ChangeMoveAnimation();

private:
	float4 Color;

	int AnimationIndex;

	EActorDir PrevDir = EActorDir::None;
	EActorDir NextDir = EActorDir::None;
	EActorDir PlayerDir = EActorDir::None;
};