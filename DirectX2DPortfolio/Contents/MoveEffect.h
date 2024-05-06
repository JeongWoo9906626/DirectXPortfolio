#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;
class AMoveEffect : public AActor
{
	GENERATED_BODY(AActor)

public:
	AMoveEffect();
	~AMoveEffect();

	AMoveEffect(const AMoveEffect& _Other) = delete;
	AMoveEffect(AMoveEffect&& _Other) noexcept = delete;
	AMoveEffect& operator=(const AMoveEffect& _Other) = delete;
	AMoveEffect& operator=(AMoveEffect&& _Other) noexcept = delete;

	void SetInput(EInputType _Input)
	{
		Input = _Input;	
	}

	void SetColorByTile(float4 _MulColor);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void PositionSetting();
	void MoveEffectOn(float _CurMoveTime);

private:
	USpriteRenderer* Renderer = nullptr;
	
	bool IsSetting = false;
	float EffectTime = 0.2f;
	float CurEffectTime = 0.0f;
	FVector MediatePos = FVector::Zero;

	EInputType Input = EInputType::None;
	FVector CurPos = FVector::Zero;
	FVector NextPos = FVector::Zero;
	FVector Scale = FVector::Zero;
};