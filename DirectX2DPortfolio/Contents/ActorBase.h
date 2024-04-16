#pragma once
#include <stack>
#include "Tile.h"

class AActorBase : public ATile
{
	GENERATED_BODY(ATile)

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
	bool MoveCheck(EActorDir _Dir);
	bool MoveEndCheck(FINT _NextTilePos, EActorDir _Dir);
	bool MoveTileActorCheck(FINT _NextTilePos, EActorDir _Dir);

	virtual void MoveSet(); 
	FVector Lerp(float _CurMoveTime) const;

	inline void SetMoveRange(float _MoveRange)
	{
		MoveRange = _MoveRange;
	}

	inline EActorDir GetCurDir() const
	{
		return CurDir;
	}

	inline bool GetIsBack() const
	{
		return IsBack;
	}

	void SetIsTileMove(bool _IsTileMove, EActorDir _Dir) override
	{
		Super::SetIsTileMove(_IsTileMove, _Dir);
		CurDir = _Dir;
	}

	std::stack<int> AnimationIndexHistory;

private:
	FINT PrevPos = FINT();
	FINT NextPos = FINT();
	EActorDir CurDir = EActorDir::None;

	bool IsMove = false;
	bool IsBack = false;

	float MoveRange = 32.0f;
	float MoveTime = 0.3f;
	float CurMoveTime = 0.0f;

	std::stack<EActorDir> MoveHistory;
};