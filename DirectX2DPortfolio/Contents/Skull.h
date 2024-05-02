#pragma once
#include "Tile.h"

class ASkull : public ATile
{
	GENERATED_BODY(ATile)

public:
	ASkull();
	~ASkull();

	ASkull(const ASkull& _Other) = delete;
	ASkull(ASkull&& _Other) noexcept = delete;
	ASkull& operator=(const ASkull& _Other) = delete;
	ASkull& operator=(ASkull&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};