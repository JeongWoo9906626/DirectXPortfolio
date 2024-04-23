#pragma once
#include "Tile.h"

class ASinkText : public ATile
{
	GENERATED_BODY(ATile)

public:
	ASinkText();
	~ASinkText();

	ASinkText(const ASinkText& _Other) = delete;
	ASinkText(ASinkText&& _Other) noexcept = delete;
	ASinkText& operator=(const ASinkText& _Other) = delete;
	ASinkText& operator=(ASinkText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};