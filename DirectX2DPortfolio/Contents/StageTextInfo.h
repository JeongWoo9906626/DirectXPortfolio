#pragma once
#include <Enginecore/Actor.h>

// Ό³Έν :
class TextActor;
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
	FVector StartPos = FVector::Zero;
	FVector AddNext = FVector(65.0f, 0.0f);
	FVector TitleScale = FVector(130, 200);

	std::vector<TextActor*> TextVector;
};

