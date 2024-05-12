#include "PreCompile.h"
#include "TitleGameMode.h"
#include "TitleLogo.h"
#include <EngineCore/Camera.h>
#include "EngineCore/Image.h"
#include "FadeInEffect.h"

#include "FadeOutEffect.h"

ATitleGameMode::ATitleGameMode()
{
	InputOn();
}

ATitleGameMode::~ATitleGameMode()
{
}

void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();

	std::shared_ptr<UCamera> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(FVector(0.0f, 0.0f, -100.0f));

	std::shared_ptr<ATitleLogo> TitleLogo = GetWorld()->SpawnActor<ATitleLogo>("TitleLogo");

	UImage* Start = CreateWidget<UImage>(GetWorld(), "Start");
	Start->AddToViewPort(1);
	Start->SetSprite("StartButton.png");
	Start->SetScale({ 589,76 });
	Start->SetPosition(FVector(0, -100));

	UImage* Exit = CreateWidget<UImage>(GetWorld(), "Exit");
	Exit->AddToViewPort(1);
	Exit->SetSprite("ExitButton.png");
	Exit->SetScale({ 589,76 });
	Exit->SetPosition(FVector(0, -200));

	TitleBaba = CreateWidget<UImage>(GetWorld(), "TitleBaba");
	TitleBaba->AddToViewPort(1);
	TitleBaba->CreateAnimation("TitleBaba", "BABA.png", { 0.1f, 0.1f, 0.1f }, { 1, 18, 35 }, true);
	TitleBaba->ChangeAnimation("TitleBaba");
	TitleBaba->SetScale({ 54, 54 });
	TitleBaba->SetPosition(FVector(-330, -100));
}

void ATitleGameMode::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == IsLevelChange)
	{
		LevelChangeEffect(_DeltaTime);
	}
	else
	{
		if (true == UEngineInput::IsDown(VK_UP))
		{
			TitleBaba->SetPosition(FVector(-330, -100));
			UEngineSound::SoundPlay("OptionSelectSound.ogg");
		}
		if (true == UEngineInput::IsDown(VK_DOWN))
		{
			TitleBaba->SetPosition(FVector(-330, -200));
			UEngineSound::SoundPlay("OptionSelectSound.ogg");
		}
		if (true == UEngineInput::IsDown(VK_SPACE))
		{
			if (-100 == static_cast<int>(TitleBaba->GetLocalPosition().Y))
			{
				IsLevelChange = true;
				BGM.Off();
				SelectSound = UEngineSound::SoundPlay("Click.ogg");
			}
			if (-200 == static_cast<int>(TitleBaba->GetLocalPosition().Y))
			{
				GEngine->EngineWindow.Off();
			}
		}
	}
}

void ATitleGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);

	AnimationEnd = false;
	BGM.Off();
}

void ATitleGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

	BGM = UEngineSound::SoundPlay("TitleBGM.mp3");
	BGM.Loop(1000);
}

void ATitleGameMode::LevelChangeEffect(float _DeltaTime)
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
			FadeOut.get()->Active(false);
			AnimationEnd = true;
			AnimationEndInit = false;
			CurEndEffectTime = 0.0f;
			IsLevelChange = false;
			GEngine->ChangeLevel("SelectLevel");
			return;
		}
		CurEndEffectTime += _DeltaTime;
	}
}
