#pragma once
#include <Enginecore/Actor.h>

// Ό³Έν :
class AStageTextInfo : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AStageTextInfo();
	~AStageTextInfo();

	// delete Function
	AStageTextInfo(const AStageTextInfo& _Other) = delete;
	AStageTextInfo(AStageTextInfo&& _Other) noexcept = delete;
	AStageTextInfo& operator=(const AStageTextInfo& _Other) = delete;
	AStageTextInfo& operator=(AStageTextInfo&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	FVector StartPos = FVector(-280, 108);
	FVector AddNext = FVector(60.0f, 0.0f);
	FVector TitleScale = FVector(200, 200);
};

