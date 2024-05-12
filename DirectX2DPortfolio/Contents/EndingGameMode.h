#pragma once
#include <EngineCore/GameMode.h>

// Ό³Έν :
class UImage;
class UFadeOutEffect;
class AEndingGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)

public:
	// constrcuter destructer
	AEndingGameMode();
	~AEndingGameMode();

	// delete Function
	AEndingGameMode(const AEndingGameMode& _Other) = delete;
	AEndingGameMode(AEndingGameMode&& _Other) noexcept = delete;
	AEndingGameMode& operator=(const AEndingGameMode& _Other) = delete;
	AEndingGameMode& operator=(AEndingGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel) override;
	void LevelStart(ULevel* _PrevLevel) override;

	void LevelChangeEffect(float _DeltaTime);

private:
	bool IsEnding = false;

	std::shared_ptr<UFadeOutEffect> FadeOut;
	float CurEndEffectTime = 0.0f;
	float EndEffectTime = 2.0f;

	bool AnimationEnd = false;
	bool AnimationEndInit = false;
};

