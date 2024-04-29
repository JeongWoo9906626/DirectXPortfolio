#pragma once
#include <EngineCore/EngineRenderTarget.h>

class UFadeInEffect : public UEffect
{
public:
	UFadeInEffect();
	~UFadeInEffect();

	UFadeInEffect(const UFadeInEffect& _Other) = delete;
	UFadeInEffect(UFadeInEffect&& _Other) noexcept = delete;
	UFadeInEffect& operator=(const UFadeInEffect& _Other) = delete;
	UFadeInEffect& operator=(UFadeInEffect&& _Other) noexcept = delete;

protected:
	void Init() override;
	void Effect(std::shared_ptr<UEngineRenderTarget> EffectTarget) override;

private:
	std::shared_ptr<UEngineRenderTarget> Target;

};