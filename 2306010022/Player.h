#pragma once

//�萔
static float MOVESPEED = 10.0f;//�v���C���[�̈ړ��X�s�[�h�i����͌Œ�j
//�N���X
class Player
{
public:



	//�X�e�[�^�X�iHP,�U����,�h��,�X�s�[�h�j
	float HP;
	float ATK;
	float DEF;
	float SPEED;
	//�摜�`��
	int PlayerGraph[390];//(��30��(288px),�c13(128px))



	
	//�ړ�����
	
	//�A�j���[�V��������
	//�U�����[�V����
	

	//�֐�
	void Init();//������
	void Draw();///�`��
};




