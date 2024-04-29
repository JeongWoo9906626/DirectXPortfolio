#pragma once
#include <EngineCore/Actor.h>

// ∏ ¿« µﬁ πË∞Ê
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

	//void TileUpdate();

private:
	USpriteRenderer* Renderer = nullptr;
	
};