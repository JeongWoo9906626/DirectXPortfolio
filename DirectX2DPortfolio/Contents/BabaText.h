#pragma once
#include "Tile.h"

class ABabaText : public ATile 
{
	GENERATED_BODY(ATile)

public:
	ABabaText();
	~ABabaText();

	ABabaText(const ABabaText& _Other) = delete;
	ABabaText(ABabaText&& _Other) noexcept = delete;
	ABabaText& operator=(const ABabaText& _Other) = delete;
	ABabaText& operator=(ABabaText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};