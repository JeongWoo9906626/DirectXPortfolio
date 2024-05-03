#pragma once
#include "Tile.h"

class AMeltText : public ATile
{
	GENERATED_BODY(ATile)
	
public:
	AMeltText();
	~AMeltText();

	AMeltText(const AMeltText& _Other) = delete;
	AMeltText(AMeltText&& _Other) noexcept = delete;
	AMeltText& operator=(const AMeltText& _Other) = delete;
	AMeltText& operator=(AMeltText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};