#pragma once

enum class ERenderOrder
{
	BackGround,
	Map,
	Object,
	Words,
	Player,
	Effect,
	None,
};

enum class EActorDir
{
	Left,
	Right,
	Up,
	Down,
	None
};

//enum class EActorType
//{
//	Baba,
//	Pillar,
//	Lava,
//	Selector,
//	LWord,
//	RWord,
//	Verb,
//	None,
//};

enum class ENounType
{
	// LWord
	BabaText,
	PillarText,
	LavaText,
	RockText,
	WaterText,
	FlagText,

	// RWord
	YouText,
	StopText,
	PushText,
	DefeatText,
	SinkText,
	WinText,

	SkullText,
	HotText,
	MeltText,
	GrassText,
	MapTileText,

	None,
};

enum class EInputType
{
	L,
	R,
	U,
	D,
	Z,
	Space,
	None,
};

enum class ETileType
{
	// Controller Actor
	Baba,
	Wall,
	Lava,
	Rock,
	Water,
	Selector,
	Flag,

	// Words
	LWord,
	RWord,
	
	// Connecting
	Is,
	And,

	Skull,
	Grass,
	MapTile,

	None,
};

// �� ���⿡ ���� �� ǥ��
enum class ELinkNext
{
	// �ƹ��͵� ���� ��
	Nothing,
	// ���ϸ� ������ ��
	Left,
	Right,
	Top,
	Bottom,
	// 2���� ������ ��
	LeftRight,
	LeftTop,
	LeftBottom,
	RightTop,
	RightBottom,
	TopBottom, 
	// 3���� ������ ��
	LeftRightTop,
	LeftRightBottom,
	LeftTopBottom,
	RightTopBottom,
	// 4�� ��� ������ ��
	LeftRightTopBottom,

	None,
};

enum class ESpawnType
{
	Baba,
	Lava,
	Wall,
	Water,
	Flag,
	Rock,

	BabaText,
	LavaText,
	WallText,
	WaterText,
	FlagText,
	RockText,

	DefeatText,
	PushText,
	SinkText,
	StopText,
	WinText,
	YouText,

	Is,

	Skull,
	SkullText,
	HotText,
	MeltText,
	Grass,
	GrassText,
	MapTile,
	MapTileText,

	None,
};

//enum class LWordType
//{
//	BabaText,
//	WallText,
//	LavaText,
//	RockText,
//	WaterText,
//	None,
//};
//
//enum class RWordType
//{
//	StopText,
//	DefeatText, 
//	PushText,
//	YouText,
//	None,
//};

