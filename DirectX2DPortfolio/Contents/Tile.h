#pragma once
#include <EngineCore/Actor.h>
#include "ContentsStruct.h"

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

	inline void SetPosition(FINT _TilePosition)
	{
		TilePosition = _TilePosition;
	}

	inline FINT GetTilePosition() const
	{
		return TilePosition;
	}

	inline bool GetCanMove() const
	{
		return CanMove;
	}

	inline void SetCanMove(bool _CanMove)
	{
		CanMove = _CanMove;
	}

	inline bool GetHasController() const
	{
		return HasController;
	}

	inline void SetHasController(bool _HasController)
	{
		HasController = _HasController;
	}

	void SetTileSetting(FINT _TilePosition, bool _CanMove, bool _HasController, bool _IsBlock)
	{
		this->TilePosition = _TilePosition;
		this->CanMove = _CanMove;
		this->HasController = _HasController;
		this->IsBlock = _IsBlock;
		
	}

	void SetTileLocation()
	{
		FVector StartPos = this->TilePosition.GetFINTToVector();
		this->SetActorLocation(StartPos);
	}

	void SetIsBlock(bool _IsBlock)
	{
		IsBlock = _IsBlock;
	}

	bool GetIsBlock()
	{
		return IsBlock;
	}

	void SetActorType(EActorType _Type)
	{
		Type = _Type;
	}

	EActorType GetActorType()
	{
		return Type;
	}

	virtual void SetIsTileMove(bool _IsTileMove, EActorDir _Dir)
	{
		IsTileMove = _IsTileMove;
	}

	bool GetIsTileMove()
	{
		return IsTileMove;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	USpriteRenderer* Renderer = nullptr;
	FINT TilePosition = FINT();
	EActorType Type = EActorType::None;

	// HasController : 키 입력을 받아 움직이는 여부
	bool HasController = false;
	// CanMove : 밀었을때 움직이는 여부
	bool CanMove;
	// IsBlock : 캐릭터 통과 여부
	bool IsBlock;
	
	// 밀었을때 움직이는지 아닌지 알려주는 변수
	bool IsTileMove = false;

	float TileSize = 32.0f;

private:
};