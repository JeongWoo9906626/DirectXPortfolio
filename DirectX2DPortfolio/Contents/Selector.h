#pragma once
#include "ActorBase.h"

class USpriteRenderer;
class ASelector : public AActorBase
{
	GENERATED_BODY(AActorBase)

public:
	ASelector();
	~ASelector();

	ASelector(const ASelector& _Other) = delete;
	ASelector(ASelector&& _Other) noexcept = delete;
	ASelector& operator=(const ASelector& _Other) = delete;
	ASelector& operator=(ASelector&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	
};