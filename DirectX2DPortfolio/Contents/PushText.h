#pragma once
#include "Tile.h"

class APushText : public ATile
{
	GENERATED_BODY(ATile)

public:
	APushText();
	~APushText();

	APushText(const APushText& _Other) = delete;
	APushText(APushText&& _Other) noexcept = delete;
	APushText& operator=(const APushText& _Other) = delete;
	APushText& operator=(APushText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};