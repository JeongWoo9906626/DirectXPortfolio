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

	FVector Pos = FVector(-135, 108);
	FVector TitleScale = FVector(54, 162);
	{
		std::shared_ptr<TextActor> B = GetWorld()->SpawnActor<TextActor>("B");
		B->SetText("B");
		B->SetActorLocation(Pos);
		B->SetScale(TitleScale);
		B->SetColor(FVector(217, 57, 106));
	}

	{
		Pos += FVector(27, 0);
		std::shared_ptr<TextActor> A = GetWorld()->SpawnActor<TextActor>("A");
		A->SetText("A");
		A->SetActorLocation(Pos);
		A->SetScale(TitleScale);
		A->SetColor(FVector(217, 57, 106));
	}

	{
		Pos += FVector(27, 0);
		std::shared_ptr<TextActor> B = GetWorld()->SpawnActor<TextActor>("B");
		B->SetText("B");
		B->SetActorLocation(Pos);
		B->SetScale(TitleScale);
		B->SetColor(FVector(217, 57, 106));
	}

	{
		Pos += FVector(27, 0);
		std::shared_ptr<TextActor> A = GetWorld()->SpawnActor<TextActor>("A");
		A->SetText("A");
		A->SetActorLocation(Pos);
		A->SetScale(TitleScale);
		A->SetColor(FVector(217, 57, 106));
	}

	{
		Pos += FVector(54, 0);
		std::shared_ptr<TextActor> I = GetWorld()->SpawnActor<TextActor>("I");
		I->SetText("I");
		I->SetActorLocation(Pos);
		I->SetScale(TitleScale);
	}

	{
		Pos += FVector(27, 0);
		std::shared_ptr<TextActor> S = GetWorld()->SpawnActor<TextActor>("S");
		S->SetText("S");
		S->SetActorLocation(Pos);
		S->SetScale(TitleScale);
	}

	{
		Pos += FVector(54, 0);
		std::shared_ptr<TextActor> Y = GetWorld()->SpawnActor<TextActor>("Y");
		Y->SetText("Y");
		Y->SetActorLocation(Pos);
		Y->SetScale(TitleScale);
		Y->SetColor(FVector(217, 57, 106));
	}

	{
		Pos += FVector(27, 0);
		std::shared_ptr<TextActor> O = GetWorld()->SpawnActor<TextActor>("O");
		O->SetText("O");
		O->SetActorLocation(Pos);
		O->SetScale(TitleScale);
		O->SetColor(FVector(217, 57, 106));
	}

	{
		Pos += FVector(27, 0);
		std::shared_ptr<TextActor> U = GetWorld()->SpawnActor<TextActor>("U");
		U->SetText("U");
		U->SetActorLocation(Pos);
		U->SetScale(TitleScale);
		U->SetColor(FVector(217, 57, 106));
	}
}

void ATitleLogo::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}