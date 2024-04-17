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
	Empty,
	Baba,
	Pillar,
	Lava,
	Selector,
	CharNoun,
	Noun,
	Verb,
	You,


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

