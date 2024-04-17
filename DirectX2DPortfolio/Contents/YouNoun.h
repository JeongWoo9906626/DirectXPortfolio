#pragma once
#include "ActorBase.h"

class AYouNoun : public AActorBase
{
	GENERATED_BODY(AActorBase)

public:
	AYouNoun();
	~AYouNoun();

	AYouNoun(const AYouNoun& _Other) = delete;
	AYouNoun(AYouNoun&& _Other) noexcept = delete;
	AYouNoun& operator=(const AYouNoun& _Other) = delete;
	AYouNoun& operator=(AYouNoun&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};