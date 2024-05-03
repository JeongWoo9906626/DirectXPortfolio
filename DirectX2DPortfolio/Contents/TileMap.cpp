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


std::map<FINT, std::list<ATile*>> ATileMap::Map;

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

	/*{
		FINT Pos = FINT(1, 1);
		std::shared_ptr<ATile> Player = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ABaba>("Baba"));
		Player->SetTilePosition(Pos);
		Player->SetTileLocation();
		Map[Pos].push_back(Player);
	}

	{
		FINT Pos = FINT(4, 2);
		std::shared_ptr<ATile> StopText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AStopText>("StopText"));
		StopText->SetTilePosition(Pos);
		StopText->SetTileLocation();
		Map[Pos].push_back(StopText);
	}

	{
		FINT TestPos = FINT(3, 3);
		std::shared_ptr<ATile> IsText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AIsText>("IsText"));
		IsText->SetTilePosition(TestPos);
		IsText->SetTileLocation();
		Map[TestPos].push_back(IsText);
	}

	{
		FINT TestPos = FINT(2, 3);
		std::shared_ptr<ATile> BabaText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ABabaText>("BabaText"));
		BabaText->SetTilePosition(TestPos);
		BabaText->SetTileLocation();
		Map[TestPos].push_back(BabaText);
	}

	{
		FINT TestPos = FINT(2, 4);
		std::shared_ptr<ATile> Wall = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWall>("Wall"));
		Wall->SetTilePosition(TestPos);
		Wall->SetTileLocation();
		Map[TestPos].push_back(Wall);
	}

	{
		FINT TestPos = FINT(4, 3);
		std::shared_ptr<ATile> YouText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AYouText>("YouText"));
		YouText->SetTilePosition(TestPos);
		YouText->SetTileLocation();
		Map[TestPos].push_back(YouText);
	}
	{
		FINT TestPos = FINT(5, 3);
		std::shared_ptr<ATile> SinkText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ASinkText>("SinkText"));
		SinkText->SetTilePosition(TestPos);
		SinkText->SetTileLocation();
		Map[TestPos].push_back(SinkText);
	}
	{
		FINT TestPos = FINT(2, 2);
		std::shared_ptr<ATile> WallText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWallText>("WallText"));
		WallText->SetTilePosition(TestPos);
		WallText->SetTileLocation();
		Map[TestPos].push_back(WallText);
	}

	{
		FINT TestPos = FINT(6, 2);
		std::shared_ptr<ATile> PushText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<APushText>("WallText"));
		PushText->SetTilePosition(TestPos);
		PushText->SetTileLocation();
		Map[TestPos].push_back(PushText);
	}
	{
		FINT TestPos = FINT(6, 3);
		std::shared_ptr<ATile> DefeatText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ADefeatText>("DefeatText"));
		DefeatText->SetTilePosition(TestPos);
		DefeatText->SetTileLocation();
		Map[TestPos].push_back(DefeatText);
	}
	{
		FINT TestPos = FINT(6, 4);
		std::shared_ptr<ATile> Water = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWater>("Water"));
		Water->SetTilePosition(TestPos);
		Water->SetTileLocation();
		Map[TestPos].push_back(Water);
	}
	{
		FINT TestPos = FINT(7, 4);
		std::shared_ptr<ATile> Water = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWater>("Water"));
		Water->SetTilePosition(TestPos);
		Water->SetTileLocation();
		Map[TestPos].push_back(Water);
	}
	{
		FINT TestPos = FINT(6, 5);
		std::shared_ptr<ATile> Water = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWater>("Water"));
		Water->SetTilePosition(TestPos);
		Water->SetTileLocation();
		Map[TestPos].push_back(Water);
	}
	{
		FINT TestPos = FINT(7, 5);
		std::shared_ptr<ATile> Water = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWater>("Water"));
		Water->SetTilePosition(TestPos);
		Water->SetTileLocation();
		Map[TestPos].push_back(Water);
	}
	{
		FINT TestPos = FINT(5, 5);
		std::shared_ptr<ATile> WaterText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWaterText>("WaterText"));
		WaterText->SetTilePosition(TestPos);
		WaterText->SetTileLocation();
		Map[TestPos].push_back(WaterText);
	}

	{
		FINT TestPos = FINT(10, 5);
		std::shared_ptr<ATile> Lava = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ALava>("Lava"));
		Lava->SetTilePosition(TestPos);
		Lava->SetTileLocation();
		Map[TestPos].push_back(Lava);
	}
	{
		FINT TestPos = FINT(11, 5);
		std::shared_ptr<ATile> Lava = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ALava>("Lava"));
		Lava->SetTilePosition(TestPos);
		Lava->SetTileLocation();
		Map[TestPos].push_back(Lava);
	}
	{
		FINT TestPos = FINT(12, 5);
		std::shared_ptr<ATile> Lava = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ALava>("Lava"));
		Lava->SetTilePosition(TestPos);
		Lava->SetTileLocation();
		Map[TestPos].push_back(Lava);
	}
	{
		FINT TestPos = FINT(12, 6);
		std::shared_ptr<ATile> Lava = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ALava>("Lava"));
		Lava->SetTilePosition(TestPos);
		Lava->SetTileLocation();
		Map[TestPos].push_back(Lava);
	}
	{
		FINT TestPos = FINT(5, 7);
		std::shared_ptr<ATile> LavaText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ALavaText>("LavaText"));
		LavaText->SetTilePosition(TestPos);
		LavaText->SetTileLocation();
		Map[TestPos].push_back(LavaText);
	}

	{
		FINT TestPos = FINT(7, 7);
		std::shared_ptr<ATile> FlagText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AFlagText>("FlagText"));
		FlagText->SetTilePosition(TestPos);
		FlagText->SetTileLocation();
		Map[TestPos].push_back(FlagText);
	}
	{
		FINT TestPos = FINT(7, 8);
		std::shared_ptr<ATile> Flag = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AFlag>("Flag"));
		Flag->SetTilePosition(TestPos);
		Flag->SetTileLocation();
		Map[TestPos].push_back(Flag);
	}
	{
		FINT TestPos = FINT(6, 8);
		std::shared_ptr<ATile> WinText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWinText>("WinText"));
		WinText->SetTilePosition(TestPos);
		WinText->SetTileLocation();
		Map[TestPos].push_back(WinText);
	}
	{
		FINT TestPos = FINT(5, 8);
		std::shared_ptr<ATile> Rock = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ARock>("Rock"));
		Rock->SetTilePosition(TestPos);
		Rock->SetTileLocation();
		Map[TestPos].push_back(Rock);
	}
	{
		FINT TestPos = FINT(4, 8);
		std::shared_ptr<ATile> RockText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ARockText>("RockText"));
		RockText->SetTilePosition(TestPos);
		RockText->SetTileLocation();
		Map[TestPos].push_back(RockText);
	}*/

	StaticHelper::CurTileMap = Map;
}

void ATileMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);


	if (true == GameWin)
	{
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
		TileUpdate();
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
		for (std::pair<FINT, std::list<ATile*>> Iterator : Map)
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
	for (std::pair<FINT, std::list<ATile*>> Iterator : Map)
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
		for (std::pair<FINT, std::list<ATile*>> Iterator : Map)
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
		for (std::pair<FINT, std::list<ATile*>> Iterator : Map)
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

void ATileMap::TileUpdate()
{
	std::map<FINT, std::list<ATile*>> NewTileMap;
	for (std::pair<FINT, std::list<ATile*>> Iterator : Map)
	{
		FINT CurMapTilePos = Iterator.first;
		std::list<ATile*> TileActorList = Iterator.second;

		for (ATile* TileActor : TileActorList)
		{
			FINT TilePos = TileActor->GetTilePosition();
			if (TilePos != CurMapTilePos)
			{
				NewTileMap[TilePos].push_back(TileActor);
			}
			else
			{
				NewTileMap[TilePos].push_back(TileActor);
			}
		}
	}

	Map.clear();
	Map = NewTileMap;
	NewTileMap.clear();
	StaticHelper::CurTileMap = Map;
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
	for (std::pair<FINT, std::list<ATile*>> Iterator : Map)
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
			/*if (
				ETileType::LWord == Tile->GetTileType() ||
				ETileType::RWord == Tile->GetTileType() ||
				ETileType::Is == Tile->GetTileType() ||
				ETileType::And == Tile->GetTileType()
				)
			{
				Check = false;
				continue;
			}*/
			if (_TileType != Tile->GetTileType())
			{
				Check = true;
				Tile->SetIsController(false);
				Tile->SetIsBlock(false);
				Tile->SetIsPush(false);
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
		for (ATile* Tile : TileList)
		{
			if (false == Tile->IsRender)
			{
				Tile->SetIsController(false);
				Tile->SetIsBlock(false);
				Tile->SetIsPush(false);
				Tile->RenderOff();
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
		}
	}
}
