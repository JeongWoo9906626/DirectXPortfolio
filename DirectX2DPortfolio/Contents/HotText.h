#pragma once
#include "Tile.h"

class AHotText : public ATile
{
	GENERATED_BODY(ATile)

public:
	AHotText();
	~AHotText();

	AHotText(const AHotText& _Other) = delete;
	AHotText(AHotText&& _Other) noexcept = delete;
	AHotText& operator=(const AHotText& _Other) = delete;
	AHotText& operator=(AHotText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};