#pragma once
#include <EngineCore/Actor.h>
#include "ContentsStruct.h"

class USpriteRenderer;
class ATile : public AActor
{
	GENERATED_BODY(AActor)

public:
	ATile();
	~ATile();

	ATile(const ATile& _Other) = delete;
	ATile(ATile&& _Other) noexcept = delete;
	ATile& operator=(const ATile& _Other) = delete;
	ATile& operator=(ATile&& _Other) noexcept = delete;

	inline void SetPosition(FINT _TilePosition)
	{
		TilePosition = _TilePosition;
	}


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* Renderer = nullptr;
	FINT TilePosition = FINT();
	bool CanMove = true;
	float TileSize = 128.0f;

private:
};