#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;
class ASelectMap : public AActor
{
	GENERATED_BODY(AActor)

public:
	ASelectMap();
	~ASelectMap();

	ASelectMap(const ASelectMap& _Other) = delete;
	ASelectMap(ASelectMap&& _Other) noexcept = delete;
	ASelectMap& operator=(const ASelectMap& _Other) = delete;
	ASelectMap& operator=(ASelectMap&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	USpriteRenderer* Renderer = nullptr;
};