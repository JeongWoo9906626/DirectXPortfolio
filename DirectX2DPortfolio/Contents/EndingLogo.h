#pragma once
#include <Enginecore/Actor.h>

// Ό³Έν :
class AEndingLogo : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AEndingLogo();
	~AEndingLogo();

	// delete Function
	AEndingLogo(const AEndingLogo& _Other) = delete;
	AEndingLogo(AEndingLogo&& _Other) noexcept = delete;
	AEndingLogo& operator=(const AEndingLogo& _Other) = delete;
	AEndingLogo& operator=(AEndingLogo&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	FVector StartPos = FVector(-280, 108);
	FVector AddNext = FVector(60.0f, 0.0f);
	FVector TitleScale = FVector(200, 200);
};

