#include "PreCompile.h"
#include "VerbTile.h"
#include "StaticHelper.h"

AVerbTile::AVerbTile()
{

}

AVerbTile::~AVerbTile()
{

}

void AVerbTile::BeginPlay()
{
	Super::BeginPlay();
}

void AVerbTile::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	//WordsCheck();
}

void AVerbTile::WordsCheck()
{
	FINT CurTilePos = TilePosition;

	bool HorizontalResult = HorizontalCheck(CurTilePos);
	bool VerticalResult = VerticalCheck(CurTilePos);

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



bool AVerbTile::HorizontalCheck(FINT _TilePos)
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
			if (ETileType::LWord == LeftTileActor->GetActorType())
			{
				IsCharNoun = true;
			}
			/*else
			{
				IsCharNoun = false;
			}*/
		}
	}
	

	std::list<std::shared_ptr<ATile>> RightTileActorList = StaticHelper::CurTileMap[RightTilePos];
	if (false == RightTileActorList.empty())
	{
		for (std::shared_ptr<ATile> RightTileActor : RightTileActorList)
		{
			TempRightTileActor = RightTileActor;
			if (ETileType::RWord == RightTileActor->GetActorType())
			{
				IsNoun = true;
			}
			/*else
			{
				IsNoun = false;
			}*/
		}
	}

	if (true == IsNoun && true == IsCharNoun)
	{
		ENounType LeftNounType = TempLeftTileActor->GetNounType();
		ENounType RightNounType = TempRightTileActor->GetNounType();

		std::map<FINT, std::list<std::shared_ptr<ATile>>> TileActorMap = StaticHelper::CurTileMap;
		for (std::pair<FINT, std::list<std::shared_ptr<ATile>>> Iterator : TileActorMap)
		{
			std::list<std::shared_ptr<ATile>> TileActorList = Iterator.second;
			for (std::shared_ptr<ATile> TileActor : TileActorList)
			{
				ETileType ActorType = TileActor->GetActorType();
				ETileType CheckActorType = ETileType::None;
				switch (LeftNounType)
				{
				case ENounType::Baba:
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
			}
		}
	}

	return (IsNoun && IsCharNoun);
}

bool AVerbTile::VerticalCheck(FINT _TilePos)
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
			/*else
			{
				IsCharNoun = false;
			}*/
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
			/*else
			{
				IsNoun = false;
			}*/
		}
	}

	if (true == IsNoun && true == IsCharNoun)
	{
		ENounType UpNounType = TempUpTileActor->GetNounType();
		ENounType DownNounType = TempDownTileActor->GetNounType();

		std::map<FINT, std::list<std::shared_ptr<ATile>>> TileActorMap = StaticHelper::CurTileMap;
		for (std::pair<FINT, std::list<std::shared_ptr<ATile>>> Iterator : TileActorMap)
		{
			std::list<std::shared_ptr<ATile>> TileActorList = Iterator.second;
			for (std::shared_ptr<ATile> TileActor : TileActorList)
			{
				ETileType ActorType = TileActor->GetActorType();
				ETileType CheckActorType = ETileType::None;
				switch (UpNounType)
				{
				case ENounType::Baba:
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
			}
		}
	}

	return (IsNoun && IsCharNoun);
}

void AVerbTile::UnLock()
{
	int a = 0;
}
