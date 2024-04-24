#pragma once
#include "Tile.h"

class AWaterText : public ATile
{
	GENERATED_BODY(ATile)

public:
	AWaterText();
	~AWaterText();

	AWaterText(const AWaterText& _Other) = delete;
	AWaterText(AWaterText&& _Other) noexcept = delete;
	AWaterText& operator=(const AWaterText& _Other) = delete;
	AWaterText& operator=(AWaterText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};