#include "PreCompile.h"
#include "StageNumberText.h"
#include "TextActor.h"

AStageNumberText::AStageNumberText()
{
}

AStageNumberText::~AStageNumberText()
{
}

void AStageNumberText::BeginPlay()
{
	Super::BeginPlay();

	std::string StageNumber = "LEVEL ";
	int Len = 6;
	for (int i = 0; i < Len; i++)
	{
		TextActor* Text = GetWorld()->SpawnActor<TextActor>("Text").get();
		std::string Alphabet = std::string(1, StageNumber[i]);
		if (Alphabet._Equal(" "))
		{
			Text->SetText("Blank");
		}
		else
		{
			Text->SetText(std::string(1, StageNumber[i]));
		}
		Text->SetActorLocation(StartPos);
  		Text->SetScale(TitleScale);
		Text->SetColor(FVector(217, 57, 106));

		StartPos += AddNext;
	}
}

void AStageNumberText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (true == StaticHelper::IsNumberDestroy)
	{
		if (nullptr != NumberText)
		{
			NumberText->Destroy();
			NumberText = nullptr;
		}
	}
	if (false == StaticHelper::IsStageNumberChange)
	{
		StaticHelper::IsNumberDestroy = false;
		StaticHelper::IsStageNumberChange = true;
		NumberText = GetWorld()->SpawnActor<TextActor>("Text").get();
		StaticHelper::StageNumber;
		std::string Alphabet = StaticHelper::StageNumber.substr(6, 1);
		NumberText->SetText(Alphabet);
		NumberText->SetActorLocation(StartPos);
		NumberText->SetScale(TitleScale * 2);
		NumberText->SetColor(FVector(217, 57, 106));
	}
	
}
