#include "PreCompile.h"
#include "TileMap.h"
#include "TestMap.h"
#include <EngineCore/Camera.h>
#include "StaticHelper.h"
#include "Tile.h"
#include "Baba.h"
#include "Selector.h"
#include "Wall.h"
#include "WallText.h"
#include "IsText.h"
#include "YouText.h"
#include "BabaText.h"
#include "StopText.h"
#include "PushText.h"
#include "DefeatText.h"
#include "SinkText.h"
#include "Water.h"
#include "WaterText.h"
#include "Lava.h"
#include "LavaText.h"
#include "Flag.h"
#include "FlagText.h"
#include "WinText.h"
#include "Rock.h"
#include "RockText.h"
#include "SelectTile.h"
#include "FadeOutEffect.h"



ATileMap::ATileMap()
{
	InputOn();
}

ATileMap::~ATileMap()
{

}

void ATileMap::BeginPlay()
{
	Super::BeginPlay();

	//StaticHelper::CurTileMap = Map;
}

void ATileMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


	if (true == GameWin)
	{
		IsInput = true;
		if (false == AnimationEnd)
		{
			if (false == AnimationEndInit)
			{
				FadeOut = GetWorld()->GetLastTarget()->AddEffect<UFadeOutEffect>();
				FadeOut->ResetTime();
				FadeOut.get()->Active(true);
				AnimationEndInit = true;
			}
			while (CurEndEffectTime >= EndEffectTime)
			{
				FadeOut.get()->Active(false);
				AnimationEnd = true;
				AnimationEndInit = false;
				CurEndEffectTime = 0.0f;
				return;
			}
			CurEndEffectTime += _DeltaTime;
		}
		else
		{
			AnimationEnd = false;
			GameWin = false;
			GEngine->ChangeLevel("SelectLevel");
			StaticHelper::CurSelectTileMap[StaticHelper::CurSelector->GetTilePosition()]->SelectInfo.IsStageClear = true;
			return;
		}
	}


	MoveResult = MoveEnd();
	if (false == MoveResult)
	{
		if (BeforeResult != MoveResult)
		{
			IsBack = false;
			IsInput = false;
			IsTileMove = false;
			Input = EInputType::None;

			BeforeResult = MoveResult;
			TileStateReset();
		}
	}
	if (true == IsInput && false == BeforeResult)
	{
		BeforeResult = true;
	}

	if (false == IsInput)
	{
		TileInputCheck();
		TileMoveCheck();
		TileMoveSet();
		TileWinCheck();
		TileSentenceCheck();
		TileAliveCheck();
	}
}

void ATileMap::TileInputCheck()
{
	if (false == IsInput && true == UEngineInput::IsAnykeyDown())
	{
		IsInput = true;
		if (true == UEngineInput::IsDown('Z'))
		{
			IsBack = true;
			Input = EInputType::Z;
		}
		else if (true == UEngineInput::IsDown(VK_LEFT))
		{
			Input = EInputType::L;
		}
		else if (true == UEngineInput::IsDown(VK_RIGHT))
		{
			Input = EInputType::R;
		}
		else if (true == UEngineInput::IsDown(VK_UP))
		{
			Input = EInputType::U;
		}
		else if (true == UEngineInput::IsDown(VK_DOWN))
		{
			Input = EInputType::D;
		}
		else
		{
			Input = EInputType::None;
			IsInput = false;
		}
	}
}

void ATileMap::TileMoveCheck()
{
	if (false == IsInput)
	{
		return;
	}

	if (true == IsBack)
	{
		std::map<FINT, std::list<ATile*>> NewTileMap;
		for (std::pair<FINT, std::list<ATile*>> Iterator : StaticHelper::CurTileMap)
		{
			FINT CurMapTilePos = Iterator.first;
			std::list<ATile*> TileActorList = Iterator.second;

			for (ATile* TileActor : TileActorList)
			{
				if (true == TileActor->GetMoveHistory().empty())
				{
					IsTileMove = false;
					return;
				}
			}
		}

		IsTileMove = true;
		return;
	}

	std::map<FINT, std::list<ATile*>> NewTileMap;
	for (std::pair<FINT, std::list<ATile*>> Iterator : StaticHelper::CurTileMap)
	{
		FINT CurMapTilePos = Iterator.first;
		std::list<ATile*> TileActorList = Iterator.second;

		for (ATile* TileActor : TileActorList)
		{
			if (true == TileActor->GetTileInfo().IsController)
			{
				bool Temp = TileActor->MoveCheck(Input);
				IsTileMove = IsTileMove || Temp;
			}
		}
	}
}

