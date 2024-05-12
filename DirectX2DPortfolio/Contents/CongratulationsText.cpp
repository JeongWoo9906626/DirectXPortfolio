#include "PreCompile.h"
#include "CongratulationsText.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

ACongratulationsText::ACongratulationsText()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	SetRoot(Root);

	for (int i = 0; i < SentenceSize; i++)
	{
		USpriteRenderer* TextAnimationRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
		TextAnimationRenderer->SetOrder(1000);
		TextAnimationRenderer->SetScale(FVector(80.0f, 160.0f));
		TextAnimationRenderer->AddPosition(FVector(-260.0f + 40.0f * i, 0.0f));
		TextVector.push_back(TextAnimationRenderer);
	}
}

ACongratulationsText::~ACongratulationsText()
{

}

void ACongratulationsText::BeginPlay()
{
	Super::BeginPlay();
	CreateTextAnimation();
	SetText();
	RenderOff();
}

void ACongratulationsText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void ACongratulationsText::CreateTextAnimation()
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
	}
}

void ACongratulationsText::SetText()
{
	std::string CurText = "CONGRATULATIONS";
	FVector TextPosition = FVector::Zero;
	float MoveRight = StaticHelper::TileSize;
	for (int i = 0; i < SentenceSize; i++)
	{
		// ¾ËÆÄºª Ã¼Å©
		char Alphabet = CurText[i];
		std::string AlphabetString;
		AlphabetString = std::string(1, Alphabet);
		TextVector[i]->ChangeAnimation(AlphabetString);
	}
}

void ACongratulationsText::RenderOff()
{
	for (int i = 0; i < SentenceSize; i++)
	{
		TextVector[i]->SetActive(false);
	}
}

void ACongratulationsText::RenderOn()
{
	for (int i = 0; i < SentenceSize; i++)
	{
		TextVector[i]->SetActive(true);
	}
}
