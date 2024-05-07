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

	HorizontalIsCheck(CurTilePos);
	VerticalIsCheck(CurTilePos);

}



void AConnectingTile::HorizontalIsCheck(FINT _TilePos)
{
	bool IsCharNoun = false;
	bool IsNoun = false;

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
				}
			}
		}
		HorizontalAndCheck(_TilePos, CheckActorType, RightNounType);
	}
}

void AConnectingTile::VerticalIsCheck(FINT _TilePos)
{
	bool IsCharNoun = false;
	bool IsNoun = false;

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
				}
			}
		}
		VerticalAndCheck(_TilePos, CheckActorType, DownNounType);
	}
}

void AConnectingTile::HorizontalAndCheck(FINT _TilePos, ETileType _TileType, ENounType _TextType)
{
	{
		FINT ExpectedLeftAndTile = _TilePos + (FINT::LEFT * 2);
		bool IsLeftAnd = false;
		bool IsLWord = false;

		ATile* TempLeftAndTileActor = nullptr;
		ATile* TempLeftLWordTileActor = nullptr;

		std::list<ATile*> LeftTileActorList = StaticHelper::CurTileMap[ExpectedLeftAndTile];
		for (ATile* LeftTile : LeftTileActorList)
		{
			if (ETileType::And == LeftTile->GetTileType())
			{
				TempLeftAndTileActor = LeftTile;
				IsLeftAnd = true;
				break;
			}
		}

		if (true == IsLeftAnd)
		{
			FINT LeftNextTile = ExpectedLeftAndTile + FINT::LEFT;
			std::list<ATile*> TileActorList = StaticHelper::CurTileMap[LeftNextTile];
			for (ATile* Tile : TileActorList)
			{
				if (ETileType::LWord == Tile->GetTileType())
				{
					TempLeftLWordTileActor = Tile;
					IsLWord = true;
					break;
				}
			}
		}

		if (true == IsLWord)
		{
			if (false == TempLeftAndTileActor->IsAnimationOn)
			{
				TempLeftAndTileActor->AnimationOn();
			}
			if (false == TempLeftLWordTileActor->IsAnimationOn)
			{
				TempLeftLWordTileActor->AnimationOn();
			}

			ENounType LeftNounType = TempLeftLWordTileActor->GetNounType();
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
						switch (_TextType)
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
					}
				}
			}
		}
	}

	{
		FINT ExpectedRightAndTile = _TilePos + (FINT::RIGHT * 2);
		bool IsRightAnd = false;
		bool IsRWord = false;
		ATile* TempRightAndTileActor = nullptr;
		ATile* TempRightRWordTileActor = nullptr;

		std::list<ATile*> RightTileActorList = StaticHelper::CurTileMap[ExpectedRightAndTile];
		for (ATile* RightTile : RightTileActorList)
		{
			if (ETileType::And == RightTile->GetTileType())
			{
				TempRightAndTileActor = RightTile;
				IsRightAnd = true;
				break;
			}
		}

		if (true == IsRightAnd)
		{
			FINT RightNextTile = ExpectedRightAndTile + FINT::RIGHT;
			std::list<ATile*> TileActorList = StaticHelper::CurTileMap[RightNextTile];
			for (ATile* Tile : TileActorList)
			{
				if (ETileType::LWord == Tile->GetTileType())
				{
					TempRightRWordTileActor = Tile;
					IsRWord = true;
					break;
				}
			}
		}

		if (true == IsRWord)
		{
			if (false == TempRightAndTileActor->IsAnimationOn)
			{
				TempRightAndTileActor->AnimationOn();
			}
			if (false == TempRightRWordTileActor->IsAnimationOn)
			{
				TempRightRWordTileActor->AnimationOn();
			}

			std::map<FINT, std::list<ATile*>> TileActorMap = StaticHelper::CurTileMap;
			for (std::pair<FINT, std::list<ATile*>> Iterator : TileActorMap)
			{
				std::list<ATile*> TileActorList = Iterator.second;
				for (ATile* TileActor : TileActorList)
				{
					ETileType ActorType = TileActor->GetTileType();
					if (ActorType == _TileType)
					{
						switch (_TextType)
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
					}
				}
			}
		}
	}
}

void AConnectingTile::VerticalAndCheck(FINT _TilePos, ETileType _TileType, ENounType _TextType)
{
	{
		FINT ExpectedUpAndTile = _TilePos + (FINT::UP * 2);
		bool IsUpAnd = false;
		bool IsLWord = false;

		ATile* TempUpAndTileActor = nullptr;
		ATile* TempUpLWordTileActor = nullptr;

		std::list<ATile*> UpTileActorList = StaticHelper::CurTileMap[ExpectedUpAndTile];
		for (ATile* UpTile : UpTileActorList)
		{
			if (ETileType::And == UpTile->GetTileType())
			{
				TempUpAndTileActor = UpTile;
				IsUpAnd = true;
				break;
			}
		}

		if (true == IsUpAnd)
		{
			FINT UpNextTile = ExpectedUpAndTile + FINT::LEFT;
			std::list<ATile*> TileActorList = StaticHelper::CurTileMap[UpNextTile];
			for (ATile* Tile : TileActorList)
			{
				if (ETileType::LWord == Tile->GetTileType())
				{
					TempUpLWordTileActor = Tile;
					IsLWord = true;
					break;
				}
			}
		}

		if (true == IsLWord)
		{
			if (false == TempUpAndTileActor->IsAnimationOn)
			{
				TempUpAndTileActor->AnimationOn();
			}
			if (false == TempUpLWordTileActor->IsAnimationOn)
			{
				TempUpLWordTileActor->AnimationOn();
			}

			ENounType UpNounType = TempUpLWordTileActor->GetNounType();
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
						switch (_TextType)
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
					}
				}
			}
		}
	}

	{
		FINT ExpectedDownAndTile = _TilePos + (FINT::DOWN * 2);
		bool IsDownAnd = false;
		bool IsRWord = false;
		ATile* TempDownAndTileActor = nullptr;
		ATile* TempDownRWordTileActor = nullptr;

		std::list<ATile*> DwonTileActorList = StaticHelper::CurTileMap[ExpectedDownAndTile];
		for (ATile* DownTile : DwonTileActorList)
		{
			if (ETileType::And == DownTile->GetTileType())
			{
				TempDownAndTileActor = DownTile;
				IsDownAnd = true;
				break;
			}
		}

		if (true == IsDownAnd)
		{
			FINT DownNextTile = ExpectedDownAndTile + FINT::RIGHT;
			std::list<ATile*> TileActorList = StaticHelper::CurTileMap[DownNextTile];
			for (ATile* Tile : TileActorList)
			{
				if (ETileType::LWord == Tile->GetTileType())
				{
					TempDownRWordTileActor = Tile;
					IsRWord = true;
					break;
				}
			}
		}

		if (true == IsRWord)
		{
			if (false == TempDownAndTileActor->IsAnimationOn)
			{
				TempDownAndTileActor->AnimationOn();
			}
			if (false == TempDownRWordTileActor->IsAnimationOn)
			{
				TempDownRWordTileActor->AnimationOn();
			}

			std::map<FINT, std::list<ATile*>> TileActorMap = StaticHelper::CurTileMap;
			for (std::pair<FINT, std::list<ATile*>> Iterator : TileActorMap)
			{
				std::list<ATile*> TileActorList = Iterator.second;
				for (ATile* TileActor : TileActorList)
				{
					ETileType ActorType = TileActor->GetTileType();
					if (ActorType == _TileType)
					{
						switch (_TextType)
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
					}
				}
			}
		}
	}
}
