#pragma once

//定数
static float MOVESPEED = 10.0f;//プレイヤーの移動スピード（今回は固定）
//クラス
class Player
{
public:



	//ステータス（HP,攻撃力,防御,スピード）
	float HP;
	float ATK;
	float DEF;
	float SPEED;
	//画像描画
	int PlayerGraph[390];//(横30枚(288px),縦13(128px))



	
	//移動処理
	
	//アニメーション処理
	//攻撃モーション
	

	//関数
	void Init();//初期化
	void Draw();///描画
};




