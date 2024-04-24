#pragma once
#include "NoAnimTile.h"

class AWater : public ANoAnimTile
{
	GENERATED_BODY(ANoAnimTile)

public:
	AWater();
	~AWater();

	AWater(const AWater& _Other) = delete;
	AWater(AWater&& _Other) noexcept = delete;
	AWater& operator=(const AWater& _Other) = delete;
	AWater& operator=(AWater&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DetaTime) override;

private:

};