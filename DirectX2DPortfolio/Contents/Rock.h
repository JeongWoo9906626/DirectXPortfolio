#pragma once
#include "Tile.h"

class ARock : public ATile
{
	GENERATED_BODY(ATile)

public:
	ARock();
	~ARock();

	ARock(const ARock& _Other) = delete;
	ARock(ARock&& _Other) noexcept = delete;
	ARock& operator=(const ARock& _Other) = delete;
	ARock& operator=(ARock&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};