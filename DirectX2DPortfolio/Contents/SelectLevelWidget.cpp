#include "PreCompile.h"
#include "SelectLevelWidget.h"

//#include <EngineCore/TextWidget.h>
#include <EngineCore/Image.h>

#include "Selector.h"
#include "SelectTile.h"

SelectLevelWidget::SelectLevelWidget()
{

}

SelectLevelWidget::~SelectLevelWidget()
{

}

void SelectLevelWidget::BeginPlay()
{
	Super::BeginPlay();
}

void SelectLevelWidget::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	FINT SelectorPosition = StaticHelper::CurSelector->GetTilePosition();
	CurText = StaticHelper::CurSelectTileMap[SelectorPosition]->SelectInfo.StageText;
	if (false == PrevText._Equal(CurText))
	{
		TextChange();
		PrevText = CurText;
	}
}

void SelectLevelWidget::TextChange()
{
	int Len = CurText.size();

	for (int i = 0; i < Len; i++)
	{
		// 알파벳 체크

		// 에니메이션으로 생성

		/*UImage* Image = CreateWidget<UImage>(GetWorld(), "HpBar");
		Image->SetupAttachment(this);
		Image->SetSprite("HPBar.png");
		Image->SetAutoSize(0.5f, true);
		Image->SetPosition({ -400, 300 });*/
	}
}
