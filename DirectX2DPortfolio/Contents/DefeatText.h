#pragma once
#include "Tile.h"

class ADefeatText : public ATile
{
	GENERATED_BODY(ATile)

public:
	ADefeatText();
	~ADefeatText();

	ADefeatText(const ADefeatText& _Other) = delete;
	ADefeatText(ADefeatText&& _Other) noexcept = delete;
	ADefeatText& operator=(const ADefeatText& _Other) = delete;
	ADefeatText& operator=(ADefeatText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};