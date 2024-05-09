#pragma once
#include <EngineCore/Widget.h>

class SelectLevelWidget : public UWidget
{
	GENERATED_BODY(UWidget)

public:
	SelectLevelWidget();
	~SelectLevelWidget();

	SelectLevelWidget(const SelectLevelWidget& _Other) = delete;
	SelectLevelWidget(SelectLevelWidget&& _Other) noexcept = delete;
	SelectLevelWidget& operator=(const SelectLevelWidget& _Other) = delete;
	SelectLevelWidget& operator=(SelectLevelWidget&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void TextChange();

private:
	std::string PrevText = "";
	std::string CurText = "";
	FVector FirstPos = FVector::Zero;

};