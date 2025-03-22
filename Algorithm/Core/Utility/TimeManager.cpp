#include "framework.h"
#include "TimeManager.h"

TimeManager* TimeManager::_instance = nullptr;

TimeManager::TimeManager()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency); // 1�ʴ� CPU ������ : 100

	QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime); // �ֱ� ������ ������ : 0

	_timeScale = 1.0 / (double)_periodFrequency;
}

TimeManager::~TimeManager()
{

}

void TimeManager::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&_curTime); // ���� Update ������ : 110
	_deltaTime = (double)(_curTime - _lastTime) * _timeScale; // cur(110), last(100) => 10 /  1�ʴ� CPU ������ => 1�� ������Ʈ�� �귯�� �ð�

	// lockFPS : ������ ����
	if (_lockFPS != 0)
	{
		// �ݺ������� Update ����
		while (_deltaTime < (1.0 / _lockFPS))
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			_deltaTime = (double)(_curTime - _lastTime) * _timeScale;
		}
	}

	_lastTime = _curTime; // last : 100

	_frameCount++;
	_oneSecCount += _deltaTime;

	// ���� 1�ʰ� �귶��.
	if (_oneSecCount > 1.0)
	{
		_oneSecCount = 0.0;
		_frameRate = _frameCount; // frameRate : 1�ʿ� ��� ������Ʈ�� �Ǿ�����
		_frameCount = 0;
	}

	_runTime += _deltaTime; // ���� ������ ����� �ð�
}
