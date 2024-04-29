#include "ContentsShaderBase.hlsli"

struct ImageVSOutPut
{
	float4 POSITION : SV_POSITION;
	float4 TEXCOORD : TEXCOORD;
};

ImageVSOutPut CircleFadeOut_VS(FEngineVertex _Input)
{
	ImageVSOutPut Out = (ImageVSOutPut) 0;
	Out.POSITION = _Input.POSITION;
	Out.TEXCOORD = _Input.TEXCOORD;
	
	return Out;
}

struct ImagePSOutPut
{
	float4 COLOR : SV_Target0;
};

TextureSet(Image, 0);

ImagePSOutPut CircleFadeOut_PS(ImageVSOutPut _Input)
{
	ImagePSOutPut Out = (ImagePSOutPut) 0;
	Out.COLOR.rgba = Image.Sample(Image_Sampler, _Input.TEXCOORD.xy);
	
	float2 Center = float2(0.5f, 0.5f);
	float2 Dir = Center - _Input.TEXCOORD.xy;
	float Len = length(Dir);
    
	if (Len > 0.5f * AccTime)
	{
		Out.COLOR.rgba = float4(0.f, 0.f, 0.f, 1.f);

	}
    
	return Out;
}