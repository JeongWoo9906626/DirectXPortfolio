#pragma once
#include <EngineCore/EngineEditorWindow.h>

class ContentsGUI : public UEngineEditorWindow
{
	GENERATED_BODY(UEngineEditorWindow)
public:
	ContentsGUI();
	~ContentsGUI();

	ContentsGUI(const ContentsGUI& _Other) = delete;
	ContentsGUI(ContentsGUI&& _Other) noexcept = delete;
	ContentsGUI& operator=(const ContentsGUI& _Other) = delete;
	ContentsGUI& operator=(ContentsGUI&& _Other) noexcept = delete;

protected:
	virtual void Init();
	void Tick(ULevel* _Level, float _DeltaTime) override;
	void OnGui(ULevel* Level, float _DeltaTime) override;


private:

};