#pragma once
#include "ActorBase.h"

class AWall : public AActorBase
{
	GENERATED_BODY(AActorBase)

public:
	AWall();
	~AWall();

	AWall(const AWall& _Other) = delete;
	AWall(AWall&& _Other) noexcept = delete;
	AWall& operator=(const AWall& _Other) = delete;
	AWall& operator=(AWall&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};