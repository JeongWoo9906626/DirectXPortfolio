#pragma once
#include "Tile.h"

class AWallText : public ATile
{
	GENERATED_BODY(ATile)

public:
	AWallText();
	~AWallText();

	AWallText(const AWallText& _Other) = delete;
	AWallText(AWallText&& _Other) noexcept = delete;
	AWallText& operator=(const AWallText& _Other) = delete;
	AWallText& operator=(AWallText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};