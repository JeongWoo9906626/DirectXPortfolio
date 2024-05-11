#include "PreCompile.h"
#include "ContentsCore.h"
#include "SwitchingLevelGameMode.h"
#include "TitleGameMode.h"
#include "StageSelectGameMode.h"
#include "TestGameMode.h"
#include <EngineCore/EngineSprite.h>
#include <EngineCore/EngineEditorGUI.h>
#include "MapEditorGUI.h"
#include "TileMapEditorGameMode.h"
#include "ContentsGUI.h"

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
		
		// Text
		UEngineSprite::CreateCutting("Number.png", 10, 6);
		
		// Object
		UEngineSprite::CreateCutting("Baba.png", 17, 3);
		UEngineSprite::CreateCutting("Selector.png", 3, 1);
		UEngineSprite::CreateCutting("SelectMap.png", 3, 1);
		UEngineSprite::CreateCutting("Flag.png", 2, 3);
		UEngineSprite::CreateCutting("Skull.png", 4, 3);
		UEngineSprite::CreateCutting("CuttingTest.png", 4, 3);
		UEngineSprite::CreateCutting("Rock.png", 1, 3);
		UEngineSprite::CreateCutting("MapTileOnly.png", 3, 1); 

		// LText + Object
		UEngineSprite::CreateCutting("Wall.png", 18, 3);
		UEngineSprite::CreateCutting("Water.png", 18, 3);
		UEngineSprite::CreateCutting("Lava.png", 18, 3);
		UEngineSprite::CreateCutting("Grass.png", 18, 3);
		UEngineSprite::CreateCutting("Line.png", 18, 3);
		UEngineSprite::CreateCutting("MapTile.png", 3, 3);

		// Connecting
		UEngineSprite::CreateCutting("IsText.png", 2, 3);
		UEngineSprite::CreateCutting("AndText.png", 2, 3);

		// LText
		UEngineSprite::CreateCutting("BabaText.png", 2, 3);
		UEngineSprite::CreateCutting("RockText.png", 2, 3);
		UEngineSprite::CreateCutting("FlagText.png", 3, 3);
		UEngineSprite::CreateCutting("SkullText.png", 2, 3);

		// RText
		UEngineSprite::CreateCutting("StopText.png", 3, 3);
		UEngineSprite::CreateCutting("PushText.png", 3, 3);
		UEngineSprite::CreateCutting("YouText.png", 3, 3);
		UEngineSprite::CreateCutting("DefeatText.png", 3, 3);
		UEngineSprite::CreateCutting("SinkText.png", 3, 3);
		UEngineSprite::CreateCutting("HotText.png", 3, 3);
		UEngineSprite::CreateCutting("WinText.png", 3, 3);
		UEngineSprite::CreateCutting("MeltText.png", 3, 3);

		// Alphabet
		UEngineSprite::CreateCutting("WhiteAlphabet.png", 7, 12);
		UEngineSprite::CreateCutting("RKey.png", 3, 1);
		UEngineSprite::CreateCutting("ZKey.png", 3, 1);
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

	{
		UEngineEditorGUI::CreateEditorWindow<ContentsGUI>("ContentsEditor");
		UEngineEditorGUI::CreateEditorWindow<MapEditorGUI>("MapEditor");
	}

	{
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("ContentsShader");
		UEngineShader::AutoCompile(Dir);
	}
	{
		std::shared_ptr<UEngineMaterial> Mat = UEngineMaterial::Create("CircleFadeIn");
		Mat->SetPixelShader("CircleFadeInShader.fx");
		Mat->SetVertexShader("CircleFadeInShader.fx");
	}
	{
		std::shared_ptr<UEngineMaterial> Mat = UEngineMaterial::Create("CircleFadeOut");
		Mat->SetPixelShader("CircleFadeOutShader.fx");
		Mat->SetVertexShader("CircleFadeOutShader.fx");
	}

	GEngine->CreateLevel<ATitleGameMode>("TitleLevel");
	GEngine->CreateLevel<AStageSelectGameMode>("SelectLevel");
	GEngine->CreateLevel<ASwitchingLevelGameMode>("SwitchingLevelGameMode");
	GEngine->CreateLevel<ATestGameMode>("TestLevel");
	GEngine->CreateLevel<ATileMapEditorGameMode>("TileMapEditorGameMode");
	GEngine->ChangeLevel("TitleLevel");
}
