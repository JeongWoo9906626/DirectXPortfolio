#pragma once
#include "Tile.h"

class AAndText : public ATile
{
	GENERATED_BODY(ATile)

public:
	AAndText();
	~AAndText();

	AAndText(const AAndText& _Other) = delete;
	AAndText(AAndText&& _Other) noexcept = delete;
	AAndText& operator=(const AAndText& _Other) = delete;
	AAndText& operator=(AAndText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};