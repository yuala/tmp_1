#include"DxLib.h"
#include"Player.h"


void Player::Init()
{
	LoadDivGraph("data/texture/Player.png", 390, 30, 13, 288, 128, PlayerGraph);
}




void Player::Draw()
{
	for(int i = 0; i < 8; i++)
	{

		DrawGraph(500, 500, PlayerGraph[i], TRUE);
	}
	
}