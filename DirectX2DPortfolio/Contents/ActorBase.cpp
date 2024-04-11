#include "PreCompile.h"
#include "ActorBase.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/SpriteRenderer.h>

AActorBase::AActorBase()
{

}

AActorBase::~AActorBase()
{

}

void AActorBase::BeginPlay()
{
	Super::BeginPlay();
	SetMoveRange(32.0f);
}

void AActorBase::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (false == IsMove)
	{
		if (true == UEngineInput::IsDown('Z'))
		{
			
			if (true == MoveHistory.empty())
			{
				return;
			}

			if (false == IsBack)
			{
				AnimationIndexHistory.pop();
			}

			IsBack = true;
			MoveSet();
			MoveHistory.pop();
		}

		if (true == UEngineInput::IsDown(VK_LEFT))
		{
			IsBack = false;
			MoveHistory.push(EActorDir::Left);
			MoveSet();
		}

		if (true == UEngineInput::IsDown(VK_RIGHT))
		{
			IsBack = false;
			MoveHistory.push(EActorDir::Right);
			MoveSet();
		}

		if (true == UEngineInput::IsDown(VK_UP))
		{
			IsBack = false;
			MoveHistory.push(EActorDir::Up);
			MoveSet();
		}

		if (true == UEngineInput::IsDown(VK_DOWN))
		{
			IsBack = false;
			MoveHistory.push(EActorDir::Down);
			MoveSet();
		}
	}
	else
	{
		if (CurMoveTime <= 0.0f)
		{
			IsMove = false;
			CurMoveTime = 0.0f;
		}

		CurMoveTime -= _DeltaTime;

		FVector MoveVector = Lerp(CurMoveTime);
		SetActorLocation(MoveVector);
	}
}

void AActorBase::MoveSet()
{
	IsMove = true;
	CurMoveTime = MoveTime;

	PrevPos = GetActorLocation();
	NextPos = PrevPos;

	CurDir = MoveHistory.top();
	
	float Dir = 1.0f;
	if (true == IsBack)
	{
		Dir = -1.0f;
	}

	switch (CurDir)
	{
	case EActorDir::Left:
		NextPos.X -= MoveRange * Dir;
		break;
	case EActorDir::Right:
		NextPos.X += MoveRange * Dir;
		break;
	case EActorDir::Up:
		NextPos.Y += MoveRange * Dir;
		break;
	case EActorDir::Down:
		NextPos.Y -= MoveRange * Dir;
		break;
	}
}

FVector AActorBase::Lerp(float _CurMoveTime)
{
	float t = (MoveTime - _CurMoveTime) / MoveTime;
	FVector CurPos = PrevPos * (1 - t) + NextPos * t;

	return CurPos;
}