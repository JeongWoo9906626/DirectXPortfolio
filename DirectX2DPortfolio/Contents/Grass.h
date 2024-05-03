#pragma once
#include "NoAnimTile.h"

class AGrass : public ANoAnimTile
{
	GENERATED_BODY(ANoAnimTile)

public:
	AGrass();
	~AGrass();

	AGrass(const AGrass& _Other) = delete;
	AGrass(AGrass&& _Other) noexcept = delete;
	AGrass& operator=(const AGrass& _Other) = delete;
	AGrass& operator=(AGrass&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DetaTime) override;

private:

};