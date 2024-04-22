#pragma once
#include "Tile.h"

class AndText : public ATile
{
	GENERATED_BODY(ATile)

public:
	AndText();
	~AndText();

	AndText(const AndText& _Other) = delete;
	AndText(AndText&& _Other) noexcept = delete;
	AndText& operator=(const AndText& _Other) = delete;
	AndText& operator=(AndText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};