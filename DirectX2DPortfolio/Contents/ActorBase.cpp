#include "PreCompile.h"
#include "ActorBase.h"
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
}

void AActorBase::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

	if (false == IsMove)
	{
		if (true == UEngineInput::IsDown(VK_LEFT))
		{
			PrevPos = GetActorLocation();
			NextPos = PrevPos; 
			NextPos.X -= MoveRange;

			CurMoveTime = MoveTime;
			IsMove = true;
		}
		
		if (true == UEngineInput::IsDown(VK_RIGHT))
		{
			PrevPos = GetActorLocation();
			NextPos = PrevPos;
			NextPos.X += MoveRange;

			CurMoveTime = MoveTime;
			IsMove = true;
		}

		if (true == UEngineInput::IsDown(VK_UP))
		{
			PrevPos = GetActorLocation();
			NextPos = PrevPos;
			NextPos.Y += MoveRange;

			CurMoveTime = MoveTime;
			IsMove = true;
		}

		if (true == UEngineInput::IsDown(VK_DOWN))
		{
			PrevPos = GetActorLocation();
			NextPos = PrevPos;
			NextPos.Y -= MoveRange;

			CurMoveTime = MoveTime;
			IsMove = true;
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

FVector AActorBase::Lerp(float _CurMoveTime)
{
	float t = (MoveTime - _CurMoveTime) / MoveTime;
	FVector CurPos = PrevPos * (1 - t) + NextPos * t;

	return CurPos;
}
