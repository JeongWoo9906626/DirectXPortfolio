#include "PreCompile.h"
#include "Tile.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

ATile::ATile()
{

}

ATile::~ATile()
{

}

void ATile::SetTileInfo(FINT _TilePosition, bool _IsPush, bool _IsBlock, bool _IsController, bool _IsAlive, ETileType _TileType, ENounType _NounType)
{
	Info.TilePosition = _TilePosition;
	Info.IsPush = _IsPush;
	Info.IsBlock = _IsBlock;
	Info.IsController = _IsController;
	Info.IsAlive = _IsAlive;
	Info.TileType = _TileType;
	Info.NounType = _NounType;
}

void ATile::BeginPlay()
{
	Super::BeginPlay();

	CurMoveTime = MoveTime;
}

void ATile::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == IsMove)
	{
		Move(_DeltaTime);
	}
}

bool ATile::MoveCheck(EInputType _Input)
{
	FINT CurTilePos = Info.TilePosition;
	FINT NextTilePos = CurTilePos;

	switch (_Input)
	{
	case EInputType::L:
		NextTilePos.X -= 1;
		break;
	case EInputType::R:
		NextTilePos.X += 1;
		break;
	case EInputType::U:
		NextTilePos.Y += 1;
		break;
	case EInputType::D:
		NextTilePos.Y -= 1;
		break;
	}
	
	bool CanMove = NextTileCheck(NextTilePos, _Input);
	IsMove = CanMove;
	return CanMove;
}
void ATile::MoveSet(EInputType _Input)
{
	int a = 0;
	if (true == IsMove)
	{
		EActorDir Dir = EActorDir::None;
		PrevPos = Info.TilePosition;
		NextPos = PrevPos;

		switch (_Input)
		{
		case EInputType::L:
		{
			NextPos = NextPos + FINT::LEFT;
			Dir = EActorDir::Left;
			break;
		}
		case EInputType::R:
		{
			NextPos = NextPos + FINT::RIGHT;
			Dir = EActorDir::Right;
			break;
		}
		case EInputType::U:
		{
			NextPos = NextPos + FINT::UP;
			Dir = EActorDir::Up;
			break;
		}
		case EInputType::D:
		{
			NextPos = NextPos + FINT::DOWN;
			Dir = EActorDir::Down;
			break;
		}
		}

		MoveHistory.push(Dir);
	}
	else
	{
		MoveHistory.push(EActorDir::None);
	}

}
void ATile::BackMoveSet()
{
	IsMove = true;

	EActorDir Dir = MoveHistory.top();
	PrevPos = Info.TilePosition;
	NextPos = PrevPos;

	PrevDir = Dir;

	switch (Dir)
	{
	case EActorDir::Left:
		NextPos = PrevPos + FINT::RIGHT;
		break;
	case EActorDir::Right:
		NextPos = PrevPos + FINT::LEFT;
		break;
	case EActorDir::Up:
		NextPos = PrevPos + FINT::DOWN;
		break;
	case EActorDir::Down:
		NextPos = PrevPos + FINT::UP;
		break;
	case EActorDir::None:
		NextPos = PrevPos + FINT();
		break;
	}
	
	MoveHistory.pop();
}
void ATile::Move(float _DeltaTime)
{
	if (CurMoveTime <= 0.0f)
	{
		IsMove = false;
		CurMoveTime = MoveTime;
		PrevPos = NextPos;
		Info.TilePosition = NextPos;
		//�Լ������� ���Ž���
	}

	CurMoveTime -= _DeltaTime;

	FVector MovePos = Lerp(CurMoveTime);
	SetActorLocation(MovePos);
}

bool ATile::NextTileCheck(FINT _NextTilePos, EInputType _Input)
{
	FINT NextArray = FINT();
	switch (_Input)
	{
	case EInputType::L:
		NextArray = FINT::LEFT;
		break;
	case EInputType::R:
		NextArray = FINT::RIGHT;
		break;
	case EInputType::U:
		NextArray = FINT::UP;
		break;
	case EInputType::D:
		NextArray = FINT::DOWN;
		break;
	case EInputType::None:
		break;
	}

	bool Temp = true;

 	if (false == MoveEndCheck(_NextTilePos))
	{
		//Temp = false;
		return false;
	}

	std::list<std::shared_ptr<ATile>> NextTileActorList = StaticHelper::CurTileMap[_NextTilePos];
	if (true == NextTileActorList.empty())
	{
		//Temp = true;
		return true;
	}
	else // List�� ������� ���� ��� (Tile�� ������ �ִ� ���)
	{
		for (std::shared_ptr<ATile> NextTileActor : NextTileActorList)
		{
			//bool Result = false;
			// Controller �� ������ �ִ� ��� (���� ������ �� ����)
			if (true == NextTileActor->GetTileInfo().IsController)
			{
				//Temp = true;
				return true;
			}
			else // Controller �� ������ ���� ���� ���
			{
				// Block�� true �� ��� (�հ� ������ ��)
				if (true == NextTileActor->GetTileInfo().IsBlock)
				{
					// CanMove�� true�� ��� �а� �� �� ����
					if (true == NextTileActor->GetTileInfo().IsPush)
					{
						bool Result = NextTileActor->MoveCheck(_Input);
						NextTileActor->IsMove = Result;

						Temp = Temp && Result;
					}
					else // CanMove�� false�� ��� ���� ������ �� ����(���� ����)
					{
						Temp = false;
					}
				}
				else // Block �� �ƴ� ��� (�հ� ������)
				{

					// CanMove�� true�� false�� �� �Ѵ� �հ� ������
					Temp = true;
				}
				//NextTileActor->SetIsTileMove(Result, _Dir);
			}
		}
		return Temp;
	}
}

bool ATile::MoveEndCheck(FINT _TilePos)
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

FVector ATile::Lerp(float _CurMoveTime) const
{
	float t = (MoveTime - _CurMoveTime) / MoveTime;

	FVector CurPos;
	CurPos.X = PrevPos.X * TileSize * (1 - t) + NextPos.X * TileSize * t;
	CurPos.Y = PrevPos.Y * TileSize * (1 - t) + NextPos.Y * TileSize * t;

	CurPos.X = static_cast<int>(std::lround(CurPos.X));
	CurPos.Y = static_cast<int>(std::lround(CurPos.Y));

	return CurPos;
}