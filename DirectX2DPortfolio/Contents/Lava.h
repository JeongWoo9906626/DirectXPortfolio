#pragma once

class Lava
{
public:
	Lava();
	~Lava();

	Lava(const Lava& _Other) = delete;
	Lava(Lava&& _Other) noexcept = delete;
	Lava& operator=(const Lava& _Other) = delete;
	Lava& operator=(Lava&& _Other) noexcept = delete;

protected:

private:

};