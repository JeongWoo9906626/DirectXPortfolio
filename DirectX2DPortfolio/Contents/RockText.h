#pragma once
#include "Tile.h"

class ARockText : public ATile
{
	GENERATED_BODY(ATile)

public:
	ARockText();
	~ARockText();

	ARockText(const ARockText& _Other) = delete;
	ARockText(ARockText&& _Other) noexcept = delete;
	ARockText& operator=(const ARockText& _Other) = delete;
	ARockText& operator=(ARockText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};