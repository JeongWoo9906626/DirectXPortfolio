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
			StaticHelper::TempMove = true;
			MoveHistory.push(EActorDir::Left);
			MoveSet();
		}

		if (true == UEngineInput::IsDown(VK_RIGHT))
		{
			if (false == MoveCheck(EActorDir::Right))
			{
				return;
			}
			StaticHelper::TempMove = true;
			MoveHistory.push(EActorDir::Right);
			MoveSet();
		}

		if (true == UEngineInput::IsDown(VK_UP))
		{
			if (false == MoveCheck(EActorDir::Up))
			{
				return;
			}
			StaticHelper::TempMove = true;
			MoveHistory.push(EActorDir::Up);
			MoveSet();
		}

		if (true == UEngineInput::IsDown(VK_DOWN))
		{
			if (false == MoveCheck(EActorDir::Down))
			{
				return;
			}
			StaticHelper::TempMove = true;
			MoveHistory.push(EActorDir::Down);
			MoveSet();
		}
	}
	else if (false == IsMove && false == HasController)
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

		if (true == IsTileMove)
		{
			if (false == MoveCheck(CurDir))
			{
				return;
			}
			MoveHistory.push(CurDir);
			MoveSet();
		}
		else
		{
			if (true == StaticHelper::TempMove)
			{
				MoveHistory.push(EActorDir::None);
				MoveSet();
			}
		}
	}
	else if (true == IsMove)
	{
		if (CurMoveTime <= 0.0f)
		{
			IsTileMove = false;
			IsBack = false;
			IsMove = false;
			CurMoveTime = 0.0f;
		}

		CurMoveTime -= _DeltaTime;

		FVector MovePos = Lerp(CurMoveTime);
		SetActorLocation(MovePos);
		StaticHelper::TempMove = false;
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

	bool CanMove = MoveTileActorCheck(NextTilePos, _Dir);
	return CanMove;
}

bool AActorBase::MoveEndCheck(FINT _TilePos)
{
	FINT MapTileSize = FINT::MapSize;
	if (_TilePos.X >= MapTileSize.X)
	{
		return false;
	}
	else if (_TilePos.X < 0)
	{
		return false;
	}
	else
	{
		if (_TilePos.Y >= MapTileSize.Y)
		{
			return false;
		}
		else if (_TilePos.Y < 0)
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
	FINT NextArray = FINT();
	switch (_Dir)
	{
	case EActorDir::Left:
		NextArray = FINT::LEFT;
		break;
	case EActorDir::Right:
		NextArray = FINT::RIGHT;
		break;
	case EActorDir::Up:
		NextArray = FINT::UP;
		break;
	case EActorDir::Down:
		NextArray = FINT::DOWN;
		break;
	case EActorDir::None:
		break;
	}

	bool Temp = true;

	if (false == MoveEndCheck(_NextTilePos))
	{
		Temp = false;
		return Temp;
	}

	std::list<std::shared_ptr<ATile>> NextTileActorList = StaticHelper::CurTileMap[_NextTilePos];
	if (true == NextTileActorList.empty())
	{
		Temp = true;
		return Temp;
	}
	else // List가 비어있지 않은 경우 (Tile을 가지고 있는 경우)
	{
		for (std::shared_ptr<ATile> NextTileActor : NextTileActorList)
		{
			// Controller 를 가지고 있는 경우 (직접 움직일 수 있음)
			if (true == NextTileActor->GetHasController())
			{
				Temp = true;
			}
			else // Controller 를 가지고 있지 않은 경우
			{
				// Block이 true 인 경우 (뚫고 못지나 감)
				if (true == NextTileActor->GetIsBlock())
				{
					// CanMove가 true인 경우 밀고 갈 수 있음
					if (true == NextTileActor->GetCanMove())
					{
						std::shared_ptr<AActorBase> NewNext = static_pointer_cast<AActorBase>(NextTileActor);
						bool Result = NewNext->MoveCheck(_Dir);
						NewNext->SetIsTileMove(Result, _Dir);
						
						Temp = Temp && Result;
					}
					else // CanMove가 false인 경우 완전 움직일 수 없음(완전 막힘)
					{
						Temp = false;
					}
				}
				else // Block 이 아닌 경우 (뚫고 지나감)
				{
					// CanMove가 true와 false일 때 둘다 뚫고 지나감
					Temp = true;
				}
			}
		}
		return Temp;
	}
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
	case EActorDir::None:
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
