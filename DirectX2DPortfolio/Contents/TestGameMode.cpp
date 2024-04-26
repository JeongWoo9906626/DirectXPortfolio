#include "PreCompile.h"
#include "TestGameMode.h"
#include "TestMap.h"
#include <EngineCore/Camera.h>
#include "StaticHelper.h"
#include "TileMap.h"

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

ATestGameMode::ATestGameMode()
{
	Dir.MoveParent();
	Dir.Move("ContentsResources");
	Dir.Move("SaveLevel");
}

ATestGameMode::~ATestGameMode()
{

}

void ATestGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	LoadTileMap("Test");
	std::shared_ptr<ATileMap> TileMap = GetWorld()->SpawnActor<ATileMap>("TM");
	TileMap->SetTileSize(FINT(20, 20));

	GetWorld()->SpawnActor<ATestMap>("TestMap");
}

void ATestGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown('O'))
	{
		GEngine->ChangeLevel("SelectLevel");
	}
}

void ATestGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void ATestGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}

void ATestGameMode::LoadTileMap(std::string _LevelName)
{
	UEngineSerializer Ser;
	std::string Str = _LevelName;
	UEngineFile File = Dir.GetPathFromFile(Str + ".Data");
	if (false == File.IsExists())
	{
		MsgBoxAssert("존재하지 않는 파일 데이터로 맵을 로드하려고 했습니다.");
		return;
	}

	File.Open(EIOOpenMode::Read, EIODataType::Binary);
	File.Load(Ser);
	Ser >> TileData;
	//MessageOn = true;
	//str = "File Load Success";

	int Index = 0;
	while (TileData.size() > Index)
	{
		int X = TileData[Index++];
		int Y = TileData[Index++];
		int Type = TileData[Index++];

		FINT Pos = { X, Y };
		ESpawnType SpawnType = static_cast<ESpawnType>(Type);
		InLevelSpawnTileActor(Pos, SpawnType);
	}
}


void ATestGameMode::InLevelSpawnTileActor(FINT _TilePos, ESpawnType _Type)
{
	switch (_Type)
	{
	case ESpawnType::Baba:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Player = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ABaba>("Baba"));
		Player->SetTilePosition(Pos);
		Player->SetTileLocation();
		ATileMap::Map[Pos].push_back(Player);
		break;
	}
	case ESpawnType::Lava:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Lava = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ALava>("Lava"));
		Lava->SetTilePosition(Pos);
		Lava->SetTileLocation();
		ATileMap::Map[Pos].push_back(Lava);
		break;
	}
	case ESpawnType::Wall:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Wall = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWall>("Wall"));
		Wall->SetTilePosition(Pos);
		Wall->SetTileLocation();
		ATileMap::Map[Pos].push_back(Wall);
		break;
	}
	case ESpawnType::Water:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Water = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWater>("Water"));
		Water->SetTilePosition(Pos);
		Water->SetTileLocation();
		ATileMap::Map[Pos].push_back(Water);
		break;
	}
	case ESpawnType::Flag:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Flag = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AFlag>("Flag"));
		Flag->SetTilePosition(Pos);
		Flag->SetTileLocation();
		ATileMap::Map[Pos].push_back(Flag);
		break;
	}
	case ESpawnType::Rock:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Rock = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ARock>("Rock"));
		Rock->SetTilePosition(Pos);
		Rock->SetTileLocation();
		ATileMap::Map[Pos].push_back(Rock);
		break;
	}
	case ESpawnType::BabaText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> BabaText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ABabaText>("BabaText"));
		BabaText->SetTilePosition(Pos);
		BabaText->SetTileLocation();
		ATileMap::Map[Pos].push_back(BabaText);
		break;
	}
	case ESpawnType::LavaText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> LavaText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ALavaText>("LavaText"));
		LavaText->SetTilePosition(Pos);
		LavaText->SetTileLocation();
		ATileMap::Map[Pos].push_back(LavaText);
		break;
	}
	case ESpawnType::WallText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> WallText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWallText>("WallText"));
		WallText->SetTilePosition(Pos);
		WallText->SetTileLocation();
		ATileMap::Map[Pos].push_back(WallText);
		break;
	}
	case ESpawnType::WaterText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> WaterText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWaterText>("WaterText"));
		WaterText->SetTilePosition(Pos);
		WaterText->SetTileLocation();
		ATileMap::Map[Pos].push_back(WaterText);
		break;
	}
	case ESpawnType::FlagText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> FlagText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AFlagText>("FlagText"));
		FlagText->SetTilePosition(Pos);
		FlagText->SetTileLocation();
		ATileMap::Map[Pos].push_back(FlagText);
		break;
	}
	case ESpawnType::RockText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> RockText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ARockText>("RockText"));
		RockText->SetTilePosition(Pos);
		RockText->SetTileLocation();
		ATileMap::Map[Pos].push_back(RockText);
		break;
	}
	case ESpawnType::DefeatText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> DefeatText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ADefeatText>("DefeatText"));
		DefeatText->SetTilePosition(Pos);
		DefeatText->SetTileLocation();
		ATileMap::Map[Pos].push_back(DefeatText);
		break;
	}
	case ESpawnType::PushText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> PushText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<APushText>("WallText"));
		PushText->SetTilePosition(Pos);
		PushText->SetTileLocation();
		ATileMap::Map[Pos].push_back(PushText);
		break;
	}
	case ESpawnType::SinkText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> SinkText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ASinkText>("SinkText"));
		SinkText->SetTilePosition(Pos);
		SinkText->SetTileLocation();
		ATileMap::Map[Pos].push_back(SinkText);
		break;
	}
	case ESpawnType::StopText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> StopText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AStopText>("StopText"));
		StopText->SetTilePosition(Pos);
		StopText->SetTileLocation();
		ATileMap::Map[Pos].push_back(StopText);
		break;
	}
	case ESpawnType::WinText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> WinText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWinText>("WinText"));
		WinText->SetTilePosition(Pos);
		WinText->SetTileLocation();
		ATileMap::Map[Pos].push_back(WinText);
		break;
	}
	case ESpawnType::YouText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> YouText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AYouText>("YouText"));
		YouText->SetTilePosition(Pos);
		YouText->SetTileLocation();
		ATileMap::Map[Pos].push_back(YouText);
		break;
	}
	case ESpawnType::Is:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> IsText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AIsText>("IsText"));
		IsText->SetTilePosition(Pos);
		IsText->SetTileLocation();
		ATileMap::Map[Pos].push_back(IsText);
		break;
	}
	case ESpawnType::None:
		break;
	}
}