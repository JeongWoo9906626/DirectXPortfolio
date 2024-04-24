#pragma once
#include "NoAnimTile.h"

class ALava : public ANoAnimTile
{
	GENERATED_BODY(ANoAnimTile)

public:
	ALava();
	~ALava();

	ALava(const ALava& _Other) = delete;
	ALava(ALava&& _Other) noexcept = delete;
	ALava& operator=(const ALava& _Other) = delete;
	ALava& operator=(ALava&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DetaTime) override;

private:

};