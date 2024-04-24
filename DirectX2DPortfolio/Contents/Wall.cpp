#include "PreCompile.h"
#include "Wall.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

AWall::AWall()
{

}

AWall::~AWall()
{

}

void AWall::BeginPlay()
{
	Super::BeginPlay();

	std::vector<int> AnimationFrameIndex = { 2, 20, 38 };
	std::vector<float> AnimationInterIndex = { 0.1f, 0.1f, 0.1f };

	std::vector<int> NothingIndex = { 2, 20, 38 };
	std::vector<int> RightIndex = { 3, 21, 39 };
	std::vector<int> TopIndex = { 4, 22, 40 };
	std::vector<int> RightTopIndex = { 5, 23, 41 };
	std::vector<int> LeftIndex = { 6, 24, 42 };
	std::vector<int> LeftRightIndex = { 7, 25, 43 };
	std::vector<int> LeftTopIndex = { 8, 26, 44 };
	std::vector<int> LeftRightTopIndex = { 9, 27, 45 };
	std::vector<int> BottomIndex = { 10, 28, 46 };
	std::vector<int> RightBottomIndex = { 11, 29, 47 };
	std::vector<int> TopBottomIndex = { 12, 30, 48 };
	std::vector<int> RightTopBottomIndex = { 13, 31, 49 };
	std::vector<int> LeftBottomIndex = { 14, 32, 50 };
	std::vector<int> LeftRightBottomIndex = { 15, 33, 51 };
	std::vector<int> LeftTopBottomIndex = { 16, 34, 52 };
	std::vector<int> LeftRightTopBottomIndex = { 17, 35, 53 };

	Renderer->CreateAnimation("LeftRightTopBottom", "Wall.png", AnimationInterIndex, LeftRightTopBottomIndex, true);
	Renderer->CreateAnimation("LeftTopBottom", "Wall.png", AnimationInterIndex, LeftTopBottomIndex, true);
	Renderer->CreateAnimation("LeftRightBottom", "Wall.png", AnimationInterIndex, LeftRightBottomIndex, true);
	Renderer->CreateAnimation("LeftBottom", "Wall.png", AnimationInterIndex, LeftBottomIndex, true);
	Renderer->CreateAnimation("RightTopBottom", "Wall.png", AnimationInterIndex, RightTopBottomIndex, true);
	Renderer->CreateAnimation("TopBottom", "Wall.png", AnimationInterIndex, TopBottomIndex, true);
	Renderer->CreateAnimation("RightBottom", "Wall.png", AnimationInterIndex, RightBottomIndex, true);
	Renderer->CreateAnimation("Bottom", "Wall.png", AnimationInterIndex, BottomIndex, true);
	Renderer->CreateAnimation("LeftRightTop", "Wall.png", AnimationInterIndex, LeftRightTopIndex, true);
	Renderer->CreateAnimation("LeftTop", "Wall.png", AnimationInterIndex, LeftTopIndex, true);
	Renderer->CreateAnimation("LeftRight", "Wall.png", AnimationInterIndex, LeftRightIndex, true);
	Renderer->CreateAnimation("Left", "Wall.png", AnimationInterIndex, LeftIndex, true);
	Renderer->CreateAnimation("RightTop", "Wall.png", AnimationInterIndex, RightTopIndex, true);
	Renderer->CreateAnimation("Top", "Wall.png", AnimationInterIndex, TopIndex, true);
	Renderer->CreateAnimation("Right", "Wall.png", AnimationInterIndex, RightIndex, true);
	Renderer->CreateAnimation("Nothing", "Wall.png", AnimationInterIndex, NothingIndex, true);

	Renderer->ChangeAnimation("Nothing");
	Renderer->SetOrder(ERenderOrder::Object);

	SetActorType(ETileType::Wall);
	SetNounType(ENounType::None);

	SetIsBlock(false);
	SetIsPush(false);
	SetIsController(false);
	SetIsSink(false);
	SetIsDefeat(false);

	SetFirstStateInfo(GetTileInfo());
}

void AWall::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
}
