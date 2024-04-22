#pragma once
#include <EngineCore/Actor.h>
#include "ContentsStruct.h"
#include <stack>

class UTileInfo
{
public:
	FINT TilePosition = FINT();

	bool IsPush = false;
	bool IsBlock = false;
	bool IsController = false;
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

	//void SetTileInfo(FINT _TilePosition, bool _IsPush = false, bool _IsBlock = false, bool _IsController = false, bool _IsAlive = true, ETileType _TileType = ETileType::None, ENounType _NounType = ENounType::None);
	void SetTilePosition(FINT _TilePosition)
	{
		Info.TilePosition = _TilePosition;
	}
	inline UTileInfo GetTileInfo() const
	{
		return Info;
	}

	inline void SetNounType(ENounType _NounType)
	{
		Info.NounType = _NounType;
	}

	inline ENounType GetNounType() const
	{
		return Info.NounType;
	}

	inline void SetPosition(FINT _TilePosition)
	{
		Info.TilePosition = _TilePosition;
	}

	inline FINT GetTilePosition() const
	{
		return Info.TilePosition;
	}

	inline bool GetIsPush() const
	{
		return Info.IsPush;
	}

	inline void SetIsPush(bool _IsPush)
	{
		Info.IsPush = _IsPush;
	}

	inline bool GetIsController() const
	{
		return Info.IsController;
	}

	inline void SetIsController(bool _IsController)
	{
		Info.IsController = _IsController;
	}

	void SetTileLocation()
	{
		FVector StartPos = Info.TilePosition.GetFINTToVector();
		this->SetActorLocation(StartPos);
	}

	void SetIsBlock(bool _IsBlock)
	{
		Info.IsBlock = _IsBlock;
	}

	bool GetIsBlock() const
	{
		return Info.IsBlock;
	}

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

	inline EActorDir GetPrevDir() const
	{
		return PrevDir;
	}

	bool GetIsMove() const
	{
		return IsMove;
	}

	bool MoveCheck(EInputType _Input);
	virtual void MoveSet(EInputType _Input);
	virtual void BackMoveSet();
	void Move(float _DeltaTime);

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
	float MoveTime = 0.5f;
	float CurMoveTime = 0.0f;

	std::stack<EActorDir> MoveHistory;

	FVector Lerp(float _CurMoveTime) const;
};