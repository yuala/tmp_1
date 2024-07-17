#include"DxLib.h"
#include"BattleMap.h"
#include"Player.h"


// WinMain関数
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	
	// 画面モードの設定
	SetGraphMode(1920, 1080, 16);		// 解像度を640*480、colorを16bitに設定.
	ChangeWindowMode(FALSE);			// ウインドウモードを変更(FALSE＝フルクリーン)

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// グラフィックの描画先を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);




	////////////////////////////////////////
	//初期化・インスタンス
	///////////////////////////////////////

	BattleMap* map = new BattleMap();
	Player* player = new Player();


	map->InitMap();  
	player->Init();
	




	// ゲームループ.
	while (1)
	{

		// 画面を初期化(真っ黒にする)
		ClearDrawScreen();
	

		///////////////////////////////////////////////
		//メイン処理
		///////////////////////////////////////////////


		map -> DrawMap();

		//-------------------------------------------//
		//プレイヤー処理
		//-------------------------------------------//

		player->Draw();


			
		// 裏画面の内容を表画面にコピーする（描画の確定）.
		ScreenFlip();

		// Windows 特有の面倒な処理をＤＸライブラリにやらせる
		// マイナスの値（エラー値）が返ってきたらループを抜ける
		if (ProcessMessage() < 0)
		{

			DxLib_End();				// ＤＸライブラリ使用の終了処理
			return 0;					// ソフトの終了
			break;
		}
		// もしＥＳＣキーが押されていたらループから抜ける
		else if (CheckHitKey(KEY_INPUT_ESCAPE))
		{

			DxLib_End();				// ＤＸライブラリ使用の終了処理
			return 0;					// ソフトの終了
			break;
		}
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;					// ソフトの終了
}

