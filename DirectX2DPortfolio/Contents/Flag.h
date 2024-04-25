#pragma once
#include "Tile.h"

class AFlag : public ATile
{
	GENERATED_BODY(ATile)

public:
	AFlag();
	~AFlag();

	AFlag(const AFlag& _Other) = delete;
	AFlag(AFlag&& _Other) noexcept = delete;
	AFlag& operator=(const AFlag& _Other) = delete;
	AFlag& operator=(AFlag&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};