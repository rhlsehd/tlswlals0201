#pragma once
class SRV
{
public:
	SRV(wstring path);
	~SRV();

	void PSSet_SRV(int slot);

	Vector GetImageSize();

private:
	void CreateSRV(wstring path);

	ScratchImage image;

	// TextureMapping
	// 1. Texture(source, ���ϸ�) => SIUUUU
	// 2. ShaderResourceView(�ǹ��̸� ����� ������)
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> srv;
};

