#include "PreCompile.h"
#include "ContentsGUI.h"

ContentsGUI::ContentsGUI()
{

}

ContentsGUI::~ContentsGUI()
{

}

void ContentsGUI::Init()
{
	Super::Init();
}

void ContentsGUI::Tick(ULevel* _Level, float _DeltaTime)
{
	Super::Tick(_Level, _DeltaTime); 
}

void ContentsGUI::OnGui(ULevel* Level, float _DeltaTime)
{
	if (true == ImGui::Button("TitleLevel"))
	{
		GEngine->ChangeLevel("TitleLevel");
	}

	if (true == ImGui::Button("SelectLevel"))
	{
		GEngine->ChangeLevel("SelectLevel");
	}

	if (true == ImGui::Button("TestLevel"))
	{
		GEngine->ChangeLevel("TestLevel");
	}

	if (true == ImGui::Button("TileMapEditorGameMode"))
	{
		GEngine->ChangeLevel("TileMapEditorGameMode");
	}
}
