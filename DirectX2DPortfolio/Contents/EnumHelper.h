#pragma once

enum class ERenderOrder
{
	Map,
	Object,
	Player,
};

enum class EActorDir
{
	Left,
	Right,
	Up,
	Down,
	None
};

enum class EActorType
{
	Baba,
	Pillar,
	Lava,
	Selector,
	LWord,
	RWord,
	Verb,
	None,
};

enum class ENounType
{
	Baba,
	Pillar,
	Lava,
	You,
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
	Baba,
	Pillar,
	Lava,
	Selector,
	LWord,
	RWord,
	Is,
	And,
	None,
};