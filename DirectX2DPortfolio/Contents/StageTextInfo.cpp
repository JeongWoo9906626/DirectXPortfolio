#include "PreCompile.h"
#include "StageTextInfo.h"
#include "TextActor.h"

AStageTextInfo::AStageTextInfo()
{
}

AStageTextInfo::~AStageTextInfo()
{
}

void AStageTextInfo::BeginPlay()
{
	Super::BeginPlay();
}

void AStageTextInfo::Tick(float _DeltaTime)
{
 	Super::Tick(_DeltaTime);

	if (true == StaticHelper::IsTextDestroy)
	{
		int Len = TextVector.size();
		for (int i = 0; i < Len; i++)
		{
			TextActor* Text = TextVector[i];
			if (nullptr != Text)
			{
				Text->Destroy();
				Text = nullptr;
			}
		}
		TextVector.clear();
		StartPos = FVector(-280, -108);
	}

	if (false == StaticHelper::IsStageTextChange)
	{
		StaticHelper::IsTextDestroy = false;
		StaticHelper::IsStageTextChange = true;
		std::string StageText = StaticHelper::StageText;
		int TextLen = StageText.size();

		StartPos = FVector(-56, 0) * (TextLen / 2);
		StartPos += FVector(0, -108);

		for (int i = 0; i < TextLen; i++)
		{
			TextVector.push_back(GetWorld()->SpawnActor<TextActor>("Text").get());
			std::string Alphabet = std::string(1, StageText[i]);
			if (Alphabet._Equal(" "))
			{
				TextVector[i]->SetText("Blank");
			}
			else
			{
				TextVector[i]->SetText(Alphabet);
			}
			TextVector[i]->SetActorLocation(StartPos);
			TextVector[i]->SetScale(TitleScale);
			StartPos += AddNext;
		}
	}
}
