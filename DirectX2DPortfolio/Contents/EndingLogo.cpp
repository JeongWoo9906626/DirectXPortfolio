#include "PreCompile.h"
#include "EndingLogo.h"
#include "TextActor.h"


AEndingLogo::AEndingLogo()
{
}

AEndingLogo::~AEndingLogo()
{
}

void AEndingLogo::BeginPlay()
{
	Super::BeginPlay();

	std::string EndingText = "THANK YOU";
	int Len = EndingText.size();
	for (int i = 0; i < Len; i++)
	{
		TextActor* Text = GetWorld()->SpawnActor<TextActor>("Text").get();
		std::string Alphabet = std::string(1, EndingText[i]);
		if (Alphabet._Equal(" "))
		{
			Text->SetText("Blank");
		}
		else
		{
			Text->SetText(Alphabet);
		}
		Text->SetActorLocation(StartPos);
		Text->SetScale(TitleScale);
		Text->SetColor(FVector(217, 57, 106));
		StartPos += AddNext;
	}
}

void AEndingLogo::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
