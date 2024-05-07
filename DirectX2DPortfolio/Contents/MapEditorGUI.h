#pragma once
#include <EngineCore/EngineEditorWindow.h>
#include <EngineBase/EngineDirectory.h>

class ATileMapEditorGameMode;
class ATile;
class MapEditorGUI : public UEngineEditorWindow
{
	GENERATED_BODY(UEngineEditorWindow)

public:
	MapEditorGUI();
	~MapEditorGUI();

	MapEditorGUI(const MapEditorGUI& _Other) = delete;
	MapEditorGUI(MapEditorGUI&& _Other) noexcept = delete;
	MapEditorGUI& operator=(const MapEditorGUI& _Other) = delete;
	MapEditorGUI& operator=(MapEditorGUI&& _Other) noexcept = delete;

protected:
	void Init() override;
	void Tick(ULevel* _Level, float _DeltaTime) override;
	void OnGui(ULevel* Level, float _DeltaTime) override;

	ATileMapEditorGameMode* GameMode = nullptr;
	UEngineDirectory Dir;
	std::string str = "";

	int TilePos[2] = { 0, };
	char FileName[255] = "";
	std::vector<int> TilePositionData;

	void ClearMap();
	void ClearTile(FINT _TilePos);

	//std::vector<ATile> Tiles;
private:
	void SpawnTile(int _X, int _Y, ESpawnType _Type);
	ESpawnType SpawnType = ESpawnType::None;
	bool MessageOn = false;
};