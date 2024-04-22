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
		Player->SetTileInfo(Pos, true, true, false, true, ETileType::Baba, ENounType::None);
		Player->SetTileLocation();
		//Player->SetActorType(EActorType::Baba);
		Map[Pos].push_back(Player);
	}

	{
		FINT TestPos = FINT(3, 3);
		std::shared_ptr<ATile> IsText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AIsText>("IsText"));
		IsText->SetTileInfo(TestPos, true, true, false, true, ETileType::Is, ENounType::None);
		IsText->SetTileLocation();
		//Test2->SetActorType(EActorType::Selector);
		Map[TestPos].push_back(IsText);
	}

	{
		FINT TestPos = FINT(2, 3);
		std::shared_ptr<ATile> IsText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ABabaText>("BabaText"));
		IsText->SetTileInfo(TestPos, true, true, false, true, ETileType::LWord, ENounType::Baba);
		IsText->SetTileLocation();
		//Test2->SetActorType(EActorType::Selector);
		Map[TestPos].push_back(IsText);
	}

	{
		FINT TestPos = FINT(2, 4);
		std::shared_ptr<ATile> Wall = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWall>("Wall"));
		Wall->SetTileInfo(TestPos, true, true, false, true, ETileType::Pillar, ENounType::None);
		Wall->SetTileLocation();
		//Wall->SetActorType(EActorType::Pillar);
		Map[TestPos].push_back(Wall);
	}

	{
		FINT TestPos = FINT(4, 3);
		std::shared_ptr<ATile> YouNoun = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AYouText>("YouText"));
		YouNoun->SetTileInfo(TestPos, true, true, false, true, ETileType::RWord, ENounType::You);
		YouNoun->SetTileLocation();
		//Wall->SetActorType(EActorType::Pillar);
		Map[TestPos].push_back(YouNoun);
	}
	{
		FINT TestPos = FINT(5, 3);
		std::shared_ptr<ATile> YouNoun = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AYouText>("YouText"));
		YouNoun->SetTileInfo(TestPos, true, true, false, true, ETileType::RWord, ENounType::You);
		YouNoun->SetTileLocation();
		//Wall->SetActorType(EActorType::Pillar);
		Map[TestPos].push_back(YouNoun);
	}
	{
		FINT TestPos = FINT(2, 2);
		std::shared_ptr<ATile> WallText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWallText>("WallText"));
		WallText->SetTileInfo(TestPos, true, true, false, true, ETileType::LWord, ENounType::Pillar);
		WallText->SetTileLocation();
		//Test->SetActorType(EActorType::Selector);
		Map[TestPos].push_back(WallText);
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
