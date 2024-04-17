#pragma once
#include "ActorBase.h"

class AWallNoun : public AActorBase
{
	GENERATED_BODY(AActorBase)

public:
	AWallNoun();
	~AWallNoun();

	AWallNoun(const AWallNoun& _Other) = delete;
	AWallNoun(AWallNoun&& _Other) noexcept = delete;
	AWallNoun& operator=(const AWallNoun& _Other) = delete;
	AWallNoun& operator=(AWallNoun&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};