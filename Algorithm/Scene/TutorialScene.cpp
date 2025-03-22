#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	_quad.resize(25);

	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			shared_ptr<Block> block = make_shared<Block>();
			block->SetPos(Vector{ 300,650 });
			_quad[i].push_back(block);
		}
	}
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			_quad[i][j]->Update();
			_quad[i][j]->SetPos(Vector{ 300,600 } + Vector{ (float)j * 20,-(float)i * 20 });
		}
	}
}

void TutorialScene::Render()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			_quad[i][j]->Render();
		}
	}
}
