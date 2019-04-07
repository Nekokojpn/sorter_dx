#include "DxLib.h"

int WINAPI WinMain1(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	int ScreenFlipCount, StartTime, FrameTime;
	int x;


	SetGraphMode(640, 480, 16);
	if (DxLib_Init() == -1)	// ＤＸライブラリ初期化処理
	{
		return -1;		// エラーが起きたら直ちに終了
	}

	// 描画先画面を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	// 計測中に別のウインドウがアクティブになっても問題が無いように常時実行フラグをセット
	SetAlwaysRunFlag(TRUE);

	// １フレームにかかる時間を計測
	ScreenFlip();
	ScreenFlipCount = 0;
	StartTime = GetNowCount();
	for (;;)
	{
		// 画面切り替えを行ってＶＹＳＮＣ待ちをする
		ScreenFlip();

		// １秒経過していたらループから抜ける
		if (GetNowCount() - StartTime >= 1000)
			break;

		// ScreenFlip を行った回数をインクリメント
		ScreenFlipCount++;
	}

	// 常時実行フラグを元に戻す
	SetAlwaysRunFlag(FALSE);

	// 計測時間を ScreenFlip を行った回数で割れば
	// ScreenFlip 一回辺りの時間が取得できます
	FrameTime = 1000 / ScreenFlipCount;

	
	int arr[100],i,j,temp;
	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand() % 500;
	}

	while (ProcessMessage() == 0 && CheckHitKeyAll() == 0&&i<199)
	{
		// 画面を消去
		ClearDrawScreen();

		// 四角の描画位置を移動(１秒間で画面を横切る速さに設定
		x += 6400 * FrameTime / 1000;
		if (x > 640 * 10) x = 0;

		// 四角を描画
		DrawBox(x / 10, 0, x / 10 + 32, 32, GetColor(255, 255, 255), TRUE);

		i++;
		// 裏画面の内容を表画面に反映させる
		ScreenFlip();
	}

	DxLib_End();		// ＤＸライブラリ使用の終了処理

	return 0;		// ソフトの終了
}