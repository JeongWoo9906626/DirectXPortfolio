#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;
class AStageText : public AActor
{
	GENERATED_BODY(AActor);

public:
	AStageText();
	~AStageText();

	AStageText(const AStageText& _Other) = delete;
	AStageText(AStageText&& _Other) noexcept = delete;
	AStageText& operator=(const AStageText& _Other) = delete;
	AStageText& operator=(AStageText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void CreateTextAnimation();
	void TextChange();

private:
	USpriteRenderer* Renderer = nullptr;
	std::vector<USpriteRenderer*> TextVector;

	FINT CurPos = FINT();
	FINT PrevPos = FINT(-1, 0);

	int SentenceSize = 20;
};