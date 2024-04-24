#include "PreCompile.h"
#include "Lava.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include "StaticHelper.h"

ALava::ALava()
{

}

ALava::~ALava()
{

}

void ALava::BeginPlay()
{
	Super::BeginPlay();

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

	Renderer->CreateAnimation("LeftRightTopBottom", "Lava.png", AnimationInterIndex, LeftRightTopBottomIndex, true);
	Renderer->CreateAnimation("LeftTopBottom", "Lava.png", AnimationInterIndex, LeftTopBottomIndex, true);
	Renderer->CreateAnimation("LeftRightBottom", "Lava.png", AnimationInterIndex, LeftRightBottomIndex, true);
	Renderer->CreateAnimation("LeftBottom", "Lava.png", AnimationInterIndex, LeftBottomIndex, true);
	Renderer->CreateAnimation("RightTopBottom", "Lava.png", AnimationInterIndex, RightTopBottomIndex, true);
	Renderer->CreateAnimation("TopBottom", "Lava.png", AnimationInterIndex, TopBottomIndex, true);
	Renderer->CreateAnimation("RightBottom", "Lava.png", AnimationInterIndex, RightBottomIndex, true);
	Renderer->CreateAnimation("Bottom", "Lava.png", AnimationInterIndex, BottomIndex, true);
	Renderer->CreateAnimation("LeftRightTop", "Lava.png", AnimationInterIndex, LeftRightTopIndex, true);
	Renderer->CreateAnimation("LeftTop", "Lava.png", AnimationInterIndex, LeftTopIndex, true);
	Renderer->CreateAnimation("LeftRight", "Lava.png", AnimationInterIndex, LeftRightIndex, true);
	Renderer->CreateAnimation("Left", "Lava.png", AnimationInterIndex, LeftIndex, true);
	Renderer->CreateAnimation("RightTop", "Lava.png", AnimationInterIndex, RightTopIndex, true);
	Renderer->CreateAnimation("Top", "Lava.png", AnimationInterIndex, TopIndex, true);
	Renderer->CreateAnimation("Right", "Lava.png", AnimationInterIndex, RightIndex, true);
	Renderer->CreateAnimation("Nothing", "Lava.png", AnimationInterIndex, NothingIndex, true);

	Renderer->ChangeAnimation("Nothing");
	Renderer->SetOrder(ERenderOrder::Object);

	SetActorType(ETileType::Lava);
	SetNounType(ENounType::None);

	SetIsBlock(false);
	SetIsPush(false);
	SetIsController(false);
	SetIsSink(false);
	SetIsDefeat(false);

	SetFirstStateInfo(GetTileInfo());
}

void ALava::Tick(float _DetaTime)
{
	Super::Tick(_DetaTime);
}
