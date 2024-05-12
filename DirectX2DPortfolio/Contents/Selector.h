#pragma once
#include <EngineCore/Actor.h>

class ASelector : public AActor
{
	GENERATED_BODY(AActor)

public:
	ASelector();
	~ASelector();

	ASelector(const ASelector& _Other) = delete;
	ASelector(ASelector&& _Other) noexcept = delete;
	ASelector& operator=(const ASelector& _Other) = delete;
	ASelector& operator=(ASelector&& _Other) noexcept = delete;

	FINT GetTilePosition()
	{
		return TilePosition;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void InputCheck();
	void MoveCheck();

	FVector Lerp(float _CurMoveTime);
	USpriteRenderer* Renderer = nullptr;
	
private:
	UEngineSoundPlayer Sound;
	bool IsSound = false;

	bool IsInput = false;
	bool IsMove = false;
	FINT PrevPos = FINT();
	FINT NextPos = FINT();

	float CurMoveTime = 0.0f;
	float MoveTime = 0.3f;

	EInputType Input = EInputType::None;
	FINT TilePosition = FINT();
};