#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;
class AInfoText : public AActor
{
	GENERATED_BODY(AActor);

public:
	AInfoText();
	~AInfoText();

	AInfoText(const AInfoText& _Other) = delete;
	AInfoText(AInfoText&& _Other) noexcept = delete;
	AInfoText& operator=(const AInfoText& _Other) = delete;
	AInfoText& operator=(AInfoText&& _Other) noexcept = delete;

	void RenderOff();
	void RenderOn();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void CreateTextAnimation();
	void UndoTextChange();
	void RestartTextChange();

private:
	USpriteRenderer* Renderer = nullptr;
	std::vector<USpriteRenderer*> UndoVector;
	std::vector<USpriteRenderer*> RestartVector;

	FINT CurPos = FINT();
	FINT PrevPos = FINT(-1, 0);
	
	int Size = 9;
};