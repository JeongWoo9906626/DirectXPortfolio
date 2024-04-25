#pragma once
#include "Tile.h"

class AWinText : public ATile
{
	GENERATED_BODY(ATile)

public:
	AWinText();
	~AWinText();

	AWinText(const AWinText& _Other) = delete;
	AWinText(AWinText&& _Other) noexcept = delete;
	AWinText& operator=(const AWinText& _Other) = delete;
	AWinText& operator=(AWinText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};