#pragma once
#include <Enginecore/Actor.h>

// ���� :
class ATitleLogo : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	ATitleLogo();
	~ATitleLogo();

	// delete Function
	ATitleLogo(const ATitleLogo& _Other) = delete;
	ATitleLogo(ATitleLogo&& _Other) noexcept = delete;
	ATitleLogo& operator=(const ATitleLogo& _Other) = delete;
	ATitleLogo& operator=(ATitleLogo&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	FVector StartPos = FVector(-280, 108);
	FVector AddNext = FVector(60.0f, 0.0f);
	FVector TitleScale = FVector(200, 200);
};

