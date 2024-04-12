#include "PreCompile.h"
#include "TestMap.h"
#include <EngineCore/SpriteRenderer.h>
#include "Baba.h"
#include "StaticHelper.h"
#include "Selector.h"

ATestMap::ATestMap()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	SetRoot(Renderer);
}

ATestMap::~ATestMap()
{

}

void ATestMap::BeginPlay()
{
	Super::BeginPlay();

	float ScreenX = GEngine->EngineWindow.GetWindowScale().X;
	float ScreenY = GEngine->EngineWindow.GetWindowScale().Y;

	SetActorScale3D(FVector(ScreenX * 1.295f, ScreenY * 2.37f, 100.0f));

	FINT::MapSize = FINT(10, 10);
	for (int y = 0; y < FINT::MapSize.Y; y++)
	{
		for (int x = 0; x < FINT::MapSize.X; x++)
		{
			FINT Pos = FINT(x, y);
			std::shared_ptr<ATile> NewTile = std::make_shared<ATile>();
			NewTile->SetPosition(Pos);
			TileMap[Pos] = NewTile;
		}
	}

	FINT Pos = FINT(0, 0);
	std::shared_ptr<ATile> Player = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ABaba>("Baba"));
	TileMap[Pos] = Player;
	Player->SetPosition(Pos);
	Player->SetHasController(true);
	FVector StartPos = Pos.GetFINTToVector();
	Player->SetActorLocation(StartPos);

	FINT TestPos = FINT(2, 0);
	std::shared_ptr<ATile> Test = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ASelector>("Test"));
	TileMap[TestPos] = Test;
	Test->SetCanMove(false);
	Test->SetHasController(false);
	FVector StartTestPos = TestPos.GetFINTToVector();
	Test->SetActorLocation(StartTestPos);

	StaticHelper::CurTileMap = TileMap;
}

void ATestMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	TileUpdate();
}

void ATestMap::TileUpdate()
{
	std::map<FINT, std::shared_ptr<ATile>> NewTileMap;
	for (std::pair<FINT, std::shared_ptr<ATile>> Iterator : TileMap)
	{
		FINT CurMapTilePos = Iterator.first;
		std::shared_ptr<ATile> TileActor = Iterator.second;
		FINT TilePos = TileActor->GetTilePosition();

		if (TilePos != CurMapTilePos)
		{
			NewTileMap[TilePos] = TileActor;
 			NewTileMap[CurMapTilePos] = TileMap[TilePos];
			NewTileMap[CurMapTilePos]->SetPosition(CurMapTilePos);
		}
		NewTileMap[TilePos] = TileActor;
	}

	TileMap.clear();
	TileMap = NewTileMap;
	StaticHelper::CurTileMap = TileMap;
	NewTileMap.clear();
}