void ATileMap::TileMoveSet()
{
	if (false == IsTileMove)
	{
		return;
	}

	if (true == IsBack)
	{
		std::map<FINT, std::list<ATile*>> NewTileMap;
		for (std::pair<FINT, std::list<ATile*>> Iterator : StaticHelper::CurTileMap)
		{
			FINT CurMapTilePos = Iterator.first;
			std::list<ATile*> TileActorList = Iterator.second;

			for (ATile* TileActor : TileActorList)
			{
				TileActor->BackMoveSet();
			}
		}
	}
	else
	{
		std::map<FINT, std::list<ATile*>> NewTileMap;
		for (std::pair<FINT, std::list<ATile*>> Iterator : StaticHelper::CurTileMap)
		{
			FINT CurMapTilePos = Iterator.first;
			std::list<ATile*> TileActorList = Iterator.second;

			for (ATile* TileActor : TileActorList)
			{
				TileActor->MoveSet(Input);
			}
		}
	}
}

void ATileMap::TileWinCheck()
{
	std::map<FINT, std::list<ATile*>> NewTileMap = StaticHelper::CurTileMap;
	for (std::pair<FINT, std::list<ATile*>> Iterator : NewTileMap)
	{
		std::list<ATile*> TileActorList = Iterator.second;
		for (ATile* TileActor : TileActorList)
		{
			if (true == TileActor->GetIsWin())
			{
				FINT WinPosition = TileActor->GetTilePosition();
				WinCheck(WinPosition);
			}
		}
	}
}

void ATileMap::TileAliveCheck()
{
	std::map<FINT, std::list<ATile*>> NewTileMap = StaticHelper::CurTileMap;
	for (std::pair<FINT, std::list<ATile*>> Iterator : NewTileMap)
	{
		std::list<ATile*> TileActorList = Iterator.second;
		for (ATile* TileActor : TileActorList)
		{
			if (true == TileActor->GetIsDefeat())
			{
				FINT DefeatPosition = TileActor->GetTilePosition();
				DefeatCheck(DefeatPosition);
			}
			if (true == TileActor->GetIsSink())
			{
				FINT SinkPosition = TileActor->GetTilePosition();
				ETileType SinkTileType = TileActor->GetTileType();
				SinkCheck(SinkPosition, SinkTileType);
			}
			if (true == TileActor->GetIsHot())
			{
				FINT HotPosition = TileActor->GetTilePosition();
				HotCheck(HotPosition);
			}
		}
	}
}

void ATileMap::TileStateReset()
{
	std::map<FINT, std::list<ATile*>> NewTileMap = StaticHelper::CurTileMap;
	for (std::pair<FINT, std::list<ATile*>> Iterator : NewTileMap)
	{
		std::list<ATile*> TileActorList = Iterator.second;
		for (ATile* TileActor : TileActorList)
		{
			TileActor->StateReset();
		}
	}
}

void ATileMap::TileSentenceCheck()
{
	std::map<FINT, std::list<ATile*>> NewTileMap = StaticHelper::CurTileMap;
	for (std::pair<FINT, std::list<ATile*>> Iterator : NewTileMap)
	{
		std::list<ATile*> TileActorList = Iterator.second;
		for (ATile* TileActor : TileActorList)
		{
			if (ETileType::Is == TileActor->GetTileType())
			{
				AConnectingTile* NewVerbTile = dynamic_cast<AConnectingTile*>(TileActor);
				NewVerbTile->WordsCheck();
			}
		}
	}
}

