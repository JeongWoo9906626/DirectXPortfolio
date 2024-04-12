#include "PreCompile.h"
#include "ActorBase.h"
#include <EngineCore/EngineDebugMsgWindow.h>

AActorBase::AActorBase()
{

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

	if (false == IsMove)
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
	else
	{
		if (CurMoveTime <= 0.0f)
		{
			IsBack = false;
			IsMove = false;
			CurMoveTime = 0.0f;

			FVector FloatToIntPos = { static_cast<int>(TilePosition.X * TileSize), static_cast<int>(TilePosition.Y * TileSize) };
			SetActorLocation(FloatToIntPos);
		}

		CurMoveTime -= _DeltaTime;

		FINT MovePos = Lerp(CurMoveTime);
		FVector MoveVector = { static_cast<float>(MovePos.X), static_cast<float>(MovePos.Y), 0.0f, 0.0f };
		SetActorLocation(MoveVector);
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

	FINT MapTileSize = FINT::MapSize;
	if (NextTilePos.X >= MapTileSize.X)
	{
		return false;
	}
	else if (NextTilePos.X < 0)
	{
		return false;
	}
	else
	{
		if (NextTilePos.Y >= MapTileSize.Y)
		{
			return false;
		}
		else if (NextTilePos.Y < 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

void AActorBase::MoveSet()
{
	IsMove = true;
	CurMoveTime = MoveTime;

	PrevPos = TilePosition.GetTilePos();
	NextPos = PrevPos;
	CurDir = MoveHistory.top();
	
	float Dir = 1.0f;
	if (true == IsBack)
	{
		Dir = -1.0f;
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

FINT AActorBase::Lerp(float _CurMoveTime) const
{
	float t = (MoveTime - _CurMoveTime) / MoveTime;

	FINT CurPos;
	CurPos.X = PrevPos.X * TileSize * (1 - t) + NextPos.X * TileSize * t;
	CurPos.Y = PrevPos.Y * TileSize * (1 - t) + NextPos.Y * TileSize * t;

	return CurPos;
}
