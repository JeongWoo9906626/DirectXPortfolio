#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;
class ACongratulationsText : public AActor
{
	GENERATED_BODY(AActor);

public:
	ACongratulationsText();
	~ACongratulationsText();

	ACongratulationsText(const ACongratulationsText& _Other) = delete;
	ACongratulationsText(ACongratulationsText&& _Other) noexcept = delete;
	ACongratulationsText& operator=(const ACongratulationsText& _Other) = delete;
	ACongratulationsText& operator=(ACongratulationsText&& _Other) noexcept = delete;

	void RenderOff();
	void RenderOn();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void CreateTextAnimation();
	void SetText();

private:
	USpriteRenderer* Renderer = nullptr;
	std::vector<USpriteRenderer*> TextVector;

	int SentenceSize = 15;
	int Size = 15;
};