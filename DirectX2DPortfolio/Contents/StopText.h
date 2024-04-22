#pragma once
#include "Tile.h"

class AStopText : public ATile
{
	GENERATED_BODY(ATile)

public:
	AStopText();
	~AStopText();

	AStopText(const AStopText& _Other) = delete;
	AStopText(AStopText&& _Other) noexcept = delete;
	AStopText& operator=(const AStopText& _Other) = delete;
	AStopText& operator=(AStopText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};