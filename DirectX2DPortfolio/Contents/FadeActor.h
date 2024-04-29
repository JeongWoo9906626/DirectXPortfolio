#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;
class AFadeActor : public AActor
{
	GENERATED_BODY(AActor)

public:
	AFadeActor();
	~AFadeActor();

	AFadeActor(const AFadeActor& _Other) = delete;
	AFadeActor(AFadeActor&& _Other) noexcept = delete;
	AFadeActor& operator=(const AFadeActor& _Other) = delete;
	AFadeActor& operator=(AFadeActor&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* Renderer;

private:

};