#pragma once

enum class ERenderOrder
{
	Map,
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
	None,
};