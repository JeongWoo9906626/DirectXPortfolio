#pragma once
#include "Tile.h"

class AYouNoun : public ATile
{
	GENERATED_BODY(ATile)

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