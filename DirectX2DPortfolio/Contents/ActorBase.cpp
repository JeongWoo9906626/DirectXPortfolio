#include "PreCompile.h"
#include "ActorBase.h"
#include <EngineCore/EngineDebugMsgWindow.h>
#include "StaticHelper.h"

AActorBase::AActorBase()
{
	InputOn();
}

AActorBase::~AActorBase()
{

}

void AActorBase::BeginPlay()
{
	Super::BeginPlay();
	SetMoveRange(32.0f);
}

void AActorBase::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	{
		FVector TilePos = { TilePosition.X, TilePosition.Y, 0 };
		std::string Msg = std::format("PlayerTilePos : {}\n", std::to_string(TilePos.X) + " " + std::to_string(TilePos.Y));
		UEngineDebugMsgWindow::PushMsg(Msg);
	}
	{
		FVector TilePos = { TilePosition.X, TilePosition.Y, 0 };
		std::string Msg = std::format("PlayerPos : {}\n", GetActorLocation().ToString());
		UEngineDebugMsgWindow::PushMsg(Msg);
	}

	if (false == IsMove && true == HasController)
	{
		if (true == UEngineInput::IsDown('Z'))
		{
			
			if (true == MoveHistory.empty())
			{
				return;
			}

			if (false == AnimationIndexHistory.empty())
			{
				AnimationIndexHistory.pop();
			}

			IsBack = true;
			MoveSet();
			MoveHistory.pop();
		}

		if (true == UEngineInput::IsDown(VK_LEFT))
		{
			if (false == MoveCheck(EActorDir::Left))
			{
				return;
			}
			MoveHistory.push(EActorDir::Left);
			MoveSet();
		}

		if (true == UEngineInput::IsDown(VK_RIGHT))
		{
			if (false == MoveCheck(EActorDir::Right))
			{
				return;
			}
			MoveHistory.push(EActorDir::Right);
			MoveSet();
		}

		if (true == UEngineInput::IsDown(VK_UP))
		{
			if (false == MoveCheck(EActorDir::Up))
			{
				return;
			}
			MoveHistory.push(EActorDir::Up);
			MoveSet();
		}

		if (true == UEngineInput::IsDown(VK_DOWN))
		{
			if (false == MoveCheck(EActorDir::Down))
			{
				return;
			}
			MoveHistory.push(EActorDir::Down);
			MoveSet();
		}
	}
	else if (true == IsMove)
	{
		if (CurMoveTime <= 0.0f)
		{
			IsBack = false;
			IsMove = false;
			CurMoveTime = 0.0f;
		}

		CurMoveTime -= _DeltaTime;

		FVector MovePos = Lerp(CurMoveTime);
		SetActorLocation(MovePos);
	}
}

bool AActorBase::MoveCheck(EActorDir _Dir)
{
	FINT CurTilePos = TilePosition;
	FINT NextTilePos = CurTilePos;

	switch (_Dir)
	{
	case EActorDir::Left:
		NextTilePos.X -= 1;
		break;
	case EActorDir::Right:
		NextTilePos.X += 1;
		break;
	case EActorDir::Up:
		NextTilePos.Y += 1;
		break;
	case EActorDir::Down:
		NextTilePos.Y -= 1;
		break;
	}

	if (false == MoveEndCheck(NextTilePos, _Dir))
	{
		return false;
	}
	else
	{
		return MoveTileActorCheck(NextTilePos, _Dir);
	}
}

bool AActorBase::MoveEndCheck(FINT _NextTilePos, EActorDir _Dir)
{
	FINT MapTileSize = FINT::MapSize;
	if (_NextTilePos.X >= MapTileSize.X)
	{
		return false;
	}
	else if (_NextTilePos.X < 0)
	{
		return false;
	}
	else
	{
		if (_NextTilePos.Y >= MapTileSize.Y)
		{
			return false;
		}
		else if (_NextTilePos.Y < 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

bool AActorBase::MoveTileActorCheck(FINT _NextTilePos, EActorDir _Dir)
{
	std::list<std::shared_ptr<ATile>> NextTileActorList = StaticHelper::CurTileMap[_NextTilePos];
	for (std::shared_ptr<ATile> NextTileActor : NextTileActorList)
	{
		if (true == NextTileActor->GetIsBlock())
		{
			return false;
		}
	}

	return true;
}

void AActorBase::MoveSet()
{
	IsMove = true;
	CurMoveTime = MoveTime;

	PrevPos = TilePosition.GetTilePos();
	NextPos = PrevPos;
	CurDir = MoveHistory.top();
	
	int Dir = 1;
	if (true == IsBack)
	{
		Dir = -1;
	}

	switch (CurDir)
	{
	case EActorDir::Left:
		TilePosition.X -= Dir;
		break;
	case EActorDir::Right:
		TilePosition.X += Dir;
		break;
	case EActorDir::Up:
		TilePosition.Y += Dir;
		break;
	case EActorDir::Down:
		TilePosition.Y -= Dir;
		break;
	}
	
	NextPos = TilePosition;
}

FVector AActorBase::Lerp(float _CurMoveTime) const
{
	float t = (MoveTime - _CurMoveTime) / MoveTime;

	// 64.2 -> 64
	// 63.9999999997 -> 63

	//FINT CurPos;
	FVector CurPos;
	CurPos.X = PrevPos.X * TileSize * (1 - t) + NextPos.X * TileSize * t;
	CurPos.Y = PrevPos.Y * TileSize * (1 - t) + NextPos.Y * TileSize * t;

	CurPos.X = static_cast<int>(std::lround(CurPos.X));
	CurPos.Y = static_cast<int>(std::lround(CurPos.Y));

	return CurPos;
}
