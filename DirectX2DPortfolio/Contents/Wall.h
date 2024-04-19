#pragma once
#include "Tile.h"

class AWall : public ATile
{
	GENERATED_BODY(ATile)

public:
	AWall();
	~AWall();

	AWall(const AWall& _Other) = delete;
	AWall(AWall&& _Other) noexcept = delete;
	AWall& operator=(const AWall& _Other) = delete;
	AWall& operator=(AWall&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};