#pragma once

enum class ERenderOrder
{
	Map,
	Object,
	Words,
	Player,
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

	// RWord
	YouText,
	StopText,
	PushText,
	DefeatText,
	SinkText,

	None,
};

enum class EInputType
{
	L,
	R,
	U,
	D,
	Z,
	None,
};

enum class ETileType
{
	// Controller Actor
	Baba,
	Pillar,
	Lava,
	Rock,
	Water,
	Selector,

	// Words
	LWord,
	RWord,
	
	// Connecting
	Is,
	And,
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