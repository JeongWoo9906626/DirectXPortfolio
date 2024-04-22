#pragma once
#include "ConnectingTile.h"

class AIsText : public AConnectingTile
{
	GENERATED_BODY(AConnectingTile)

public:
	AIsText();
	~AIsText();

	AIsText(const AIsText& _Other) = delete;
	AIsText(AIsText&& _Other) noexcept = delete;
	AIsText& operator=(const AIsText& _Other) = delete;
	AIsText& operator=(AIsText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};