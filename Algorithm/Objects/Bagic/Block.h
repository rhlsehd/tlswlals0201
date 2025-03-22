#pragma once
class Block
{
public:
	Block();
	~Block();
	void Render();
	void Update();

	void SetPos(Vector pos);
private:
	shared_ptr<Quad> _block;
};

