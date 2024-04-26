#include "PreCompile.h"
#include "TileMapEditorGameMode.h"
#include "StaticHelper.h"
#include "TileMap.h"
#include "TestMap.h"

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

ATileMapEditorGameMode::ATileMapEditorGameMode()
{
}

ATileMapEditorGameMode::~ATileMapEditorGameMode()
{

}

void ATileMapEditorGameMode::SpawnTileActor(FINT _TilePos, ESpawnType _Type)
{
	switch (_Type)
	{
	case ESpawnType::Baba:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Player = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ABaba>("Baba"));
		Player->SetTilePosition(Pos);
		Player->SetTileLocation();
		StaticHelper::NewTileMap->Map[Pos].push_back(Player);
		break;
	}
	case ESpawnType::Lava:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Lava = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ALava>("Lava"));
		Lava->SetTilePosition(Pos);
		Lava->SetTileLocation();
		StaticHelper::NewTileMap->Map[Pos].push_back(Lava);
		break;
	}
	case ESpawnType::Wall:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Wall = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWall>("Wall"));
		Wall->SetTilePosition(Pos);
		Wall->SetTileLocation();
		StaticHelper::NewTileMap->Map[Pos].push_back(Wall);
		break;
	}
	case ESpawnType::Water:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Water = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWater>("Water"));
		Water->SetTilePosition(Pos);
		Water->SetTileLocation();
		StaticHelper::NewTileMap->Map[Pos].push_back(Water);
		break;
	}
	case ESpawnType::Flag:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Flag = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AFlag>("Flag"));
		Flag->SetTilePosition(Pos);
		Flag->SetTileLocation();
		StaticHelper::NewTileMap->Map[Pos].push_back(Flag);
		break;
	}
	case ESpawnType::Rock:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Rock = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ARock>("Rock"));
		Rock->SetTilePosition(Pos);
		Rock->SetTileLocation();
		StaticHelper::NewTileMap->Map[Pos].push_back(Rock);
		break;
	}
	case ESpawnType::BabaText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> BabaText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ABabaText>("BabaText"));
		BabaText->SetTilePosition(Pos);
		BabaText->SetTileLocation();
		StaticHelper::NewTileMap->Map[Pos].push_back(BabaText);
		break;
	}
	case ESpawnType::LavaText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> LavaText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ALavaText>("LavaText"));
		LavaText->SetTilePosition(Pos);
		LavaText->SetTileLocation();
		StaticHelper::NewTileMap->Map[Pos].push_back(LavaText);
		break;
	}
	case ESpawnType::WallText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> WallText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWallText>("WallText"));
		WallText->SetTilePosition(Pos);
		WallText->SetTileLocation();
		StaticHelper::NewTileMap->Map[Pos].push_back(WallText);
		break;
	}
	case ESpawnType::WaterText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> WaterText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWaterText>("WaterText"));
		WaterText->SetTilePosition(Pos);
		WaterText->SetTileLocation();
		StaticHelper::NewTileMap->Map[Pos].push_back(WaterText);
		break;
	}
	case ESpawnType::FlagText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> FlagText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AFlagText>("FlagText"));
		FlagText->SetTilePosition(Pos);
		FlagText->SetTileLocation();
		StaticHelper::NewTileMap->Map[Pos].push_back(FlagText);
		break;
	}
	case ESpawnType::RockText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> RockText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ARockText>("RockText"));
		RockText->SetTilePosition(Pos);
		RockText->SetTileLocation();
		StaticHelper::NewTileMap->Map[Pos].push_back(RockText);
		break;
	}
	case ESpawnType::DefeatText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> DefeatText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ADefeatText>("DefeatText"));
		DefeatText->SetTilePosition(Pos);
		DefeatText->SetTileLocation();
		StaticHelper::NewTileMap->Map[Pos].push_back(DefeatText);
		break;
	}
	case ESpawnType::PushText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> PushText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<APushText>("WallText"));
		PushText->SetTilePosition(Pos);
		PushText->SetTileLocation();
		StaticHelper::NewTileMap->Map[Pos].push_back(PushText);
		break;
	}
	case ESpawnType::SinkText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> SinkText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ASinkText>("SinkText"));
		SinkText->SetTilePosition(Pos);
		SinkText->SetTileLocation();
		StaticHelper::NewTileMap->Map[Pos].push_back(SinkText);
		break;
	}
	case ESpawnType::StopText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> StopText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AStopText>("StopText"));
		StopText->SetTilePosition(Pos);
		StopText->SetTileLocation();
		StaticHelper::NewTileMap->Map[Pos].push_back(StopText);
		break;
	}
	case ESpawnType::WinText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> WinText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWinText>("WinText"));
		WinText->SetTilePosition(Pos);
		WinText->SetTileLocation();
		StaticHelper::NewTileMap->Map[Pos].push_back(WinText);
		break;
	}
	case ESpawnType::YouText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> YouText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AYouText>("YouText"));
		YouText->SetTilePosition(Pos);
		YouText->SetTileLocation();
		StaticHelper::NewTileMap->Map[Pos].push_back(YouText);
		break;
	}
	case ESpawnType::Is:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> IsText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AIsText>("IsText"));
		IsText->SetTilePosition(Pos);
		IsText->SetTileLocation();
		StaticHelper::NewTileMap->Map[Pos].push_back(IsText);
		break;
	}
	case ESpawnType::None:
		break;
	}
}

void ATileMapEditorGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	std::shared_ptr<ATileMap> TileMap = GetWorld()->SpawnActor<ATileMap>("TM");
	TileMap->SetTileSize(FINT(10, 10));

	GetWorld()->SpawnActor<ATestMap>("TestMap");
}

void ATileMapEditorGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ATileMapEditorGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void ATileMapEditorGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}
