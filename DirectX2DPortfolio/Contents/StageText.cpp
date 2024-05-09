#include "PreCompile.h"
#include "StageText.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"
#include "Selector.h"
#include "SelectTile.h"

AStageText::AStageText()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	SetRoot(Root);

	FVector ActorPosition = this->GetActorLocation();
	for (int i = 0; i < SentenceSize; i++)
	{
		ActorPosition.X += i * 100.0f;
		USpriteRenderer* TextAnimationRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
		TextAnimationRenderer->SetOrder(1000);
		TextAnimationRenderer->SetScale(FVector(36.0f, 36.0f));
		TextAnimationRenderer->AddPosition(FVector(- 600.0f + 18.0f * i, 340.0f));
		TextVector.push_back(TextAnimationRenderer);
	}
}

AStageText::~AStageText()
{

}

void AStageText::BeginPlay()
{
	Super::BeginPlay();
	CreateTextAnimation();
}

void AStageText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	CurPos = StaticHelper::CurSelector->GetTilePosition();
	if (CurPos != PrevPos)
	{
		TextChange();
		PrevPos = CurPos;
	}
}

void AStageText::CreateTextAnimation()
{
	for (int i = 0; i < SentenceSize; i++)
	{
		std::vector<float> AnimationFrame = { 0.1f };
		std::vector<int> TextAnimationIndex;
		std::to_string(char('A'));

		for (char ch = 'A'; ch <= 'Z'; ch++)
		{
			int Index = static_cast<int>(ch) - static_cast<int>('A');
			std::string Alphabet = std::string(1, ch);

			if (Index <= 6)
			{
				// 0 ~ 6 (A ~ G)
				TextAnimationIndex = { 0 + Index };
			}
			else if (Index <= 13)
			{
				// 7 ~ 13 (H ~ N)
				TextAnimationIndex = { 14 + Index };
			}
			else if (Index <= 20)
			{
				// 14 ~ 20 (O ~ U)
				TextAnimationIndex = { 28 + Index };
			}
			else
			{
				// 21 ~ 25 (V ~ Z)
				TextAnimationIndex = { 42 + Index };
			}

			TextVector[i]->CreateAnimation(Alphabet, "WhiteAlphabet.png", AnimationFrame, TextAnimationIndex);
		}
		TextVector[i]->CreateAnimation("Blank", "WhiteAlphabet.png", AnimationFrame, { 78 });
	}
}

void AStageText::TextChange()
{
	std::string CurText = UEngineString::ToUpper(StaticHelper::CurSelectTileMap[CurPos]->SelectInfo.StageText);
	int Len = CurText.size();

	FVector TextPosition = FVector::Zero;
	float MoveRight = StaticHelper::TileSize;
	for (int i = 0; i < SentenceSize; i++)
	{
		TextPosition.X += i * MoveRight;
		if (i < Len)
		{
			// ¾ËÆÄºª Ã¼Å©
			char Alphabet = CurText[i];
			std::string AlphabetString;
			if (Alphabet == ' ')
			{
				AlphabetString = "Blank";
			}
			else
			{
				AlphabetString = std::string(1, Alphabet);
			}

			TextVector[i]->ChangeAnimation(AlphabetString);
		}
		else
		{
			TextVector[i]->ChangeAnimation("Blank");
		}
	}
}

