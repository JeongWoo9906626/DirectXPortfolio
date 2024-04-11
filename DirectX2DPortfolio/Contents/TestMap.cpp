#include "PreCompile.h"
#include "TestMap.h"
#include <EngineCore/SpriteRenderer.h>
#include "Baba.h"

ATestMap::ATestMap()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");


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

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			FINT Pos = FINT(x, y);
			std::shared_ptr<ATile> NewTile = std::make_shared<ATile>();
			NewTile->SetPosition(Pos);
			TilePos[Pos] = NewTile;
		}
	}

	FINT Pos = FINT(2, 2);
	std::shared_ptr<ATile> Player = static_pointer_cast<ATile>(GetWorld()->SpawnActor<ABaba>("Baba"));
	TilePos[Pos] = Player;
	Player->SetPosition(Pos);
	FVector StartPos = { Pos.X * 128.0f, Pos.Y * 128.0f };
	Player->SetActorLocation(StartPos);
}

void ATestMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}