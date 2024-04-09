#include "PreCompile.h"
#include "Baba.h"
#include <EngineCore/SpriteRenderer.h>

ABaba::ABaba()
{
	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	InputOn();
}

ABaba::~ABaba()
{

}

void ABaba::BeginPlay()
{
	Super::BeginPlay();

	SetMoveRange(100.0f);

	SetActorScale3D(FVector(1000.0f, 1000.0f, 20.0f));
	Renderer->CreateAnimation("BabaMove_Left", "Baba.png", 0.1f, true, 9, 12);
	Renderer->CreateAnimation("BabaMove_Right", "Baba.png", 0.1f, true, 1, 4);
	Renderer->CreateAnimation("BabaMove_Up", "Baba.png", 0.1f, true, 5, 8);
	Renderer->CreateAnimation("BabaMove_Down", "Baba.png", 0.1f, true, 13, 16);

	Renderer->CreateAnimation("BabaIdle_Left", "Baba.png", 0.1f, true, 9, 9);
	Renderer->CreateAnimation("BabaIdle_Right", "Baba.png", 0.1f, true, 1, 1);
	Renderer->CreateAnimation("BabaIdle_Up", "Baba.png", 0.1f, true, 5, 5);
	Renderer->CreateAnimation("BabaIdle_Down", "Baba.png", 0.1f, true, 13, 13);

	Renderer->ChangeAnimation("BabaIdle_Right");
	Renderer->SetOrder(ERenderOrder::Player);
}

void ABaba::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void ABaba::MoveSet()
{
	Super::MoveSet();
	EActorDir CurDir = GetCurDir();

	switch (CurDir)
	{
	case EActorDir::Left:
		Renderer->ChangeAnimation("BabaMove_Left");
		break;
	case EActorDir::Right:
		Renderer->ChangeAnimation("BabaMove_Right");
		break;
	case EActorDir::Up:
		Renderer->ChangeAnimation("BabaMove_Up");
		break;
	case EActorDir::Down:
		Renderer->ChangeAnimation("BabaMove_Down");
		break;
	}
}
