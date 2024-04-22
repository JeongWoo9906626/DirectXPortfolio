#pragma once
#include "Tile.h"

class DefeatText : public ATile
{
	GENERATED_BODY(ATile)

public:
	DefeatText();
	~DefeatText();

	DefeatText(const DefeatText& _Other) = delete;
	DefeatText(DefeatText&& _Other) noexcept = delete;
	DefeatText& operator=(const DefeatText& _Other) = delete;
	DefeatText& operator=(DefeatText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};