#pragma once
#include <Enginecore/Actor.h>

// ���� :
class AStageNumberText : public AActor
{
	GENERATED_BODY(AActor)

public:
	// constrcuter destructer
	AStageNumberText();
	~AStageNumberText();

	// delete Function
	AStageNumberText(const AStageNumberText& _Other) = delete;
	AStageNumberText(AStageNumberText&& _Other) noexcept = delete;
	AStageNumberText& operator=(const AStageNumberText& _Other) = delete;
	AStageNumberText& operator=(AStageNumberText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	FVector StartPos = FVector(-280, 108);
	FVector AddNext = FVector(60.0f, 0.0f);
	FVector TitleScale = FVector(200, 200);
};