bool ATileMap::MoveEnd()
{
	if (false == IsTileMove)
	{
		return false;
	}

	bool Temp = false;
	std::map<FINT, std::list<ATile*>> NewTileMap;
	for (std::pair<FINT, std::list<ATile*>> Iterator : StaticHelper::CurTileMap)
	{
		FINT CurMapTilePos = Iterator.first;
		std::list<ATile*> TileActorList = Iterator.second;

		for (ATile* TileActor : TileActorList)
		{
			Temp = Temp || TileActor->GetIsMove();
		}
	}

	return Temp;
}

void ATileMap::DefeatCheck(FINT _TilePosition)
{
	std::list<ATile*> TileList = StaticHelper::CurTileMap[_TilePosition];
	if (1 == TileList.size())
	{
		return;
	}

	for (ATile* Tile : TileList)
	{
		if (true == Tile->GetIsDefeat())
		{
			continue;
		}
		if (
			ETileType::LWord == Tile->GetTileType() ||
			ETileType::RWord == Tile->GetTileType() ||
			ETileType::Is == Tile->GetTileType() ||
			ETileType::And == Tile->GetTileType()
			)
		{
			continue;
		}
		if (true == Tile->GetIsController())
		{
			Tile->SetIsController(false);
			Tile->RenderOff();
		}
	}
}

void ATileMap::SinkCheck(FINT _TilePosition, ETileType _TileType)
{
	bool Check = false;
	ATile* SinkTile = nullptr;
	std::list<ATile*> TileList = StaticHelper::CurTileMap[_TilePosition];
	if (1 == TileList.size())
	{
		return;
	}
	else if (2 == TileList.size())
	{
		for (ATile* Tile : TileList)
		{
			if (_TileType != Tile->GetTileType())
			{
				Check = true;
				Tile->SetIsController(false);
				Tile->SetIsBlock(false);
				Tile->SetIsPush(false);
				Tile->SetIsWin(false);
				Tile->RenderOff();
			}

			if (_TileType == Tile->GetTileType())
			{
				SinkTile = Tile;
			}
		}
		if (true == Check)
		{
			SinkTile->SetIsController(false);
			SinkTile->RenderOff();
		}
	}
	else
	{
		int Count = 0;
		for (ATile* Tile : TileList)
		{
			if (false == Tile->GetIsController())
			{
				if (true == Tile->GetIsSink())
				{
					Tile->SetIsController(false);
					Tile->RenderOff();
				}
				else if (Count < 1)
				{
					Count++;
					Tile->SetIsController(false);
					Tile->SetIsBlock(false);
					Tile->SetIsPush(false);
					Tile->SetIsWin(false);
					Tile->RenderOff();
				}
			}
		}
	}
}

void ATileMap::HotCheck(FINT _TilePosition)
{
	std::list<ATile*> TileList = StaticHelper::CurTileMap[_TilePosition];
	if (1 == TileList.size())
	{
		return;
	}

	for (ATile* Tile : TileList)
	{
		if (true == Tile->GetIsHot())
		{
			continue;
		}
		if (
			ETileType::LWord == Tile->GetTileType() ||
			ETileType::RWord == Tile->GetTileType() ||
			ETileType::Is == Tile->GetTileType() ||
			ETileType::And == Tile->GetTileType()
			)
		{
			continue;
		}
		if (true == Tile->GetIsMelt())
		{
			Tile->SetIsController(false);
			Tile->SetIsPush(false);
			Tile->SetIsBlock(false);
			Tile->RenderOff();
		}
	}
}

void ATileMap::WinCheck(FINT _TilePosition)
{
	std::list<ATile*> TileList = StaticHelper::CurTileMap[_TilePosition];
	if (1 == TileList.size())
	{
		if (true == TileList.front()->GetIsController())
		{
			GameWin = true;
			TileList.front()->SetIsController(false);
		}
		return;
	}

	for (ATile* Tile : TileList)
	{
		if (
			ETileType::LWord == Tile->GetTileType() ||
			ETileType::RWord == Tile->GetTileType() ||
			ETileType::Is == Tile->GetTileType() ||
			ETileType::And == Tile->GetTileType()
			)
		{
			continue;
		}

		if (true == Tile->GetIsController())
		{
			GameWin = true;
			Tile->SetIsController(false);
		}
	}
}
