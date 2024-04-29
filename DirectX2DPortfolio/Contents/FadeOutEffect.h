#pragma once
#include <EngineCore/EngineRenderTarget.h>

class UFadeOutEffect : public UEffect
{
public:
	UFadeOutEffect();
	~UFadeOutEffect();

	UFadeOutEffect(const UFadeOutEffect& _Other) = delete;
	UFadeOutEffect(UFadeOutEffect&& _Other) noexcept = delete;
	UFadeOutEffect& operator=(const UFadeOutEffect& _Other) = delete;
	UFadeOutEffect& operator=(UFadeOutEffect&& _Other) noexcept = delete;

protected:
	void Init() override;
	void Effect(std::shared_ptr<UEngineRenderTarget> EffectTarget) override;


private:
	std::shared_ptr<UEngineRenderTarget> Target;

};