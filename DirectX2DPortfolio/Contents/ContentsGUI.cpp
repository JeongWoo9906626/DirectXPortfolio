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
}

void ContentsGUI::OnGui(float _DeltaTime)
{
	if (true == ImGui::Button("PlayLevel"))
	{
		GEngine->ChangeLevel("PlayLevel");
	}

	if (true == ImGui::Button("TestLevel"))
	{
		GEngine->ChangeLevel("TestLevel");
	}

}
