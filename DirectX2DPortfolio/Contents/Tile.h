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

	inline FINT GetTilePosition() const
	{
		return TilePosition;
	}

	virtual bool MoveCheck(EActorDir _Dir) { return false; }


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* Renderer = nullptr;
	FINT TilePosition = FINT();
	bool HasController = false;
	bool CanMove = false;
	float TileSize = 32.0f;

private:
};