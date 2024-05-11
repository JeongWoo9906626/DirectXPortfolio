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

	{
		std::shared_ptr<TextActor> B = GetWorld()->SpawnActor<TextActor>("B");
		B->SetText("B");
		B->SetActorLocation(StartPos);
		B->SetScale(TitleScale);
		B->SetColor(FVector(217, 57, 106));
	}

	{
		StartPos += AddNext;
		std::shared_ptr<TextActor> A = GetWorld()->SpawnActor<TextActor>("A");
		A->SetText("A");
		A->SetActorLocation(StartPos);
		A->SetScale(TitleScale);
		A->SetColor(FVector(217, 57, 106));
	}

	{
		StartPos += AddNext;
		std::shared_ptr<TextActor> B = GetWorld()->SpawnActor<TextActor>("B");
		B->SetText("B");
		B->SetActorLocation(StartPos);
		B->SetScale(TitleScale);
		B->SetColor(FVector(217, 57, 106));
	}

	{
		StartPos += AddNext;
		std::shared_ptr<TextActor> A = GetWorld()->SpawnActor<TextActor>("A");
		A->SetText("A");
		A->SetActorLocation(StartPos);
		A->SetScale(TitleScale);
		A->SetColor(FVector(217, 57, 106));
	}

	{
		StartPos += AddNext * 2;
		std::shared_ptr<TextActor> I = GetWorld()->SpawnActor<TextActor>("I");
		I->SetText("I");
		I->SetActorLocation(StartPos);
		I->SetScale(TitleScale);
	}

	{
		StartPos += AddNext;
		std::shared_ptr<TextActor> S = GetWorld()->SpawnActor<TextActor>("S");
		S->SetText("S");
		S->SetActorLocation(StartPos);
		S->SetScale(TitleScale);
	}

	{
		StartPos += AddNext * 2;
		std::shared_ptr<TextActor> Y = GetWorld()->SpawnActor<TextActor>("Y");
		Y->SetText("Y");
		Y->SetActorLocation(StartPos);
		Y->SetScale(TitleScale);
		Y->SetColor(FVector(217, 57, 106));
	}

	{
		StartPos += AddNext;
		std::shared_ptr<TextActor> O = GetWorld()->SpawnActor<TextActor>("O");
		O->SetText("O");
		O->SetActorLocation(StartPos);
		O->SetScale(TitleScale);
		O->SetColor(FVector(217, 57, 106));
	}

	{
		StartPos += AddNext;
		std::shared_ptr<TextActor> U = GetWorld()->SpawnActor<TextActor>("U");
		U->SetText("U");
		U->SetActorLocation(StartPos);
		U->SetScale(TitleScale);
		U->SetColor(FVector(217, 57, 106));
	}
}

void AStageNumberText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
