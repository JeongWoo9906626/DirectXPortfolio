#include "PreCompile.h"
#include "ContentsCore.h"
#include "PlayGameMode.h"
#include "TitleGameMode.h"
#include "StageSelectGameMode.h"
#include "TestGameMode.h"
#include <EngineCore/EngineSprite.h>

UContentsCore::UContentsCore()
{
}

UContentsCore::~UContentsCore()
{
}

void UContentsCore::Initialize()
{
	{
		// ������ ���
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("ContentsResources");
		Dir.Move("Image");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : Files)
		{
			// CuttingTest.png texture�ε� ������ �ε尡 �ư�
			// ��������Ʈ�ε� 1��¥���� �ε尡 �� ��Ȳ�̾�.
			UEngineSprite::Load(File.GetFullPath());
		}

		// �ε������� �̷��� �Ѵٰ� Ĩ�ô�.
		std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			std::string Name = Directorys[i].GetFolderName();
			UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
		}

		// Ư�� ��������Ʈ�� 
		// Ư�� �ؽ�ó�� ã�Ƽ�
		// ���� ��������Ʈ�� �������� �ʴ´ٸ�
		// �̰� ����ϴ� ���� ������ �ڸ���.
		// �̹� �� �̸��� ���� ��������Ʈ�� �����Ѵ�.
		// �׷��� ������ ��������Ʈ �����ʹ� ����������
		// �ڸ� ��������Ʈ ������ �����Ѵ�.
		UEngineSprite::CreateCutting("Baba.png", 17, 3);
		UEngineSprite::CreateCutting("Selector.png", 3, 1);
		UEngineSprite::CreateCutting("SelectMap.png", 3, 1);
		UEngineSprite::CreateCutting("CuttingTest.png", 4, 3);

		UEngineSprite::CreateCutting("Wall.png", 18, 3);
		UEngineSprite::CreateCutting("Water.png", 18, 3);
		UEngineSprite::CreateCutting("Lava.png", 18, 3);

		UEngineSprite::CreateCutting("IsText.png", 2, 3);
		UEngineSprite::CreateCutting("BabaText.png", 2, 3);

		UEngineSprite::CreateCutting("StopText.png", 3, 3);
		UEngineSprite::CreateCutting("PushText.png", 3, 3);
		UEngineSprite::CreateCutting("YouText.png", 3, 3);
		UEngineSprite::CreateCutting("DefeatText.png", 3, 3);
		UEngineSprite::CreateCutting("SinkText.png", 3, 3);
	}


	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("ContentsResources");
		Dir.Move("Sound");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".wav" });
		for (UEngineFile& File : Files)
		{
			//File.Open(EIOOpenMode::Read, EIODataType::Binary);

			//char Arr[100];
			//File.Read(Arr, 100);

			UEngineSound::Load(File.GetFullPath());
		}
		// UEngineSound::SoundPlay("anipang_ingame_wav.wav");
	}

	GEngine->CreateLevel<ATitleGameMode>("TitleLevel");
	GEngine->CreateLevel<AStageSelectGameMode>("SelectLevel");
	GEngine->CreateLevel<APlayGameMode>("PlayLevel");
	GEngine->CreateLevel<ATestGameMode>("TestLevel");
	GEngine->ChangeLevel("TestLevel");

}
