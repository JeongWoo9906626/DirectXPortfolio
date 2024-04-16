#pragma once

struct FINT
{
public:
	static const FINT LEFT;
	static const FINT RIGHT;
	static const FINT UP;
	static const FINT DOWN;

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
	static FINT MapSize;

	inline FINT GetTilePos()
	{
		FINT Result = FINT(X, Y);
		return Result;
	}

	inline void SetTilePos(int _X, int _Y)
	{
		X = _X;
		Y = _Y;
	}

	inline void SetTilePos(FINT _TilePos)
	{
		SetTilePos(_TilePos.X, _TilePos.Y);
	}

	inline FVector GetFINTToVector()
	{
		FINT TilePos = *this;
		FVector Result = FVector::Zero;
		Result.X = TilePos.X * 32;
		Result.Y = TilePos.Y * 32;
		return Result;
	}

	inline FINT& operator= (const FINT& _Other)
	{
		//FINT Result = *this;
		X = _Other.X;
		Y = _Other.Y;
		return *this;
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

	bool operator== (FINT _Other)
	{
		FINT Right = *this;
		if (Right.X == _Other.X && Right.Y == _Other.Y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool operator!= (FINT _Other)
	{
		FINT Right = *this;
		bool Result = !Right.operator==(_Other);
		return Result;
	}
};

