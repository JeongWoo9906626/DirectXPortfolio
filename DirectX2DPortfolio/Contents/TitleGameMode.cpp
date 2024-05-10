#include "PreCompile.h"
#include "TitleGameMode.h"
#include "TitleLogo.h"
#include <EngineCore/Camera.h>
#include "EngineCore/Image.h"

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

	if (true == UEngineInput::IsDown(VK_UP))
	{
		TitleBaba->SetPosition(FVector(-330, -100));
	}
	if (true == UEngineInput::IsDown(VK_DOWN))
	{
		TitleBaba->SetPosition(FVector(-330, -200));
	}
	if (true == UEngineInput::IsDown(VK_SPACE))
	{
		if (-100 == static_cast<int>(TitleBaba->GetLocalPosition().Y))
		{
			GEngine->ChangeLevel("SelectLevel");
		}
		if (-200 == static_cast<int>(TitleBaba->GetLocalPosition().Y))
		{
			GEngine->EngineWindow.Off();
		}
	}
}

void ATitleGameMode::LevelEnd(ULevel* _NextLevel)
{
	Super::LevelEnd(_NextLevel);
}

void ATitleGameMode::LevelStart(ULevel* _PrevLevel)
{
	Super::LevelStart(_PrevLevel);

}