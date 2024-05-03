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

	ATile* TempLeftTileActor = nullptr;
	ATile* TempRightTileActor = nullptr;

	std::list<ATile*> LeftTileActorList = StaticHelper::CurTileMap[LeftTilePos];
	if (false == LeftTileActorList.empty())
	{
		for (ATile* LeftTileActor : LeftTileActorList)
		{
			TempLeftTileActor = LeftTileActor;
			if (ETileType::LWord == TempLeftTileActor->GetTileType())
			{
				IsCharNoun = true;
				break;
			}
		}
	}
	

	std::list<ATile*> RightTileActorList = StaticHelper::CurTileMap[RightTilePos];
	if (false == RightTileActorList.empty())
	{
		for (ATile* RightTileActor : RightTileActorList)
		{
			TempRightTileActor = RightTileActor;
			if (ETileType::RWord == TempRightTileActor->GetTileType())
			{
				IsNoun = true;
				break;
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
			CheckActorType = ETileType::Wall;
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
		case ENounType::FlagText:
			CheckActorType = ETileType::Flag;
			break;
		case ENounType::SkullText:
			CheckActorType = ETileType::Skull;
			break;
		case ENounType::GrassText:
			CheckActorType = ETileType::Grass;
			break;
		case ENounType::MapTileText:
			CheckActorType = ETileType::MapTile;
			break;
		case ENounType::None:
			break;
		}

		std::map<FINT, std::list<ATile*>> TileActorMap = StaticHelper::CurTileMap;
		for (std::pair<FINT, std::list<ATile*>> Iterator : TileActorMap)
		{
			std::list<ATile*> TileActorList = Iterator.second;
			for (ATile* TileActor : TileActorList)
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
					case ENounType::WinText:
					{
						TileActor->SetIsWin(true);
						break;
					}
					case ENounType::HotText:
					{
						TileActor->SetIsHot(true);
						break;
					}
					case ENounType::MeltText:
					{
						TileActor->SetIsMelt(true);
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

	ATile* TempUpTileActor = nullptr;
	ATile* TempDownTileActor = nullptr;

	std::list<ATile*> UpTileActorList = StaticHelper::CurTileMap[UpTilePos];
	if (false == UpTileActorList.empty())
	{
		for (ATile* UpTileActor : UpTileActorList)
		{
			TempUpTileActor = UpTileActor;
			if (ETileType::LWord == UpTileActor->GetTileType())
			{
				IsCharNoun = true;
				break;
			}
		}
	}

	std::list<ATile*> DownTileActorList = StaticHelper::CurTileMap[DownTilePos];
	if (false == UpTileActorList.empty())
	{
		for (ATile* DownTileActor : DownTileActorList)
		{
			TempDownTileActor = DownTileActor;
			if (ETileType::RWord == DownTileActor->GetTileType())
			{
				IsNoun = true;
				break;
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
			CheckActorType = ETileType::Wall;
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
		case ENounType::FlagText:
			CheckActorType = ETileType::Flag;
			break;
		case ENounType::SkullText:
			CheckActorType = ETileType::Skull;
			break;
		case ENounType::GrassText:
			CheckActorType = ETileType::Grass;
			break;
		case ENounType::MapTileText:
			CheckActorType = ETileType::MapTile;
			break;
		case ENounType::None:
			break;
		}

		std::map<FINT, std::list<ATile*>> TileActorMap = StaticHelper::CurTileMap;
		for (std::pair<FINT, std::list<ATile*>> Iterator : TileActorMap)
		{
			std::list<ATile*> TileActorList = Iterator.second;
			for (ATile* TileActor : TileActorList)
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
					case ENounType::WinText:
					{
						TileActor->SetIsWin(true);
						break;
					}
					case ENounType::HotText:
					{
						TileActor->SetIsHot(true);
						break;
					}
					case ENounType::MeltText:
					{
						TileActor->SetIsMelt(true);
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