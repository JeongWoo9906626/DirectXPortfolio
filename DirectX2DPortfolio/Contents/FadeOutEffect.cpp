#include "PreCompile.h"
#include "FadeOutEffect.h"

UFadeOutEffect::UFadeOutEffect()
{

}

UFadeOutEffect::~UFadeOutEffect()
{
}

void UFadeOutEffect::Init()
{
	SetMaterial("CircleFadeOut");

	Target = UEngineRenderTarget::Create();
	// ���� �ٶ󺸴� �ֵ��� ��Ƽ� �׸��� �ִ� ����Ÿ���� ����� �;�.
	float4 Scale = GEngine->EngineWindow.GetWindowScale();
	Target->CreateTexture(DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT, Scale, float4::Zero);
}

void UFadeOutEffect::Effect(std::shared_ptr<UEngineRenderTarget> EffectTarget)
{
	Target->Copy(EffectTarget);
	EffectTarget->Clear();
	EffectTarget->Setting();

	Resources->SettingTexture("Image", Target->GetTexture(), "POINT");

	Render(0.0f);
}