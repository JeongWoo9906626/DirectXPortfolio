#pragma once
#include <EngineCore/Actor.h>
#include "ContentsStruct.h"


class ASelectTile;
class ASelectTileMap : public AActor
{
	GENERATED_BODY(AActor)

public:
	ASelectTileMap();
	~ASelectTileMap();

	ASelectTileMap(const ASelectTileMap& _Other) = delete;
	ASelectTileMap(ASelectTileMap&& _Other) noexcept = delete;
	ASelectTileMap& operator=(const ASelectTileMap& _Other) = delete;
	ASelectTileMap& operator=(ASelectTileMap&& _Other) noexcept = delete;

	//static std::map<FINT, ASelectTile*> SelectMap;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void StageChangeCheck();

private:
};