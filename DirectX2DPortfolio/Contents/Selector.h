#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;
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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer = nullptr;
	float4 Color;
};