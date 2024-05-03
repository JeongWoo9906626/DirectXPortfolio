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

// 옆 방향에 없는 것 표시
enum class ELinkNext
{
	// 아무것도 없는 것
	Nothing,
	// 단일만 연결인 것
	Left,
	Right,
	Top,
	Bottom,
	// 2개가 연결인 것
	LeftRight,
	LeftTop,
	LeftBottom,
	RightTop,
	RightBottom,
	TopBottom, 
	// 3개가 연결인 것
	LeftRightTop,
	LeftRightBottom,
	LeftTopBottom,
	RightTopBottom,
	// 4개 모두 연결인 것
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

