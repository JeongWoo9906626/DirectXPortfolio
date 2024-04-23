#pragma once
#include <EngineCore/Actor.h>
#include "ContentsStruct.h"
#include <stack>

class UTileInfo
{
public:
	UTileInfo& operator=(const UTileInfo& _Other)
	{
		TilePosition = _Other.TilePosition;

		IsPush = _Other.IsPush;
		IsBlock = _Other.IsBlock;
		IsController = _Other.IsController;
		IsAlive = _Other.IsAlive;
		IsSink = _Other.IsSink;
		IsDefeat = _Other.IsDefeat;

		TileType = _Other.TileType;
		NounType = _Other.NounType;

		return *this;
	}

public:
	FINT TilePosition = FINT();

	bool IsPush = false;
	bool IsBlock = false;
	bool IsController = false;
	bool IsSink = false;
	bool IsDefeat = false;
	bool IsAlive = true;

	ETileType TileType = ETileType::None;
	ENounType NounType = ENounType::None;
};

class USpriteRenderer;
class ATile : public AActor
{
	GENERATED_BODY(AActor)

public:
	ATile();
	~ATile();

	ATile(const ATile& _Other) = delete;
	ATile(ATile&& _Other) noexcept = delete;
	ATile& operator=(const ATile& _Other) = delete;
	ATile& operator=(ATile&& _Other) noexcept = delete;

	// Get TileInfo
	inline UTileInfo GetTileInfo() const
	{
		return Info;
	}

	// Get/Set TilePosition
	inline void SetTilePosition(FINT _TilePosition)
	{
		Info.TilePosition = _TilePosition;
	}
	inline FINT GetTilePosition() const
	{
		return Info.TilePosition;
	}

	// Get/Set NounType
	inline void SetNounType(ENounType _NounType)
	{
		Info.NounType = _NounType;
	}
	inline ENounType GetNounType() const
	{
		return Info.NounType;
	}

	/*inline void SetPosition(FINT _TilePosition)
	{
		Info.TilePosition = _TilePosition;
	}*/

	// Get/Set IsPush
	inline bool GetIsPush() const
	{
		return Info.IsPush;
	}
	inline void SetIsPush(bool _IsPush)
	{
		Info.IsPush = _IsPush;
	}

	// Get/Set IsConroller
	inline bool GetIsController() const
	{
		return Info.IsController;
	}
	inline void SetIsController(bool _IsController)
	{
		Info.IsController = _IsController;
	}

	// Get/Set IsBlock
	void SetIsBlock(bool _IsBlock)
	{
		Info.IsBlock = _IsBlock;
	}
	bool GetIsBlock() const
	{
		return Info.IsBlock;
	}

	// Get/Set IsSink
	void SetIsSink(bool _IsSink)
	{
		Info.IsSink = _IsSink;
	}
	bool GetIsSink() const
	{
		return Info.IsSink;
	}

	// Get/Set IsDefeat
	void SetIsDefeat(bool _IsDefeat)
	{
		Info.IsDefeat = _IsDefeat;
	}
	bool GetIsDefeat() const
	{
		return Info.IsDefeat;
	}


	void SetTileLocation()
	{
		FVector StartPos = Info.TilePosition.GetFINTToVector();
		this->SetActorLocation(StartPos);
	}

	// Get/Set ActorType
	void SetActorType(ETileType _TileType)
	{
		Info.TileType = _TileType;
	}
	ETileType GetActorType() const
	{
		return Info.TileType;
	}

	std::stack<EActorDir> GetMoveHistory() const
	{
		return MoveHistory;
	}

	void SetFirstStateInfo(const UTileInfo _Other)
	{
		FirstStateInfo = _Other;
	}
	
	inline EActorDir GetPrevDir() const
	{
		return PrevDir;
	}

	bool GetIsMove() const
	{
		return IsMove;
	}

	void StateReset();

	bool MoveCheck(EInputType _Input);
	virtual void MoveSet(EInputType _Input);
	virtual void BackMoveSet();
	void Move(float _DeltaTime);

	void RenderOff();
	void RenderOn();

	void AnimationOn();
	void AnimationOff();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* Renderer = nullptr;
	//FINT TilePosition = FINT();

	bool NextTileCheck(FINT _NextTilePos, EInputType _Input);
	bool MoveEndCheck(FINT _TilePos);

	bool IsMove = false;
	float TileSize = 32.0f;

private:
	UTileInfo Info;

	FINT PrevPos = FINT();
	FINT NextPos = FINT();

	EActorDir PrevDir = EActorDir::None;

	float MoveRange = 32.0f;
	float MoveTime = 0.3f;
	float CurMoveTime = 0.0f;

	std::stack<EActorDir> MoveHistory;

	FVector Lerp(float _CurMoveTime) const;

	UTileInfo FirstStateInfo;
};