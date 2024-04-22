#include "PreCompile.h"
#include "ConnectingTile.h"
#include "StaticHelper.h"

AConnectingTile::AConnectingTile()
{

}

AConnectingTile::~AConnectingTile()
{

}

void AConnectingTile::BeginPlay()
{
	Super::BeginPlay();
}

void AConnectingTile::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void AConnectingTile::WordsCheck()
{
	FINT CurTilePos = GetTileInfo().TilePosition;

	HorizontalResult = HorizontalCheck(CurTilePos);
	VerticalResult = VerticalCheck(CurTilePos);

	if (false == HorizontalResult)
	{
		std::map<FINT, std::list<std::shared_ptr<ATile>>> TileMap = StaticHelper::CurTileMap;
		for (std::pair<FINT, std::list<std::shared_ptr<ATile>>> Iterator : TileMap)
		{
			std::list<std::shared_ptr<ATile>> TileActorList = Iterator.second;
			for (std::shared_ptr<ATile> TileActor : TileActorList)
			{
				ETileType ActorType = TileActor->GetActorType();
				if (ActorType == HorizontalLeftType)
				{
					TileActor->SetIsController(false);
					HorizontalLeftType = ETileType::None;
				}
			}
		}
	}

	if (false == VerticalResult)
	{
		std::map<FINT, std::list<std::shared_ptr<ATile>>> TileMap = StaticHelper::CurTileMap;
		for (std::pair<FINT, std::list<std::shared_ptr<ATile>>> Iterator : TileMap)
		{
			std::list<std::shared_ptr<ATile>> TileActorList = Iterator.second;
			for (std::shared_ptr<ATile> TileActor : TileActorList)
			{
				ETileType ActorType = TileActor->GetActorType();
				if (ActorType == VerticalLeftType)
				{
					TileActor->SetIsController(false);
					VerticalLeftType = ETileType::None;
				}
			}
		}
	}
}



bool AConnectingTile::HorizontalCheck(FINT _TilePos)
{
	IsCharNoun = false;
	IsNoun = false;

	FINT LeftTilePos = _TilePos + FINT::LEFT;
	FINT RightTilePos = _TilePos + FINT::RIGHT;

	std::shared_ptr<ATile> TempLeftTileActor;
	std::shared_ptr<ATile> TempRightTileActor;

	std::list<std::shared_ptr<ATile>> LeftTileActorList = StaticHelper::CurTileMap[LeftTilePos];
	if (false == LeftTileActorList.empty())
	{
		for (std::shared_ptr<ATile> LeftTileActor : LeftTileActorList)
		{
			TempLeftTileActor = LeftTileActor;
			if (ETileType::LWord == TempLeftTileActor->GetActorType())
			{
				IsCharNoun = true;
			}
		}
	}
	

	std::list<std::shared_ptr<ATile>> RightTileActorList = StaticHelper::CurTileMap[RightTilePos];
	if (false == RightTileActorList.empty())
	{
		for (std::shared_ptr<ATile> RightTileActor : RightTileActorList)
		{
			TempRightTileActor = RightTileActor;
			if (ETileType::RWord == TempRightTileActor->GetActorType())
			{
				IsNoun = true;
			}
		}
	}

	if (true == IsNoun && true == IsCharNoun)
	{
		ENounType LeftNounType = TempLeftTileActor->GetNounType();
		ENounType RightNounType = TempRightTileActor->GetNounType();

		ETileType CheckActorType = ETileType::None;
		switch (LeftNounType)
		{
		case ENounType::Baba:
			CheckActorType = ETileType::Baba;
			break;
		case ENounType::Pillar:
			CheckActorType = ETileType::Pillar;
			break;
		case ENounType::Lava:
			break;
		case ENounType::You:
			break;
		case ENounType::None:
			break;
		}

		std::map<FINT, std::list<std::shared_ptr<ATile>>> TileActorMap = StaticHelper::CurTileMap;
		for (std::pair<FINT, std::list<std::shared_ptr<ATile>>> Iterator : TileActorMap)
		{
			std::list<std::shared_ptr<ATile>> TileActorList = Iterator.second;
			for (std::shared_ptr<ATile> TileActor : TileActorList)
			{
				ETileType ActorType = TileActor->GetActorType();
				

				if (ActorType == CheckActorType)
				{
					switch (RightNounType)
					{
					case ENounType::Baba:
						break;
					case ENounType::Pillar:
						break;
					case ENounType::Lava:
						break;
					case ENounType::You:
						TileActor->SetIsController(true);
						break;
					}
					HorizontalLeftType = ActorType;
				}
				else
				{
					TileActor->SetIsController(false);
				}
			}
		}
	}

	return (IsNoun && IsCharNoun);
}

bool AConnectingTile::VerticalCheck(FINT _TilePos)
{
	IsCharNoun = false;
	IsNoun = false;

	FINT UpTilePos = _TilePos + FINT::UP;
	FINT DownTilePos = _TilePos + FINT::DOWN;

	std::shared_ptr<ATile> TempUpTileActor;
	std::shared_ptr<ATile> TempDownTileActor;

	std::list<std::shared_ptr<ATile>> UpTileActorList = StaticHelper::CurTileMap[UpTilePos];
	if (false == UpTileActorList.empty())
	{
		for (std::shared_ptr<ATile> UpTileActor : UpTileActorList)
		{
			TempUpTileActor = UpTileActor;
			if (ETileType::LWord == UpTileActor->GetActorType())
			{
				IsCharNoun = true;
			}
		}
	}

	std::list<std::shared_ptr<ATile>> DownTileActorList = StaticHelper::CurTileMap[DownTilePos];
	if (false == UpTileActorList.empty())
	{
		for (std::shared_ptr<ATile> DownTileActor : DownTileActorList)
		{
			TempDownTileActor = DownTileActor;
			if (ETileType::RWord == DownTileActor->GetActorType())
			{
				IsNoun = true;
			}
		}
	}

	if (true == IsNoun && true == IsCharNoun)
	{
		ENounType UpNounType = TempUpTileActor->GetNounType();
		ENounType DownNounType = TempDownTileActor->GetNounType();

		ETileType CheckActorType = ETileType::None;

		switch (UpNounType)
		{
		case ENounType::Baba:
			CheckActorType = ETileType::Baba;
			break;
		case ENounType::Pillar:
			CheckActorType = ETileType::Pillar;
			break;
		case ENounType::Lava:
			break;
		case ENounType::You:
			break;
		case ENounType::None:
			break;
		}

		std::map<FINT, std::list<std::shared_ptr<ATile>>> TileActorMap = StaticHelper::CurTileMap;
		for (std::pair<FINT, std::list<std::shared_ptr<ATile>>> Iterator : TileActorMap)
		{
			std::list<std::shared_ptr<ATile>> TileActorList = Iterator.second;
			for (std::shared_ptr<ATile> TileActor : TileActorList)
			{
				ETileType ActorType = TileActor->GetActorType();
				

				if (ActorType == CheckActorType)
				{
					switch (DownNounType)
					{
					case ENounType::Baba:
						break;
					case ENounType::Pillar:
						break;
					case ENounType::Lava:
						break;
					case ENounType::You:
						TileActor->SetIsController(true);
						break;
					}
					VerticalLeftType = ActorType;
				}
				else
				{
					if (false == HorizontalResult)
					{
						TileActor->SetIsController(false);
					}

				}
			}
		}
	}

	return (IsNoun && IsCharNoun);
}