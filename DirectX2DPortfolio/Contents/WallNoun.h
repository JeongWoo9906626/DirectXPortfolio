#pragma once
#include "Tile.h"

class AWallNoun : public ATile
{
	GENERATED_BODY(ATile)

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