#include "PreCompile.h"
#include "FadeInEffect.h"

UFadeInEffect::UFadeInEffect()
{

}

UFadeInEffect::~UFadeInEffect()
{

}

void UFadeInEffect::Init()
{
	SetMaterial("CircleFadeIn");

	Target = UEngineRenderTarget::Create();
	// ���� �ٶ󺸴� �ֵ��� ��Ƽ� �׸��� �ִ� ����Ÿ���� ����� �;�.
	float4 Scale = GEngine->EngineWindow.GetWindowScale();
	Target->CreateTexture(DXGI_FORMAT::DXGI_FORMAT_R32G32B32A32_FLOAT, Scale, float4::Zero);
}

void UFadeInEffect::Effect(std::shared_ptr<UEngineRenderTarget> EffectTarget)
{
	Target->Copy(EffectTarget);
	EffectTarget->Clear();
	EffectTarget->Setting();

	Resources->SettingTexture("Image", Target->GetTexture(), "POINT");

	Render(0.0f);
}
