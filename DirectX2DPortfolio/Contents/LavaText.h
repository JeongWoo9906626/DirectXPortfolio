#pragma once
#include "Tile.h"

class ALavaText : public ATile
{
	GENERATED_BODY(ATile)

public:
	ALavaText();
	~ALavaText();

	ALavaText(const ALavaText& _Other) = delete;
	ALavaText(ALavaText&& _Other) noexcept = delete;
	ALavaText& operator=(const ALavaText& _Other) = delete;
	ALavaText& operator=(ALavaText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};