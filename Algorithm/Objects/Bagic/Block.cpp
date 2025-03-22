#include "framework.h"
#include "Block.h"

Block::Block()
{
	_block = make_shared<Quad>(Vector(10, 10));
}

Block::~Block()
{
}

void Block::Render()
{
	_block->Render();
}

void Block::Update()
{
	_block->Update();
}

void Block::SetPos(Vector pos)
{
	_block->GetTransform()->SetPos(pos);
}
