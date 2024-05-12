#include "PreCompile.h"
#include "EndingGameMode.h"
#include "EndingLogo.h"
#include <EngineCore/Camera.h>
#include "EngineCore/Image.h"
#include "FadeInEffect.h"
#include "FadeOutEffect.h"

AEndingGameMode::AEndingGameMode()
{
	InputOn();
}

AEndingGameMode::~AEndingGameMode()
{
}

void AEndingGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	std::shared_ptr<AEndingLogo> EndingLogo = GetWorld()->SpawnActor<AEndingLogo>("EndingLogo");
}

void AEndingGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown(VK_SPACE))
	{
		IsEnding = true;
	}

	if (true == IsEnding)
	{
		LevelChangeEffect(_DeltaTime);
	}
}

void AEndingGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
	AnimationEnd = false;
}

void AEndingGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);
}

void AEndingGameMode::LevelChangeEffect(float _DeltaTime)
{

	if (false == AnimationEnd)
	{
		if (false == AnimationEndInit)
		{
			FadeOut = GetWorld()->GetLastTarget()->AddEffect<UFadeOutEffect>();
			FadeOut->ResetTime();
			FadeOut.get()->Active(true);
			AnimationEndInit = true;
		}
		if (CurEndEffectTime >= EndEffectTime)
		{
			IsEnding = false;
			FadeOut.get()->Active(false);
			AnimationEnd = true;
			AnimationEndInit = false;
			CurEndEffectTime = 0.0f;
			GEngine->EngineWindow.Off();
			return;
		}
		CurEndEffectTime += _DeltaTime;
	}
}
