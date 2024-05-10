#pragma once
#include <EngineCore/Actor.h>

class USpriteRenderer;
class TextActor : public AActor
{
	GENERATED_BODY(AActor)

public:
	TextActor();
	~TextActor();

	TextActor(const TextActor& _Other) = delete;
	TextActor(TextActor&& _Other) noexcept = delete;
	TextActor& operator=(const TextActor& _Other) = delete;
	TextActor& operator=(TextActor&& _Other) noexcept = delete;

	void SetText(std::string _Text);
	void SetColor(FVector _Color);
	void SetScale(FVector _Scale);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void TextAnimationSetting();
	
private:
	USpriteRenderer* Renderer = nullptr;
};