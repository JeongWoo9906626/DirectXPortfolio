#pragma once
#include "Tile.h"

class AGrassText : public ATile
{
	GENERATED_BODY(ATile) 

public:
	AGrassText();
	~AGrassText();

	AGrassText(const AGrassText& _Other) = delete;
	AGrassText(AGrassText&& _Other) noexcept = delete;
	AGrassText& operator=(const AGrassText& _Other) = delete;
	AGrassText& operator=(AGrassText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};