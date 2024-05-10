#pragma once
#include <EngineCore/GameMode.h>

// Ό³Έν :
class UImage;
class UFadeOutEffect;
class ATitleGameMode : public AGameMode
{
	GENERATED_BODY(AGameMode)

public:
	// constrcuter destructer
	ATitleGameMode();
	~ATitleGameMode();

	// delete Function
	ATitleGameMode(const ATitleGameMode& _Other) = delete;
	ATitleGameMode(ATitleGameMode&& _Other) noexcept = delete;
	ATitleGameMode& operator=(const ATitleGameMode& _Other) = delete;
	ATitleGameMode& operator=(ATitleGameMode&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void LevelEnd(ULevel* _NextLevel) override;
	void LevelStart(ULevel* _PrevLevel) override;

	void LevelChangeEffect(float _DeltaTime);

private:
	UImage* TitleBaba = nullptr;

	bool IsLevelChange = false;

	std::shared_ptr<UFadeOutEffect> FadeOut;
	float CurEndEffectTime = 0.0f;
	float EndEffectTime = 2.0f;

	bool AnimationEnd = false;
	bool AnimationEndInit = false;
};

