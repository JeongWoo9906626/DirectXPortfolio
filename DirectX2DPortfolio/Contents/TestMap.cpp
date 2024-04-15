#include "PreCompile.h"
#include "TestMap.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

ATestMap::ATestMap()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);

	SetRoot(Root);
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
}

void ATestMap::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	/*StaticHelper::CurTileMap = TileMap;
	TileUpdate();*/
	//StaticHelper::CurTileMap = TileMap;
}

//void ATestMap::TileUpdate()
//{
//	std::map<FINT, std::shared_ptr<ATile>> NewTileMap;
//	for (std::pair<FINT, std::shared_ptr<ATile>> Iterator : TileMap)
//	{
//		FINT CurMapTilePos = Iterator.first;
//		std::shared_ptr<ATile> TileActor = Iterator.second;
//		FINT TilePos = TileActor->GetTilePosition();
//
//		if (TilePos != CurMapTilePos)
//		{
//			NewTileMap[TilePos] = TileActor;
// 			NewTileMap[CurMapTilePos] = TileMap[TilePos];
//			NewTileMap[CurMapTilePos]->SetPosition(CurMapTilePos);
//		}
//		else
//		{
//			NewTileMap[TilePos] = TileActor;
//		}
//	}
//
//	TileMap.clear();
//	TileMap = NewTileMap;
//	NewTileMap.clear();
//}
