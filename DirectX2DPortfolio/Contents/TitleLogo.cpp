#include "PreCompile.h"
#include "TitleLogo.h"
#include "TextActor.h"

ATitleLogo::ATitleLogo()
{
}

ATitleLogo::~ATitleLogo()
{
}

void ATitleLogo::BeginPlay()
{
	Super::BeginPlay();

	{
		TextActor* B = GetWorld()->SpawnActor<TextActor>("B").get();
		B->SetText("B");
		B->SetActorLocation(StartPos);
		B->SetScale(TitleScale);
		B->SetColor(FVector(217, 57, 106));
	}

	{
		StartPos += AddNext;
		TextActor* A = GetWorld()->SpawnActor<TextActor>("A").get();
		A->SetText("A");
		A->SetActorLocation(StartPos);
		A->SetScale(TitleScale);
		A->SetColor(FVector(217, 57, 106));
	}

	{
		StartPos += AddNext;
		TextActor* B = GetWorld()->SpawnActor<TextActor>("B").get();
		B->SetText("B");
		B->SetActorLocation(StartPos);
		B->SetScale(TitleScale);
		B->SetColor(FVector(217, 57, 106));
	}

	{
		StartPos += AddNext;
		TextActor* A = GetWorld()->SpawnActor<TextActor>("A").get();
		A->SetText("A");
		A->SetActorLocation(StartPos);
		A->SetScale(TitleScale);
		A->SetColor(FVector(217, 57, 106));
	}

	{
		StartPos += AddNext * 2;
		TextActor* I = GetWorld()->SpawnActor<TextActor>("I").get();
		I->SetText("I");
		I->SetActorLocation(StartPos);
		I->SetScale(TitleScale);
	}

	{
		StartPos += AddNext;
		TextActor* S = GetWorld()->SpawnActor<TextActor>("S").get();
		S->SetText("S");
		S->SetActorLocation(StartPos);
		S->SetScale(TitleScale);
	}

	{
		StartPos += AddNext * 2;
		TextActor* Y = GetWorld()->SpawnActor<TextActor>("Y").get();
		Y->SetText("Y");
		Y->SetActorLocation(StartPos);
		Y->SetScale(TitleScale);
		Y->SetColor(FVector(217, 57, 106));
	}

	{
		StartPos += AddNext;
		TextActor* O = GetWorld()->SpawnActor<TextActor>("O").get();
		O->SetText("O");
		O->SetActorLocation(StartPos);
		O->SetScale(TitleScale);
		O->SetColor(FVector(217, 57, 106));
	}

	{
		StartPos += AddNext;
		TextActor* U = GetWorld()->SpawnActor<TextActor>("U").get();
		U->SetText("U");
		U->SetActorLocation(StartPos);
		U->SetScale(TitleScale);
		U->SetColor(FVector(217, 57, 106));
	}
}

void ATitleLogo::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}