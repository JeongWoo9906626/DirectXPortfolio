#pragma once
#include "Tile.h"

class AFlagText : public ATile
{
	GENERATED_BODY(ATile)

public:
	AFlagText();
	~AFlagText();

	AFlagText(const AFlagText& _Other) = delete;
	AFlagText(AFlagText&& _Other) noexcept = delete;
	AFlagText& operator=(const AFlagText& _Other) = delete;
	AFlagText& operator=(AFlagText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};