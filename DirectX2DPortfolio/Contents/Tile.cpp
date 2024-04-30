#include "PreCompile.h"
#include "Tile.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"
#include "ConnectingTile.h"

ATile::ATile()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Root->SetScale(FVector(54.0f, 54.0f, 20.0f));
	SetRoot(Root);

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
}

ATile::~ATile()
{

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
		RenderOn();
		Move(_DeltaTime);
	}
}

void ATile::StateReset()
{
	if (ETileType::LWord == GetTileType() || ETileType::RWord == GetTileType() || ETileType::Is == GetTileType() || ETileType::And == GetTileType())
	{
		AnimationOff();
	}

	Info.IsController = FirstStateInfo.IsController;
	Info.IsBlock = FirstStateInfo.IsBlock;
	Info.IsPush = FirstStateInfo.IsPush;
	Info.IsSink = FirstStateInfo.IsSink;
	Info.IsDefeat = FirstStateInfo.IsDefeat;
	Info.IsWin = FirstStateInfo.IsWin;
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
	}

	CurMoveTime -= _DeltaTime;

	FVector MovePos = Lerp(CurMoveTime);
	SetActorLocation(MovePos);
}

void ATile::RenderOff()
{
	IsRender = false;
	Renderer->SetActive(false);
}

void ATile::RenderOn()
{
	IsRender = true;
	Renderer->SetActive(true);
}

void ATile::AnimationOn()
{
	if (IsAnimationOn == true) {
		return;
	}

	IsAnimationOn = true;
	Renderer->ChangeAnimation("On");
}

void ATile::AnimationOff()
{
	if (IsAnimationOn == false) {
		return;
	}

	IsAnimationOn = false;
	Renderer->ChangeAnimation("Off");
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

	std::list<ATile*> NextTileActorList = StaticHelper::CurTileMap[_NextTilePos];
	if (true == NextTileActorList.empty())
	{
		return true;
	}
	else // List가 비어있지 않은 경우 (Tile을 가지고 있는 경우)
	{
		for (ATile* NextTileActor : NextTileActorList)
		{
			//bool Result = false;
			// Controller 를 가지고 있는 경우 (직접 움직일 수 있음)
			if (true == NextTileActor->GetTileInfo().IsController)
			{
				//Temp = true;
				return true;
			}
			else // Controller 를 가지고 있지 않은 경우
			{
				// Block이 true 인 경우 (뚫고 못지나 감)
				if (true == NextTileActor->GetTileInfo().IsBlock)
				{
					// CanMove가 true인 경우 밀고 갈 수 있음
					if (true == NextTileActor->GetTileInfo().IsPush)
					{
						bool Result = NextTileActor->MoveCheck(_Input);
						NextTileActor->IsMove = Result;

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

FVector ATile::Lerp(float _CurMoveTime) 
{
	FVector PrevVector = PrevPos.GetFINTToVector();
	FVector NextVector = NextPos.GetFINTToVector();
	float t = (MoveTime - _CurMoveTime) / MoveTime;

	FVector CurPos;
	/*CurPos.X = PrevPos.X * StaticHelper::TileSize * (1 - t) + NextPos.X * StaticHelper::TileSize * t;
	CurPos.Y = PrevPos.Y * StaticHelper::TileSize * (1 - t) + NextPos.Y * StaticHelper::TileSize * t;*/

	CurPos.X = PrevVector.X * (1 - t) + NextVector.X * t;
	CurPos.Y = PrevVector.Y * (1 - t) + NextVector.Y * t;

	CurPos.X = static_cast<int>(std::lround(CurPos.X));
	CurPos.Y = static_cast<int>(std::lround(CurPos.Y));

	return CurPos;
}