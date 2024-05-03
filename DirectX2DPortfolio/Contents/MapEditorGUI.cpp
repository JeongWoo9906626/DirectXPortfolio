#include "PreCompile.h"
#include "MapEditorGUI.h"
#include "TileMapEditorGameMode.h"

MapEditorGUI::MapEditorGUI()
{

}

MapEditorGUI::~MapEditorGUI()
{

}

void MapEditorGUI::Init()
{
	Super::Init();

	Dir.MoveParent();
	Dir.Move("ContentsResources");
	Dir.Move("SaveLevel");
}

void MapEditorGUI::Tick(ULevel* _Level, float _DeltaTime)
{
	Super::Tick(_Level, _DeltaTime);

	std::string str = _Level->GetName();
	
	if (true == str._Equal("TileMapEditorGameMode")) 
	{
		On();
		if (GameMode == nullptr) 
		{
			GameMode = dynamic_cast<ATileMapEditorGameMode*>(_Level->GetGameMode().get());
		}
	}
	else 
	{
		Off();
	}
}

void MapEditorGUI::OnGui(ULevel* _Level, float _DeltaTime)
{
	ImGui::InputInt2("TileSize", TilePos);

	float4 MousePos = GEngine->EngineWindow.GetScreenMousePos();
	float4 MousePosWorld = _Level->GetMainCamera()->ScreenPosToWorldPos(MousePos);

	float WorldTilePositionX = MousePosWorld.X / StaticHelper::TileSize;
	float WorldTilePositionY = MousePosWorld.Y / StaticHelper::TileSize;

	ImGui::Text(("Mouse X : " + (std::to_string(MousePos.X))).c_str());
	ImGui::Text(("Mouse Y : " + (std::to_string(MousePos.Y))).c_str());

	ImGui::Text(("TilePos X : " + (std::to_string(static_cast<int>(WorldTilePositionX)))).c_str());
	ImGui::Text(("TilePos Y : " + (std::to_string(static_cast<int>(WorldTilePositionY)))).c_str());

	// Character GUI
	ImGui::Text("\n< Character >");
	if (true == ImGui::Button("Baba"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::Baba;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	ImGui::SameLine();
	if (true == ImGui::Button("Lava"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::Lava;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	ImGui::SameLine();
	if (true == ImGui::Button("Wall"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::Wall;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	ImGui::SameLine();
	if (true == ImGui::Button("Water"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::Water;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	ImGui::SameLine();
	if (true == ImGui::Button("Flag"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::Flag;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	ImGui::SameLine();
	if (true == ImGui::Button("Rock"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::Rock;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	ImGui::SameLine();
	if (true == ImGui::Button("Skull"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::Skull;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	// LeftNoun GUI
	ImGui::Text("\n< LeftNoun >");
	if (true == ImGui::Button("BabaText"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::BabaText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	ImGui::SameLine();
	if (true == ImGui::Button("LavaText"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::LavaText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	ImGui::SameLine();
	if (true == ImGui::Button("WallText"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::WallText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	ImGui::SameLine();
	if (true == ImGui::Button("WaterText"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::WaterText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	ImGui::SameLine();
	if (true == ImGui::Button("FlagText"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::FlagText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	ImGui::SameLine();
	if (true == ImGui::Button("RockText"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::RockText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	ImGui::SameLine();
	if (true == ImGui::Button("SkullText"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::SkullText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	// RightNoun GUI
	ImGui::Text("\n< RightNoun >");
	if (true == ImGui::Button("DefeatText"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::DefeatText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	ImGui::SameLine();
	if (true == ImGui::Button("PushText"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::PushText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	ImGui::SameLine();
	if (true == ImGui::Button("SinkText"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::SinkText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	ImGui::SameLine();
	if (true == ImGui::Button("StopText"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::StopText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	ImGui::SameLine();
	if (true == ImGui::Button("WinText"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::WinText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	ImGui::SameLine();
	if (true == ImGui::Button("YouText"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::YouText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	ImGui::SameLine();
	if (true == ImGui::Button("HotText"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::HotText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	ImGui::SameLine();
	if (true == ImGui::Button("MeltText"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::MeltText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}

	// Connecting Text GUI
	ImGui::Text("\n< Connecting Text >");
	if (true == ImGui::Button("Is"))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::Is;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}
	/*ImGui::SameLine();
	if (true == ImGui::Button("And"))
	{

	}*/
	
	ImGui::Text("\n< All Tiles Clear >");
	if (true == ImGui::Button("Clear"))
	{
		// 클리어 만들기
	}

	ImGui::Text("\n< Save TileData >");
	ImGui::InputText("Save As FileName", FileName, 25);
	if (true == ImGui::Button("Save"))
	{
		if (true == TilePositionData.empty())
		{
			MessageOn = true;
			str = "Can't Save File! Please Insert TileData.";
			return;
		}

		UEngineSerializer Ser;
		Ser << TilePositionData;
		std::string CharToString = FileName;
		UEngineFile File = Dir.GetPathFromFile(CharToString + ".Data");
		File.Open(EIOOpenMode::Write, EIODataType::Binary);
		File.Save(Ser);
		str = "File Save Success";
	}

	ImGui::Text("\n< Load TileData >");
	ImGui::InputText("Load Data By FileName", FileName, 25);
	if (true == ImGui::Button("Load"))
	{
		UEngineSerializer Ser;
		std::string Str = FileName;
		UEngineFile File = Dir.GetPathFromFile(Str + ".Data");
		if (false == File.IsExists())
		{
			MessageOn = true;
			str = FileName + std::string("file does not exist");
			return;
		}

		File.Open(EIOOpenMode::Read, EIODataType::Binary);
		File.Load(Ser);
		Ser >> TilePositionData;
		MessageOn = true;
		str = "File Load Success";

		int Index = 0;
		while (TilePositionData.size() > Index)
		{
			int X = TilePositionData[Index++];
			int Y = TilePositionData[Index++];
			int Type = TilePositionData[Index++];

			FINT Pos = { X, Y };
			ESpawnType SpawnType = static_cast<ESpawnType>(Type);
			GameMode->SpawnTileActor(Pos, SpawnType);
		}
	}
}

void MapEditorGUI::SpawnTile(int _X, int _Y, ESpawnType _Type)
{
	FINT TilePos = { _X, _Y };

	GameMode->SpawnTileActor(TilePos, _Type);
}
