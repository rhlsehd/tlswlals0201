#pragma once
class MatrixBuffer;

class Transform
{
public:
	Transform();
	~Transform();

	void Update();
	void SetVS(int slot);

	void SetPos(Vector pos) { _pos = pos; }
	void SetScale(Vector scale) { _scale = scale; }
	void SetAngle(float angle) { _angle = angle; }

	Vector GetLocalPos() { return _pos; }
	Vector GetWorldPos(); // World�� ��ǥ
	Vector GetScale() { return _scale; }
	Vector GetWorldScale();
	float GetAngle() { return _angle; }

	void AddPos(Vector pos) { _pos = _pos + pos; }
	void AddScale(Vector scale) { _scale = _scale + scale; }
	void AddAngle(float value) { _angle += value; }

	void SetParent(shared_ptr<Transform> parent) { _parent = parent; }
	XMMATRIX GetMatrix() { return _srtMatrix;  }

private:
	// Quad : ���
	// => vertices => ����
	// �����(Local Space) => ��Ʈ��(World Space)
	// �������� �ʰ� ��Ʈ������ ���� �� �� ����.
	// => Transform�� Component�� ���� ���� ������ World�� ������ �� ����.

	// world���
	Vector _pos;
	Vector _scale = { 1,1 };
	float _angle = 0.0f; // Z�� ȸ��
	XMMATRIX _srtMatrix;

	shared_ptr<MatrixBuffer> _world;
	
	weak_ptr<Transform> _parent;
};

