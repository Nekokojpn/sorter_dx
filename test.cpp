#include "DxLib.h"

int WINAPI WinMain1(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	int ScreenFlipCount, StartTime, FrameTime;
	int x;


	SetGraphMode(640, 480, 16);
	if (DxLib_Init() == -1)	// �c�w���C�u��������������
	{
		return -1;		// �G���[���N�����璼���ɏI��
	}

	// �`����ʂ𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);

	// �v�����ɕʂ̃E�C���h�E���A�N�e�B�u�ɂȂ��Ă���肪�����悤�ɏ펞���s�t���O���Z�b�g
	SetAlwaysRunFlag(TRUE);

	// �P�t���[���ɂ����鎞�Ԃ��v��
	ScreenFlip();
	ScreenFlipCount = 0;
	StartTime = GetNowCount();
	for (;;)
	{
		// ��ʐ؂�ւ����s���Ău�x�r�m�b�҂�������
		ScreenFlip();

		// �P�b�o�߂��Ă����烋�[�v���甲����
		if (GetNowCount() - StartTime >= 1000)
			break;

		// ScreenFlip ���s�����񐔂��C���N�������g
		ScreenFlipCount++;
	}

	// �펞���s�t���O�����ɖ߂�
	SetAlwaysRunFlag(FALSE);

	// �v�����Ԃ� ScreenFlip ���s�����񐔂Ŋ����
	// ScreenFlip ���ӂ�̎��Ԃ��擾�ł��܂�
	FrameTime = 1000 / ScreenFlipCount;

	
	int arr[100],i,j,temp;
	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand() % 500;
	}

	while (ProcessMessage() == 0 && CheckHitKeyAll() == 0&&i<199)
	{
		// ��ʂ�����
		ClearDrawScreen();

		// �l�p�̕`��ʒu���ړ�(�P�b�Ԃŉ�ʂ����؂鑬���ɐݒ�
		x += 6400 * FrameTime / 1000;
		if (x > 640 * 10) x = 0;

		// �l�p��`��
		DrawBox(x / 10, 0, x / 10 + 32, 32, GetColor(255, 255, 255), TRUE);

		i++;
		// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();
	}

	DxLib_End();		// �c�w���C�u�����g�p�̏I������

	return 0;		// �\�t�g�̏I��
}