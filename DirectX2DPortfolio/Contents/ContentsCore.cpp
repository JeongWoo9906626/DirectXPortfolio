#include "PreCompile.h"
#include "ContentsCore.h"
#include "PlayGameMode.h"
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
		// 파일의 헤더
		UEngineDirectory Dir;
		Dir.MoveToSearchChild("ContentsResources");
		Dir.Move("Image");
		std::vector<UEngineFile> Files = Dir.GetAllFile({ ".png" }, true);
		for (UEngineFile& File : Files)
		{
			// CuttingTest.png texture로도 한장이 로드가 됐고
			// 스프라이트로도 1장짜리로 로드가 된 상황이야.
			UEngineSprite::Load(File.GetFullPath());
		}

		// 로드폴더는 이렇게 한다고 칩시다.
		std::vector<UEngineDirectory> Directorys = Dir.GetAllDirectory();
		for (size_t i = 0; i < Directorys.size(); i++)
		{
			std::string Name = Directorys[i].GetFolderName();
			UEngineSprite::LoadFolder(Directorys[i].GetFullPath());
		}

		// 특정 스프라이트나 
		// 특정 텍스처를 찾아서
		// 만약 스프라이트가 존재하지 않는다면
		// 이걸 사용하는 순간 만들어내고 자른다.
		// 이미 이 이름을 가진 스프라이트가 존재한다.
		// 그러면 기존의 스프라이트 데이터는 날려버리고
		// 자른 스프라이트 데이터 변경한다.
		
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
	GEngine->CreateLevel<APlayGameMode>("PlayLevel");
	GEngine->CreateLevel<ATestGameMode>("TestLevel");
	GEngine->CreateLevel<ATileMapEditorGameMode>("TileMapEditorGameMode");
	//GEngine->ChangeLevel("TileMapEditorGameMode");
	GEngine->ChangeLevel("TitleLevel");
}
