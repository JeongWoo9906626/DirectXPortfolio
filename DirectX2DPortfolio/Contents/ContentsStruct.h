#pragma once

struct FINT
{
public:
	int X;
	int Y;

	FINT()
		: X(0.0f), Y(0.0f)
	{

	}

	FINT(int _X, int _Y)
		: X(_X), Y(_Y)
	{

	}

public:
	inline FINT GetPos()
	{
		FINT Result = FINT(X, Y);
		return Result;
	}

	inline void SetPos(int _X, int _Y)
	{
		X = _X;
		Y = _Y;
	}

	inline void SetPos(FINT _Pos)
	{
		SetPos(_Pos.X, _Pos.Y);
	}

	inline FINT operator+ (const FINT& _Other) const
	{
		FINT Result = *this;
		Result.X += _Other.X;
		Result.Y += _Other.Y;
		return Result;
	}

	inline FINT operator* (const float _Other) const
	{
		FINT Result = *this;
		Result.X *= _Other;
		Result.Y *= _Other;
		return Result;
	}

	inline bool operator< (const FINT& _Other) const
	{
		FINT Right = *this;
		
		if (Right.Y < _Other.Y)
		{
			return true;
		}
		else if (Right.Y == _Other.Y)
		{
			if (Right.X < _Other.X)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	inline bool operator> (const FINT& _Other) const
	{
		FINT Right = *this;

		if (Right.Y > _Other.Y)
		{
			return true;
		}
		else if (Right.Y == _Other.Y)
		{
			if (Right.X < _Other.X)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
};

