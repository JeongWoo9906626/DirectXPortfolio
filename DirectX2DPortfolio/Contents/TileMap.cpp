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

	StaticHelper::CurTileMap = Map;
}

void ATileMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

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

void ATileMap::TileAliveCheck()
{
	std::map<FINT, std::list<std::shared_ptr<ATile>>> NewTileMap = StaticHelper::CurTileMap;
	for (std::pair<FINT, std::list<std::shared_ptr<ATile>>> Iterator : NewTileMap)
	{
		std::list<std::shared_ptr<ATile>> TileActorList = Iterator.second;
		for (std::shared_ptr<ATile> TileActor : TileActorList)
		{
			if (true == TileActor->GetIsDefeat())
			{
				FINT DefeatPosition = TileActor->GetTilePosition();
				DefeatCheck(DefeatPosition);
			}
			if (true == TileActor->GetIsSink())
			{
				FINT SinkPosition = TileActor->GetTilePosition();
				SinkCheck(SinkPosition);
			}
		}
	}
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

void ATileMap::DefeatCheck(FINT _TilePosition)
{
	std::list<std::shared_ptr<ATile>> TileList = StaticHelper::CurTileMap[_TilePosition];
	if (1 == TileList.size())
	{
		return;
	}

	for (std::shared_ptr<ATile> Tile : TileList)
	{
		if (true == Tile->GetIsDefeat())
		{
			continue;
		}
		if (
			ETileType::LWord == Tile->GetActorType() ||
			ETileType::RWord == Tile->GetActorType() ||
			ETileType::Is == Tile->GetActorType() ||
			ETileType::And == Tile->GetActorType()
			)
		{
			continue;
		}
		Tile->SetIsController(false);
		Tile->RenderOff();
	}
}

void ATileMap::SinkCheck(FINT _TilePosition)
{
	std::list<std::shared_ptr<ATile>> TileList = StaticHelper::CurTileMap[_TilePosition];
	if (1 == TileList.size())
	{
		return;
	}
	for (std::shared_ptr<ATile> Tile : TileList)
	{
		if (
			ETileType::LWord == Tile->GetActorType() ||
			ETileType::RWord == Tile->GetActorType() ||
			ETileType::Is == Tile->GetActorType() ||
			ETileType::And == Tile->GetActorType()
			)
		{
			continue;
		}
		Tile->SetIsController(false);
		Tile->RenderOff();
	}
}
