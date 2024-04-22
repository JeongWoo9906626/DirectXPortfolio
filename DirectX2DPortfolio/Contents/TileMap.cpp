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

	{
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
		std::shared_ptr<ATile> YouNoun = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AYouText>("YouText"));
		YouNoun->SetTilePosition(TestPos);
		YouNoun->SetTileLocation();
		Map[TestPos].push_back(YouNoun);
	}
	{
		FINT TestPos = FINT(5, 3);
		std::shared_ptr<ATile> YouNoun = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AYouText>("YouText"));
		YouNoun->SetTilePosition(TestPos);
		YouNoun->SetTileLocation();
		Map[TestPos].push_back(YouNoun);
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

	StaticHelper::CurTileMap = Map;
}

void ATileMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	
	MoveResult = MoveEnd();
	if (false == MoveResult)
	{
		IsBack = false;
		IsInput = false;
		IsTileMove = false;
		Input = EInputType::None;
	}

	if (false == IsInput)
	{
		TileInputCheck();
		TileMoveCheck();
		TileMoveSet();
		TileUpdate();
		TileStateReset();
		TileSentenceCheck();
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
		std::map<FINT, std::list<std::shared_ptr<ATile>>> NewTileMap;
		for (std::pair<FINT, std::list<std::shared_ptr<ATile>>> Iterator : Map)
		{
			FINT CurMapTilePos = Iterator.first;
			std::list<std::shared_ptr<ATile>> TileActorList = Iterator.second;

			for (std::shared_ptr<ATile> TileActor : TileActorList)
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

	std::map<FINT, std::list<std::shared_ptr<ATile>>> NewTileMap;
	for (std::pair<FINT, std::list<std::shared_ptr<ATile>>> Iterator : Map)
	{
		FINT CurMapTilePos = Iterator.first;
		std::list<std::shared_ptr<ATile>> TileActorList = Iterator.second;

		for (std::shared_ptr<ATile> TileActor : TileActorList)
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
		std::map<FINT, std::list<std::shared_ptr<ATile>>> NewTileMap;
		for (std::pair<FINT, std::list<std::shared_ptr<ATile>>> Iterator : Map)
		{
			FINT CurMapTilePos = Iterator.first;
			std::list<std::shared_ptr<ATile>> TileActorList = Iterator.second;

			for (std::shared_ptr<ATile> TileActor : TileActorList)
			{
				TileActor->BackMoveSet();
			}
		}
	}
	else
	{
		std::map<FINT, std::list<std::shared_ptr<ATile>>> NewTileMap;
		for (std::pair<FINT, std::list<std::shared_ptr<ATile>>> Iterator : Map)
		{
			FINT CurMapTilePos = Iterator.first;
			std::list<std::shared_ptr<ATile>> TileActorList = Iterator.second;

			for (std::shared_ptr<ATile> TileActor : TileActorList)
			{
				TileActor->MoveSet(Input);
			}
		}
	}
}

void ATileMap::TileUpdate()
{
	std::map<FINT, std::list<std::shared_ptr<ATile>>> NewTileMap;
	for (std::pair<FINT, std::list<std::shared_ptr<ATile>>> Iterator : Map)
	{
		FINT CurMapTilePos = Iterator.first;
		std::list<std::shared_ptr<ATile>> TileActorList = Iterator.second;

		for (std::shared_ptr<ATile> TileActor : TileActorList)
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

void ATileMap::TileStateReset()
{
	std::map<FINT, std::list<std::shared_ptr<ATile>>> NewTileMap = StaticHelper::CurTileMap;
	for (std::pair<FINT, std::list<std::shared_ptr<ATile>>> Iterator : NewTileMap)
	{
		std::list<std::shared_ptr<ATile>> TileActorList = Iterator.second;
		for (std::shared_ptr<ATile> TileActor : TileActorList)
		{
			TileActor->StateReset();
		}
	}
}

void ATileMap::TileSentenceCheck()
{
	std::map<FINT, std::list<std::shared_ptr<ATile>>> NewTileMap = StaticHelper::CurTileMap;
	for (std::pair<FINT, std::list<std::shared_ptr<ATile>>> Iterator : NewTileMap)
	{
		std::list<std::shared_ptr<ATile>> TileActorList = Iterator.second;
		for (std::shared_ptr<ATile> TileActor : TileActorList)
		{
			if (ETileType::Is == TileActor->GetActorType())
			{
				AConnectingTile* NewVerbTile = dynamic_cast<AConnectingTile*>(TileActor.get());
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
	std::map<FINT, std::list<std::shared_ptr<ATile>>> NewTileMap;
	for (std::pair<FINT, std::list<std::shared_ptr<ATile>>> Iterator : Map)
	{
		FINT CurMapTilePos = Iterator.first;
		std::list<std::shared_ptr<ATile>> TileActorList = Iterator.second;

		for (std::shared_ptr<ATile> TileActor : TileActorList)
		{
			Temp = Temp || TileActor->GetIsMove();
		}
	}

	return Temp;
}
