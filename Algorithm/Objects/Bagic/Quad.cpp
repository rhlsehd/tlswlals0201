#include "framework.h"
#include "Quad.h"

Quad::Quad()
{
	CreateVertices();

	_vs = make_shared<VertexShader>(L"Shader/TutoVertexShader.hlsl");
	_ps = make_shared<PixelShader>(L"Shader/TutoPixelShader.hlsl");

    _transform = make_shared<Transform>();
}

Quad::Quad(Vector halfSize)
{
    CreateVertices(halfSize);

    _vs = make_shared<VertexShader>(L"Shader/TutoVertexShader.hlsl");
    _ps = make_shared<PixelShader>(L"Shader/TutoPixelShader.hlsl");

    _transform = make_shared<Transform>();
}

Quad::~Quad()
{
}

void Quad::Update()
{
    _transform->Update();
}

void Quad::Render()
{
    _transform->SetVS(0);

    _vs->IASetInputLayout();
    _vertexBuffer->IASet(0);

    _vs->VSSet();
    _ps->PSSet();

    DC->Draw(_vertices.size(), 0);
}

void Quad::CreateVertices()
{
    _vertices = 
    { 
        {0,50}, // ���� ��
        {50, 0}, // ������ ��
        {0, 0}, // ������ �Ʒ�
        
        {0,50}, // ���� ��
        {50, 50}, // ������ �Ʒ�
        {50, 0}, // ���� �Ʒ�
    };
    _vertices[0].color = { 1,0,0,1 };
    _vertices[1].color = { 0,1,0,1 };
    _vertices[2].color = { 0,0,1,1 };

    _vertices[3].color = { 1,0,0,1 };
    _vertices[4].color = { 0,0,1,1 };
    _vertices[5].color = { 1,1,1,1 };

    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex_Color), _vertices.size());
}

void Quad::CreateVertices(Vector halfSize)
{
    _vertices =
    {
        {-halfSize.x, halfSize.y}, // ���� ��
        {halfSize.x, halfSize.y}, // ������ ��
        {halfSize.x, -halfSize.y}, // ������ �Ʒ�

        {-halfSize.x, halfSize.y}, // ���� ��
        {halfSize.x, -halfSize.y}, // ������ �Ʒ�
        {-halfSize.x, -halfSize.y}, // ���� �Ʒ�
    };
    _vertices[0].color = { 1,0,0,1 };
    _vertices[1].color = { 0,1,0,1 };
    _vertices[2].color = { 0,0,1,1 };

    _vertices[3].color = { 1,0,0,1 };
    _vertices[4].color = { 0,0,1,1 };
    _vertices[5].color = { 1,1,1,1 };

    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex_Color), _vertices.size());
}
