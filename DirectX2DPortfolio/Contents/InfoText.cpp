#include "PreCompile.h"
#include "InfoText.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

AInfoText::AInfoText()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	SetRoot(Root);

	for (int i = 0; i < Size; i++)
	{
		USpriteRenderer* TextAnimationRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
		TextAnimationRenderer->SetOrder(1000);
		TextAnimationRenderer->SetScale(FVector(32.0f, 36.0f));
		TextAnimationRenderer->AddPosition(FVector(-150.0f + 12.0f * i, 340.0f));
		UndoVector.push_back(TextAnimationRenderer);
	}

	for (int i = 0; i < Size; i++)
	{
		USpriteRenderer* TextAnimationRenderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
		TextAnimationRenderer->SetOrder(1000);
		TextAnimationRenderer->SetScale(FVector(32.0f, 36.0f));
		TextAnimationRenderer->AddPosition(FVector(150.0f + 12.0f * i, 340.0f));
		RestartVector.push_back(TextAnimationRenderer);
	}

	UndoVector[0]->SetScale(FVector(40.0f, 40.0f));
	RestartVector[0]->SetScale(FVector(40.0f, 40.0f));
}

AInfoText::~AInfoText()
{

}

void AInfoText::BeginPlay()
{
	Super::BeginPlay();
	CreateTextAnimation();
	UndoTextChange();
	RestartTextChange();
	RenderOff();
}

void AInfoText::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void AInfoText::CreateTextAnimation()
{
	for (int i = 0; i < Size; i++)
	{
		std::vector<float> AnimationFrame = { 0.1f, 0.1f, 0.1f };
		std::vector<int> TextAnimationIndex;
		std::to_string(char('A'));

		for (char ch = 'A'; ch <= 'Z'; ch++)
		{
			int Index = static_cast<int>(ch) - static_cast<int>('A');
			std::string Alphabet = std::string(1, ch);

			if (Index <= 6)
			{
				// 0 ~ 6 (A ~ G)
				TextAnimationIndex = { 0 + Index, 7 + Index, 14 + Index };
			}
			else if (Index <= 13)
			{
				// 7 ~ 13 (H ~ N)
				TextAnimationIndex = { 14 + Index, 21 + Index, 28 + Index };
			}
			else if (Index <= 20)
			{
				// 14 ~ 20 (O ~ U)(42,49,56)
				TextAnimationIndex = { 28 + Index, 35 + Index, 42 + Index };
			}
			else
			{
				// 21 ~ 25 (V ~ Z) (63, 68, 73
				TextAnimationIndex = { 42 + Index , 47 + Index, 52 + Index };
			}

			UndoVector[i]->CreateAnimation("Info" + Alphabet, "WhiteAlphabet.png", AnimationFrame, TextAnimationIndex);
			RestartVector[i]->CreateAnimation("Restart" + Alphabet, "WhiteAlphabet.png", AnimationFrame, TextAnimationIndex);
		}
		UndoVector[i]->CreateAnimation("InfoBlank", "WhiteAlphabet.png", AnimationFrame, { 78 });
		RestartVector[i]->CreateAnimation("RestartBlank", "WhiteAlphabet.png", AnimationFrame, { 78 });
	}
}

void AInfoText::UndoTextChange()
{
	std::string CurText = "Z Undo";
	int Len = CurText.size();

	FVector TextPosition = FVector::Zero;
	float MoveRight = StaticHelper::TileSize;
	for (int i = 0; i < Size; i++)
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

			UndoVector[i]->ChangeAnimation("Info" + AlphabetString);
		}
		else
		{
			UndoVector[i]->ChangeAnimation("InfoBlank");
		}
	}
}

void AInfoText::RestartTextChange()
{
	std::string CurText = "R Restart";
	int Len = CurText.size();

	FVector TextPosition = FVector::Zero;
	float MoveRight = StaticHelper::TileSize;
	for (int i = 0; i < Size; i++)
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

			RestartVector[i]->ChangeAnimation("Restart" + AlphabetString);
		}
		else
		{
			RestartVector[i]->ChangeAnimation("RestartBlank");
		}
	}
}

void AInfoText::RenderOff()
{
	for (int i = 0; i < Size; i++)
	{
		UndoVector[i]->SetActive(false);
		RestartVector[i]->SetActive(false);
	}
}

void AInfoText::RenderOn()
{
	for (int i = 0; i < Size; i++)
	{
		UndoVector[i]->SetActive(true);
		RestartVector[i]->SetActive(true);
	}
}
