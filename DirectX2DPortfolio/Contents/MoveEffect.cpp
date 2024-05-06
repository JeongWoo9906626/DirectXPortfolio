#include "PreCompile.h"
#include "MoveEffect.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

AMoveEffect::AMoveEffect()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	Root->SetScale(FVector(StaticHelper::TileSize / 2, StaticHelper::TileSize / 2, 20.0f));
	SetRoot(Root);

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
}

AMoveEffect::~AMoveEffect()
{

}

void AMoveEffect::SetColorByTile(float4 _MulColor)
{
	Renderer->SetMulColor(_MulColor);
}

void AMoveEffect::BeginPlay()
{
	Super::BeginPlay();

	Renderer->SetSprite("Dust0.png");
	Renderer->SetOrder(ERenderOrder::Effect);
	CurEffectTime = EffectTime;
	Scale = GetActorScale3D();
}

void AMoveEffect::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (false == IsSetting)
	{
		PositionSetting();
		IsSetting = true;
	}

	if (CurEffectTime <= 0.0f)
	{
		CurEffectTime = 0.0f;
		Destroy();
	}
	CurEffectTime -= _DeltaTime;
	MoveEffectOn(CurEffectTime);
	
}

void AMoveEffect::PositionSetting()
{
	switch (Input)
	{
	case EInputType::L:
		MediatePos = FVector(StaticHelper::TileSize / 2, 0.0f);
		break;
	case EInputType::R:
		MediatePos = FVector(-1 * StaticHelper::TileSize / 2, 0.0f);
		break;
	case EInputType::U:
		MediatePos = FVector(0.0f, -1 * StaticHelper::TileSize / 2);
		break;
	case EInputType::D:
		MediatePos = FVector(0.0f, StaticHelper::TileSize / 2);
		break;
	}

	CurPos = GetActorLocation();
	NextPos = CurPos + MediatePos;
}

void AMoveEffect::MoveEffectOn(float _CurEffectTime)
{
	float t = (EffectTime - _CurEffectTime) / EffectTime;

	FVector Pos;
	Pos.X = CurPos.X * (1 - t) + NextPos.X * t;
	Pos.Y = CurPos.Y * (1 - t) + NextPos.Y * t;

	Pos.X = static_cast<int>(std::lround(Pos.X));
	Pos.Y = static_cast<int>(std::lround(Pos.Y));

	FVector CurScale;
	CurScale.X = Scale.X * (1 - t);
	CurScale.Y = Scale.Y * (1 - t);
	
	SetActorScale3D(CurScale);
	SetActorLocation(Pos);
}
