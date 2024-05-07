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
#include "Skull.h"	
#include "SkullText.h"	
#include "HotText.h"
#include "MeltText.h"
#include "Grass.h"
#include "GrassText.h"
#include "MapTile.h"	
#include "MapTileText.h"
#include "AndText.h"

ATileMapEditorGameMode::ATileMapEditorGameMode()
{
}

ATileMapEditorGameMode::~ATileMapEditorGameMode()
{

}

void ATileMapEditorGameMode::SpawnTileActor(FINT _TilePos, ESpawnType _Type)
{
	FINT::MapSize = FINT(33, 18);
	switch (_Type)
	{
	case ESpawnType::Baba:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Player = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ABaba>("Baba"));
		Player->SetTilePosition(Pos);
		Player->SetTileLocation();
		ATileMap::Map[Pos].push_back(Player.get());
		break;
	}
	case ESpawnType::Lava:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Lava = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ALava>("Lava"));
		Lava->SetTilePosition(Pos);
		Lava->SetTileLocation();
		ATileMap::Map[Pos].push_back(Lava.get());
		break;
	}
	case ESpawnType::Wall:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Wall = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWall>("Wall"));
		Wall->SetTilePosition(Pos);
		Wall->SetTileLocation();
		ATileMap::Map[Pos].push_back(Wall.get());
		break;
	}
	case ESpawnType::Water:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Water = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWater>("Water"));
		Water->SetTilePosition(Pos);
		Water->SetTileLocation();
		ATileMap::Map[Pos].push_back(Water.get());
		break;
	}
	case ESpawnType::Flag:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Flag = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AFlag>("Flag"));
		Flag->SetTilePosition(Pos);
		Flag->SetTileLocation();
		ATileMap::Map[Pos].push_back(Flag.get());
		break;
	}
	case ESpawnType::Rock:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Rock = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ARock>("Rock"));
		Rock->SetTilePosition(Pos);
		Rock->SetTileLocation();
		ATileMap::Map[Pos].push_back(Rock.get());
		break;
	}
	case ESpawnType::Grass:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Grass = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AGrass>("Grass"));
		Grass->SetTilePosition(Pos);
		Grass->SetTileLocation();
		ATileMap::Map[Pos].push_back(Grass.get());
		break;
	}
	case ESpawnType::MapTile:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> MapTile = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AMapTile>("MapTile"));
		MapTile->SetTilePosition(Pos);
		MapTile->SetTileLocation();
		ATileMap::Map[Pos].push_back(MapTile.get());
		break;
	}
	case ESpawnType::BabaText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> BabaText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ABabaText>("BabaText"));
		BabaText->SetTilePosition(Pos);
		BabaText->SetTileLocation();
		ATileMap::Map[Pos].push_back(BabaText.get());
		break;
	}
	case ESpawnType::LavaText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> LavaText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ALavaText>("LavaText"));
		LavaText->SetTilePosition(Pos);
		LavaText->SetTileLocation();
		ATileMap::Map[Pos].push_back(LavaText.get());
		break;
	}
	case ESpawnType::WallText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> WallText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWallText>("WallText"));
		WallText->SetTilePosition(Pos);
		WallText->SetTileLocation();
		ATileMap::Map[Pos].push_back(WallText.get());
		break;
	}
	case ESpawnType::WaterText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> WaterText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWaterText>("WaterText"));
		WaterText->SetTilePosition(Pos);
		WaterText->SetTileLocation();
		ATileMap::Map[Pos].push_back(WaterText.get());
		break;
	}
	case ESpawnType::FlagText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> FlagText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AFlagText>("FlagText"));
		FlagText->SetTilePosition(Pos);
		FlagText->SetTileLocation();
		ATileMap::Map[Pos].push_back(FlagText.get());
		break;
	}
	case ESpawnType::RockText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> RockText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ARockText>("RockText"));
		RockText->SetTilePosition(Pos);
		RockText->SetTileLocation();
		ATileMap::Map[Pos].push_back(RockText.get());
		break;
	}
	case ESpawnType::GrassText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> GrassText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AGrassText>("GrassText"));
		GrassText->SetTilePosition(Pos);
		GrassText->SetTileLocation();
		ATileMap::Map[Pos].push_back(GrassText.get());
		break;
	}
	case ESpawnType::MapTileText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> MapTileText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AMapTileText>("MapTileText"));
		MapTileText->SetTilePosition(Pos);
		MapTileText->SetTileLocation();
		ATileMap::Map[Pos].push_back(MapTileText.get());
		break;
	}
	case ESpawnType::DefeatText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> DefeatText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ADefeatText>("DefeatText"));
		DefeatText->SetTilePosition(Pos);
		DefeatText->SetTileLocation();
		ATileMap::Map[Pos].push_back(DefeatText.get());
		break;
	}
	case ESpawnType::PushText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> PushText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<APushText>("WallText"));
		PushText->SetTilePosition(Pos);
		PushText->SetTileLocation();
		ATileMap::Map[Pos].push_back(PushText.get());
		break;
	}
	case ESpawnType::SinkText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> SinkText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ASinkText>("SinkText"));
		SinkText->SetTilePosition(Pos);
		SinkText->SetTileLocation();
		ATileMap::Map[Pos].push_back(SinkText.get());
		break;
	}
	case ESpawnType::StopText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> StopText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AStopText>("StopText"));
		StopText->SetTilePosition(Pos);
		StopText->SetTileLocation();
		ATileMap::Map[Pos].push_back(StopText.get());
		break;
	}
	case ESpawnType::WinText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> WinText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AWinText>("WinText"));
		WinText->SetTilePosition(Pos);
		WinText->SetTileLocation();
		ATileMap::Map[Pos].push_back(WinText.get());
		break;
	}
	case ESpawnType::YouText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> YouText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AYouText>("YouText"));
		YouText->SetTilePosition(Pos);
		YouText->SetTileLocation();
		ATileMap::Map[Pos].push_back(YouText.get());
		break;
	}
	case ESpawnType::Is:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> IsText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AIsText>("IsText"));
		IsText->SetTilePosition(Pos);
		IsText->SetTileLocation();
		ATileMap::Map[Pos].push_back(IsText.get());
		break;
	}
	case ESpawnType::Skull:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> Skull = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ASkull>("Skull"));
		Skull->SetTilePosition(Pos);
		Skull->SetTileLocation();
		ATileMap::Map[Pos].push_back(Skull.get());
		break;
	}
	case ESpawnType::SkullText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> SkullText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ASkullText>("SkullText"));
		SkullText->SetTilePosition(Pos);
		SkullText->SetTileLocation();
		ATileMap::Map[Pos].push_back(SkullText.get());
		break;
	}
	case ESpawnType::HotText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> HotText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AHotText>("HotText"));
		HotText->SetTilePosition(Pos);
		HotText->SetTileLocation();
		ATileMap::Map[Pos].push_back(HotText.get());
		break;
	}
	case ESpawnType::MeltText:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> MeltText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AMeltText>("MeltText"));
		MeltText->SetTilePosition(Pos);
		MeltText->SetTileLocation();
		ATileMap::Map[Pos].push_back(MeltText.get());
		break;
	}
	case ESpawnType::And:
	{
		FINT Pos = _TilePos;
		std::shared_ptr<ATile> AndText = static_pointer_cast<ATile>(GetWorld()->SpawnActor<AAndText>("AndText"));
		AndText->SetTilePosition(Pos);
		AndText->SetTileLocation();
		ATileMap::Map[Pos].push_back(AndText.get());
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

	/*std::shared_ptr<ATileMap> TileMap = GetWorld()->SpawnActor<ATileMap>("TM");
	TileMap->SetTileSize(FINT(10, 10));*/

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
