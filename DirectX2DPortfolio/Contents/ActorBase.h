#pragma once
#include <EngineCore/Actor.h>
#include <stack>

class USpriteRenderer;
class AActorBase : public AActor
{
	GENERATED_BODY(AActor)

public:
	AActorBase();
	~AActorBase();

	AActorBase(const AActorBase& _Other) = delete;
	AActorBase(AActorBase&& _Other) noexcept = delete;
	AActorBase& operator=(const AActorBase& _Other) = delete;
	AActorBase& operator=(AActorBase&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* Renderer = nullptr;

	virtual void MoveSet(); 
	FVector Lerp(float _CurMoveTime);

	inline void SetMoveRange(float _MoveRange)
	{
		MoveRange = _MoveRange;
	}

	inline EActorDir GetCurDir()
	{
		return CurDir;
	}

private:
	FVector PrevPos = FVector::Zero;
	FVector NextPos = FVector::Zero;
	EActorDir CurDir = EActorDir::None;

	bool IsMove = false;
	bool IsBack = false;
	float MoveRange = 32.0f;
	float MoveTime = 0.3f;
	float CurMoveTime = 0.0f;

	std::stack<EActorDir> MoveHistory;
};