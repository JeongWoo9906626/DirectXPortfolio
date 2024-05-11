#include "PreCompile.h"
#include "TextActor.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

TextActor::TextActor()
{
	UDefaultSceneComponent* Root = CreateDefaultSubObject<UDefaultSceneComponent>("Renderer");
	SetRoot(Root);

	Renderer = CreateDefaultSubObject<USpriteRenderer>("Renderer");
	Renderer->SetupAttachment(Root);
	Renderer->SetOrder(ERenderOrder::Words);
	Renderer->SetScale(FVector(36, 36));
}

TextActor::~TextActor()
{

}

void TextActor::BeginPlay()
{
	Super::BeginPlay();

	TextAnimationSetting();
}

void TextActor::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}

void TextActor::TextAnimationSetting()
{
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
			Renderer->CreateAnimation("Title" + Alphabet, "WhiteAlphabet.png", AnimationFrame, TextAnimationIndex);
		}
		Renderer->CreateAnimation("TitleBlank", "WhiteAlphabet.png", AnimationFrame, { 78 });
	}

	{
		int i = 0;
		int Index = -1;
		std::vector<float> AnimationFrame = { 0.1f, 0.1f, 0.1f };
		std::vector<int> AnimationOnFrameIndex;

		while (i < 10)
		{
			Index += 1;
			std::string Number = std::to_string(i);

			if (i < 5)
			{
				AnimationOnFrameIndex = { Index, Index + 10, Index + 20 };
				Index++;
			}
			else
			{
				AnimationOnFrameIndex = { Index + 20, Index + 30, Index + 40 };
				Index++;
			}

			Renderer->CreateAnimation("Title" + Number, "Number.png", AnimationFrame, AnimationOnFrameIndex, true);
			i++;
		}
	}
}


void TextActor::SetText(std::string _Text)
{
	Renderer->ChangeAnimation("Title" + _Text);
}

void TextActor::SetColor(FVector _Color)
{
	_Color.X = _Color.X / 255;
	_Color.Y = _Color.Y / 255;
	_Color.Z = _Color.Z / 255;
	Renderer->SetMulColor(_Color);
}

void TextActor::SetScale(FVector _Scale)
{
	Renderer->SetScale(_Scale);
}
