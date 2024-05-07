#include "PreCompile.h"
#include "Tile.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"
#include "ConnectingTile.h"
#include "MoveEffect.h"

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

float4 ATile::GetMulColorByTileType()
{
	float4 MulColorByTile = float4();

	ETileType CurTileTYpe = Info.TileType;
	if (ETileType::LWord == CurTileTYpe || ETileType::RWord == CurTileTYpe)
	{
		MulColorByTile = GetMulColorBytNounType();
	}
	else
	{
		switch (CurTileTYpe)
		{
		case ETileType::Baba:
			MulColorByTile = RGBToFloat4(255, 255, 255);
			break;
		case ETileType::Wall:
			MulColorByTile = RGBToFloat4(41, 49, 65);
			break;
		case ETileType::Lava:
			MulColorByTile = RGBToFloat4(228, 153, 80);
			break;
		case ETileType::Rock:
			MulColorByTile = RGBToFloat4(194, 158, 70);
			break;
		case ETileType::Water:
			MulColorByTile = RGBToFloat4(95, 157, 209);
			break;
		case ETileType::Flag:
			MulColorByTile = RGBToFloat4(237, 226, 133);
			break;
		case ETileType::Is:
		{
			if (true == IsAnimationOn)
			{
				MulColorByTile = RGBToFloat4(255, 255, 255);
			}
			else
			{
				MulColorByTile = RGBToFloat4(115, 115, 115);
			}
			break;
		}
		/*case ETileType::And:
		{
			if (true == IsRender)
			{
				MulColorByTile = RGBToFloat4();
			}
			else
			{
				MulColorByTile = RGBToFloat4();
			}
			break;
		}*/
		case ETileType::Skull:
			MulColorByTile = RGBToFloat4(130, 38, 28);
			break;
		case ETileType::Grass:
			MulColorByTile = RGBToFloat4(48, 56, 36);
			break;
		case ETileType::MapTile:
			MulColorByTile = RGBToFloat4(31, 31, 31);
			break;
		}
	}

	return MulColorByTile;
}

float4 ATile::GetMulColorBytNounType()
{
	float4 MulColorByTile = float4();

	ENounType NType = Info.NounType;
	switch (NType)
	{
	case ENounType::BabaText:
	case ENounType::YouText:
	{
		if (true == IsAnimationOn)
		{
			MulColorByTile = RGBToFloat4(217, 57, 106);
		}
		else
		{
			MulColorByTile = RGBToFloat4(104, 46, 76);
		}
		break;
	}
	case ENounType::PillarText:
	{
		if (true == IsAnimationOn)
		{
			MulColorByTile = RGBToFloat4(115, 115, 115);
		}
		else
		{
			MulColorByTile = RGBToFloat4(41, 49, 65);
		}
		break;
	}
	case ENounType::LavaText:
	case ENounType::HotText:
	{
		if (true == IsAnimationOn)
		{
			MulColorByTile = RGBToFloat4(228, 153, 80);
		}
		else
		{
			MulColorByTile = RGBToFloat4(229, 83, 59);
		}
		break;
	}
	case ENounType::RockText:
	case ENounType::PushText:
	{
		if (true == IsAnimationOn)
		{
			MulColorByTile = RGBToFloat4(144, 103, 62);
		}
		else
		{
			MulColorByTile = RGBToFloat4(80, 63, 36);
		}
		break;
	}
	case ENounType::WaterText:
	case ENounType::SinkText:
	case ENounType::MeltText:
	{
		if (true == IsAnimationOn)
		{
			MulColorByTile = RGBToFloat4(95, 157, 209);
		}
		else
		{
			MulColorByTile = RGBToFloat4(62, 118, 136);
		}
		break;
	}
	case ENounType::FlagText:
	case ENounType::WinText:
	{
		if (true == IsAnimationOn)
		{
			MulColorByTile = RGBToFloat4(237, 226, 133);
		}
		else
		{
			MulColorByTile = RGBToFloat4(144, 103, 62);
		}
		break;
	}
	
	case ENounType::StopText:
	{
		if (true == IsAnimationOn)
		{
			MulColorByTile = RGBToFloat4(75, 92, 28);
		}
		else
		{
			MulColorByTile = RGBToFloat4(48, 56, 36);
		}
		break;
	}

	case ENounType::SkullText:
	case ENounType::DefeatText:
	{
		if (true == IsAnimationOn)
		{
			MulColorByTile = RGBToFloat4(130, 38, 28);
		}
		else
		{
			MulColorByTile = RGBToFloat4(66, 25, 16);
		}
		break;
	}
		
	case ENounType::GrassText:
	{
		if (true == IsAnimationOn)
		{
			MulColorByTile = RGBToFloat4(165, 177, 63);
		}
		else
		{
			MulColorByTile = RGBToFloat4(75, 92, 28);
		}
		break;
	}
	case ENounType::MapTileText:
	{
		if (true == IsAnimationOn)
		{
			MulColorByTile = RGBToFloat4(116, 116, 116);
		}
		else
		{
			MulColorByTile = RGBToFloat4(36, 45, 63);
		}
		break;
	}
	}

	return MulColorByTile;
}

float4 ATile::RGBToFloat4(int _R, int _G, int _B)
{
	float4 Result = float4();
	Result.X = static_cast<float>(_R) / 255.f;
	Result.Y = static_cast<float>(_G) / 255.f;
	Result.Z = static_cast<float>(_B) / 255.f;
	Result.W = 1.f;
	return Result;
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
	Info.IsHot = FirstStateInfo.IsHot;
	Info.IsMelt = FirstStateInfo.IsMelt;
	RenderOn();
}

bool ATile::MoveCheck(EInputType _Input)
{
	FINT CurTilePos = Info.TilePosition;
	FINT NextTilePos = CurTilePos;

	InputType = _Input;

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
		SpawnMoveEffect(PrevPos);
		InputType = EInputType::None;
		IsMove = false;
		CurMoveTime = MoveTime;
		std::list<ATile*>& TileList = StaticHelper::CurTileMap[PrevPos];
		std::list<ATile*>::iterator StartIter = TileList.begin();
		std::list<ATile*>::iterator EndIter = TileList.end();
		for (; StartIter != EndIter;)
		{
			if (*StartIter == this)
			{
				StartIter = TileList.erase(StartIter);
				continue;
			}
			++StartIter;
		}
		StaticHelper::CurTileMap[NextPos].push_back(this);

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

void ATile::SpawnMoveEffect(FINT _PrevPos)
{
	if (EInputType::None == InputType)
	{
		return;
	}

	AMoveEffect* MoveEffect = GetWorld()->SpawnActor<AMoveEffect>("MoveEffect").get();
	float4 MulColorByTile = GetMulColorByTileType();
	MoveEffect->SetColorByTile(MulColorByTile);
	MoveEffect->SetInput(InputType);
	FVector SpawnPos = _PrevPos.GetFINTToVector();
	MoveEffect->SetActorLocation(SpawnPos);
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