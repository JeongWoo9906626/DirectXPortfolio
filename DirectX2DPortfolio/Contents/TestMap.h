#pragma once
#include <EngineCore/Actor.h>
#include "ContentsStruct.h"
#include "Tile.h"

class USpriteRenderer;
class ATestMap : public AActor
{
	GENERATED_BODY(AActor)

public:
	ATestMap();
	~ATestMap();

	ATestMap(const ATestMap& _Other) = delete;
	ATestMap(ATestMap&& _Other) noexcept = delete;
	ATestMap& operator=(const ATestMap& _Other) = delete;
	ATestMap& operator=(ATestMap&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer = nullptr;
	std::map<FINT, std::shared_ptr<ATile>> TilePos;
};