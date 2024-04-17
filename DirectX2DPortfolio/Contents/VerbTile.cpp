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

	WordsCheck();
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
				EActorType ActorType = TileActor->GetActorType();
				if (ActorType == HorizontalLeftType)
				{
					TileActor->SetHasController(false);
					HorizontalLeftType = EActorType::None;
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
				EActorType ActorType = TileActor->GetActorType();
				if (ActorType == VerticalLeftType)
				{
					TileActor->SetHasController(false);
					VerticalLeftType = EActorType::None;
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

	std::shared_ptr<ATile> LeftTileActor;
	std::shared_ptr<ATile> RightTileActor;

	std::list<std::shared_ptr<ATile>> LeftTileActorList = StaticHelper::CurTileMap[LeftTilePos];
	if (false == LeftTileActorList.empty())
	{
		LeftTileActor = LeftTileActorList.front();
		if (EActorType::CharNoun == LeftTileActor->GetActorType())
		{
			IsCharNoun = true;
		}
	}

	std::list<std::shared_ptr<ATile>> RightTileActorList = StaticHelper::CurTileMap[RightTilePos];
	if (false == RightTileActorList.empty())
	{
		RightTileActor = RightTileActorList.front();
		if (EActorType::Noun == RightTileActor->GetActorType())
		{
			IsNoun = true;
		}
	}

	if (true == (IsNoun && IsCharNoun))
	{
		ENounType LeftNounType = LeftTileActor->GetNounType();
		ENounType RightNounType = RightTileActor->GetNounType();

		std::map<FINT, std::list<std::shared_ptr<ATile>>> TileActorMap = StaticHelper::CurTileMap;
		for (std::pair<FINT, std::list<std::shared_ptr<ATile>>> Iterator : TileActorMap)
		{
			std::list<std::shared_ptr<ATile>> TileActorList = Iterator.second;
			for (std::shared_ptr<ATile> TileActor : TileActorList)
			{
				EActorType ActorType = TileActor->GetActorType();
				EActorType CheckActorType = EActorType::None;
				switch (LeftNounType)
				{
				case ENounType::Baba:
					break;
				case ENounType::Pillar:
					CheckActorType = EActorType::Pillar;
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
						TileActor->SetHasController(true);
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

	std::shared_ptr<ATile> UpTileActor;
	std::shared_ptr<ATile> DownTileActor;

	std::list<std::shared_ptr<ATile>> UpTileActorList = StaticHelper::CurTileMap[UpTilePos];
	if (false == UpTileActorList.empty())
	{
		UpTileActor = UpTileActorList.front();
		if (EActorType::CharNoun == UpTileActor->GetActorType())
		{
			IsCharNoun = true;
		}
	}

	std::list<std::shared_ptr<ATile>> DownTileActorList = StaticHelper::CurTileMap[DownTilePos];
	if (false == DownTileActorList.empty())
	{
		DownTileActor = DownTileActorList.front();
		if (EActorType::Noun == DownTileActor->GetActorType())
		{
			IsNoun = true;
		}
	}

	if (true == (IsNoun && IsCharNoun))
	{
		ENounType UpNounType = UpTileActor->GetNounType();
		ENounType DownNounType = DownTileActor->GetNounType();

		std::map<FINT, std::list<std::shared_ptr<ATile>>> TileActorMap = StaticHelper::CurTileMap;
		for (std::pair<FINT, std::list<std::shared_ptr<ATile>>> Iterator : TileActorMap)
		{
			std::list<std::shared_ptr<ATile>> TileActorList = Iterator.second;
			for (std::shared_ptr<ATile> TileActor : TileActorList)
			{
				EActorType ActorType = TileActor->GetActorType();
				EActorType CheckActorType = EActorType::None;
				switch (UpNounType)
				{
				case ENounType::Baba:
					break;
				case ENounType::Pillar:
					CheckActorType = EActorType::Pillar;
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
						TileActor->SetHasController(true);
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
