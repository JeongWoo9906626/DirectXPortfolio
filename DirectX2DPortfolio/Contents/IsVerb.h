#pragma once
#include "VerbTile.h"

class AIsVerb : public AVerbTile
{
	GENERATED_BODY(AVerbTile)

public:
	AIsVerb();
	~AIsVerb();

	AIsVerb(const AIsVerb& _Other) = delete;
	AIsVerb(AIsVerb&& _Other) noexcept = delete;
	AIsVerb& operator=(const AIsVerb& _Other) = delete;
	AIsVerb& operator=(AIsVerb&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};