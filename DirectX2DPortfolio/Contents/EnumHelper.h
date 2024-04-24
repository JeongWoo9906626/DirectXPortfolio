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

// �� ���⿡ ���� �� ǥ��
enum class ENoNext
{
	// �ƹ��͵� ���� ��
	Nothing,
	// ���ϸ� ���� ��
	Left,
	Right,
	Top,
	Bottom,
	// 2���� ���� ��
	LeftRight,
	LeftTop,
	LeftBottom,
	RightTop,
	RightBottom,
	TopBottom, 
	// 3���� ���� ��
	LeftRightTop,
	LeftRightBottom,
	LeftTopBottom,
	RightTopBottom,
	// 4�� ��� ���� ��
	LeftRightTopBottom,

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

