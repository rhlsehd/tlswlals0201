#pragma once
class SamplerState
{
public:
	SamplerState();
	~SamplerState();

	void PSSet_Sampler(int slot);
private:
	void CreateSamplerState();

	// 3. SamplerState(�ǹ��̸� ������ ������)
	Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState;
};

