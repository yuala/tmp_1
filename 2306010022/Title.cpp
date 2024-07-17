#include"DxLib.h"
#include"BattleMap.h"
#include"Player.h"


// WinMain�֐�
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	
	// ��ʃ��[�h�̐ݒ�
	SetGraphMode(1920, 1080, 16);		// �𑜓x��640*480�Acolor��16bit�ɐݒ�.
	ChangeWindowMode(FALSE);			// �E�C���h�E���[�h��ύX(FALSE���t���N���[��)

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// �O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);




	////////////////////////////////////////
	//�������E�C���X�^���X
	///////////////////////////////////////

	BattleMap* map = new BattleMap();
	Player* player = new Player();


	map->InitMap();  
	player->Init();
	




	// �Q�[�����[�v.
	while (1)
	{

		// ��ʂ�������(�^�����ɂ���)
		ClearDrawScreen();
	

		///////////////////////////////////////////////
		//���C������
		///////////////////////////////////////////////


		map -> DrawMap();

		//-------------------------------------------//
		//�v���C���[����
		//-------------------------------------------//

		player->Draw();


			
		// ����ʂ̓��e��\��ʂɃR�s�[����i�`��̊m��j.
		ScreenFlip();

		// Windows ���L�̖ʓ|�ȏ������c�w���C�u�����ɂ�点��
		// �}�C�i�X�̒l�i�G���[�l�j���Ԃ��Ă����烋�[�v�𔲂���
		if (ProcessMessage() < 0)
		{

			DxLib_End();				// �c�w���C�u�����g�p�̏I������
			return 0;					// �\�t�g�̏I��
			break;
		}
		// �����d�r�b�L�[��������Ă����烋�[�v���甲����
		else if (CheckHitKey(KEY_INPUT_ESCAPE))
		{

			DxLib_End();				// �c�w���C�u�����g�p�̏I������
			return 0;					// �\�t�g�̏I��
			break;
		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	return 0;					// �\�t�g�̏I��
}

