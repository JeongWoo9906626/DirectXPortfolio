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
			if (ETileType::LWord == TempLeftTileActor->GetTileType())
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
			if (ETileType::RWord == TempRightTileActor->GetTileType())
			{
				IsNoun = true;
			}
		}
	}

	if (true == IsNoun && true == IsCharNoun)
	{
		if (false == this->IsAnimationOn)
		{
			this->AnimationOn();
		}
		if (false == TempLeftTileActor->IsAnimationOn)
		{
			TempLeftTileActor->AnimationOn();
		}
		if (false == TempRightTileActor->IsAnimationOn)
		{
			TempRightTileActor->AnimationOn();
		}

		ENounType LeftNounType = TempLeftTileActor->GetNounType();
		ENounType RightNounType = TempRightTileActor->GetNounType();

		ETileType CheckActorType = ETileType::None;
		switch (LeftNounType)
		{
		case ENounType::BabaText:
			CheckActorType = ETileType::Baba;
			break;
		case ENounType::PillarText:
			CheckActorType = ETileType::Pillar;
			break;
		case ENounType::LavaText:
			CheckActorType = ETileType::Lava;
			break;
		case ENounType::RockText:
			CheckActorType = ETileType::Rock;
			break;
		case ENounType::WaterText:
			CheckActorType = ETileType::Water;
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
				ETileType ActorType = TileActor->GetTileType();
				

				if (ActorType == CheckActorType)
				{
					switch (RightNounType)
					{
					case ENounType::YouText:
						TileActor->SetIsController(true);
						break;
					case ENounType::StopText:
					{
						TileActor->SetIsBlock(true);
						TileActor->SetIsPush(false);
						break;
					}
					case ENounType::PushText:
					{
						TileActor->SetIsBlock(true);
						TileActor->SetIsPush(true);
						break;
					}
					case ENounType::DefeatText:
					{
						TileActor->SetIsDefeat(true);
						break;
					}
					case ENounType::SinkText:
					{
						TileActor->SetIsSink(true);
						break;
					}
					}
					HorizontalLeftType = ActorType;
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
			if (ETileType::LWord == UpTileActor->GetTileType())
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
			if (ETileType::RWord == DownTileActor->GetTileType())
			{
				IsNoun = true;
			}
		}
	}

	if (true == IsNoun && true == IsCharNoun)
	{
		if (false == this->IsAnimationOn)
		{
			this->AnimationOn();
		}
		if (false == TempUpTileActor->IsAnimationOn)
		{
			TempUpTileActor->AnimationOn();
		}
		if (false == TempDownTileActor->IsAnimationOn)
		{
			TempDownTileActor->AnimationOn();
		}

		ENounType UpNounType = TempUpTileActor->GetNounType();
		ENounType DownNounType = TempDownTileActor->GetNounType();

		ETileType CheckActorType = ETileType::None;

		switch (UpNounType)
		{
		case ENounType::BabaText:
			CheckActorType = ETileType::Baba;
			break;
		case ENounType::PillarText:
			CheckActorType = ETileType::Pillar;
			break;
		case ENounType::LavaText:
			CheckActorType = ETileType::Lava;
			break;
		case ENounType::RockText:
			CheckActorType = ETileType::Rock;
			break;
		case ENounType::WaterText:
			CheckActorType = ETileType::Water;
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
				ETileType ActorType = TileActor->GetTileType();
				

				if (ActorType == CheckActorType)
				{
					switch (DownNounType)
					{
					case ENounType::YouText:
						TileActor->SetIsController(true);
						break;
					case ENounType::StopText:
					{
						TileActor->SetIsBlock(true);
						TileActor->SetIsPush(false);
						break;
					}
					case ENounType::PushText:
					{
						TileActor->SetIsBlock(true);
						TileActor->SetIsPush(true);
						break;
					}
					case ENounType::DefeatText:
					{
						TileActor->SetIsDefeat(true);
						break;
					}
					case ENounType::SinkText:
					{
						TileActor->SetIsSink(true);
						break;
					}
					}
					VerticalLeftType = ActorType;
				}
			}
		}
	}

	return (IsNoun && IsCharNoun);
}