#pragma once
#include "Tile.h"

class AYouText : public ATile
{
	GENERATED_BODY(ATile)

public:
	AYouText();
	~AYouText();

	AYouText(const AYouText& _Other) = delete;
	AYouText(AYouText&& _Other) noexcept = delete;
	AYouText& operator=(const AYouText& _Other) = delete;
	AYouText& operator=(AYouText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};