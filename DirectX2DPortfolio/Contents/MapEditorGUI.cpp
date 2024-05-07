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
			FINT::MapSize = FINT(33, 18);
			GameMode = dynamic_cast<ATileMapEditorGameMode*>(_Level->GetGameMode().get());
		}
	}
	else
	{
		Off();
	}

	if (true == UEngineInput::IsPress(VK_LBUTTON))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];

		if (FINT::MapSize.X < TilePosX ||
			FINT::MapSize.Y < TilePosY ||
			TilePosX < 0 ||
			TilePosY < 0)
		{
			return;
		}

		if (1 <= StaticHelper::CurTileMap[FINT(TilePosX, TilePosY)].size())
		{
			return;
		}

		int InsertNumber = static_cast<int>(SpawnType);
		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);
	}

	if (true == UEngineInput::IsPress(VK_RBUTTON))
	{
		int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		FINT CurTilePos = FINT(TilePosX, TilePosY);

		if (1 == StaticHelper::CurTileMap[FINT(TilePosX, TilePosY)].size())
		{
			ClearTile(CurTilePos);
			for (int i = 0; i < TilePositionData.size(); i += 3)
			{
				if (TilePosX == TilePositionData[i] && TilePosY == TilePositionData[i + 1])
				{
					TilePositionData[i + 2] = static_cast<int>(ESpawnType::None);
				}
			}
		}
	}

}

void MapEditorGUI::OnGui(ULevel* _Level, float _DeltaTime)
{
	//ImGui::InputInt2("TileSize", TilePos);

	float4 MousePos = GEngine->EngineWindow.GetScreenMousePos();
	float4 MousePosWorld = _Level->GetMainCamera()->ScreenPosToWorldPos(MousePos);
	float WorldTilePositionX = MousePosWorld.X / StaticHelper::TileSize;
	float WorldTilePositionY = MousePosWorld.Y / StaticHelper::TileSize;
	int HalfScaleX = FINT::MapSize.X / 2.0f;
	int HalfScaleY = FINT::MapSize.Y / 2.0f;

	int CurTilePositionX = HalfScaleX + static_cast<int>(WorldTilePositionX);
	int CurTIlePositionY = HalfScaleY + static_cast<int>(WorldTilePositionY);

	FINT CurTilePosition = FINT(CurTilePositionX, CurTIlePositionY);

	ImGui::Text(("TilePos X : " + (std::to_string(CurTilePosition.X))).c_str());
	ImGui::Text(("TilePos Y : " + (std::to_string(CurTilePosition.Y))).c_str());

	TilePos[0] = CurTilePositionX;
	TilePos[1] = CurTIlePositionY;

	// Character GUI
	ImGui::Text("\n< Character >");
	if (true == ImGui::Button("Baba"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::Baba;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::Baba;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("Lava"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::Lava;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::Lava;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("Wall"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::Wall;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::Wall;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("Water"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::Water;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::Water;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("Flag"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::Flag;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::Flag;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("Rock"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::Rock;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::Rock;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("Skull"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::Skull;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::Skull;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("Grass"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::Grass;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::Grass;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("MapTile"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::MapTile;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::MapTile;
	}
	// LeftNoun GUI
	ImGui::Text("\n< LeftNoun >");
	if (true == ImGui::Button("BabaText"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::BabaText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::BabaText;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("LavaText"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::LavaText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::LavaText;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("WallText"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::WallText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::WallText;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("WaterText"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::WaterText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::WaterText;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("FlagText"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::FlagText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::FlagText;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("RockText"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::RockText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::RockText;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("SkullText"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::SkullText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::SkullText;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("GrassText"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::GrassText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::GrassText;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("MapTileText"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::MapTileText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::MapTileText;
	}
	// RightNoun GUI
	ImGui::Text("\n< RightNoun >");
	if (true == ImGui::Button("DefeatText"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::DefeatText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::DefeatText;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("PushText"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::PushText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::PushText;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("SinkText"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::SinkText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::SinkText;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("StopText"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::StopText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::StopText;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("WinText"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::WinText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::WinText;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("YouText"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::YouText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::YouText;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("HotText"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::HotText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::HotText;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("MeltText"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::MeltText;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::MeltText;
	}

	// Connecting Text GUI
	ImGui::Text("\n< Connecting Text >");
	if (true == ImGui::Button("Is"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::Is;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::Is;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("And"))
	{
		/*int TilePosX = TilePos[0];
		int TilePosY = TilePos[1];
		ESpawnType SpawnType = ESpawnType::And;
		int InsertNumber = static_cast<int>(SpawnType);

		TilePositionData.push_back(TilePosX);
		TilePositionData.push_back(TilePosY);
		TilePositionData.push_back(InsertNumber);

		SpawnTile(TilePosX, TilePosY, SpawnType);*/
		SpawnType = ESpawnType::And;
	}

	ImGui::Text("\n< All Tiles Clear >");
	if (true == ImGui::Button("Clear"))
	{
		ClearMap();
	}

	ImGui::Text("\n< Save TileData >");
	ImGui::InputText("Save As FileName", FileName, 25);
	if (true == ImGui::Button("Save"))
	{
		if (true == TilePositionData.empty())
		{
			return;
		}

		UEngineSerializer Ser;
		Ser << TilePositionData;
		std::string CharToString = FileName;
		UEngineFile File = Dir.GetPathFromFile(CharToString + ".Data");
		File.Open(EIOOpenMode::Write, EIODataType::Binary);
		File.Save(Ser);
	}

	ImGui::Text("\n< Load TileData >");
	ImGui::InputText("Load Data By FileName", FileName, 25);
	if (true == ImGui::Button("Load"))
	{
		ClearMap();
		UEngineSerializer Ser;
		std::string Str = FileName;
		UEngineFile File = Dir.GetPathFromFile(Str + ".Data");
		if (false == File.IsExists())
		{
			return;
		}

		File.Open(EIOOpenMode::Read, EIODataType::Binary);
		File.Load(Ser);
		Ser >> TilePositionData;
		MessageOn = true;

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

void MapEditorGUI::ClearMap()
{
	for (std::pair<FINT, std::list<ATile*>> Iter : StaticHelper::CurTileMap)
	{
		for (ATile* Tile : Iter.second)
		{
			if (nullptr != Tile) {
				Tile->Destroy();
				Tile = nullptr;
			}
		}
	}
	TilePositionData.clear();
	StaticHelper::CurTileMap.clear();
}

void MapEditorGUI::ClearTile(FINT _TilePos)
{
	for (ATile* Tile : StaticHelper::CurTileMap[_TilePos])
	{
		if (nullptr != Tile) {
			Tile->Destroy();
			Tile = nullptr;
		}
	}
	StaticHelper::CurTileMap[_TilePos].clear();
}

void MapEditorGUI::SpawnTile(int _X, int _Y, ESpawnType _Type)
{
	FINT TilePos = { _X, _Y };

	GameMode->SpawnTileActor(TilePos, _Type);
}
