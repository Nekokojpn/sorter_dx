#pragma once
#include "DxLib.h"
#include <stdlib.h>
#include <random>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define PUZZ_SIZE 30 //2で割り切れる数を指定
#define PUZZ_DISPX 200
#define PUZZ_DISPY 200
#define ROWS 6
#define COLS 6
#define PUZZ_DISPWIDTH (PUZZ_SIZE*COLS)
#define PUZZ_DISPHEIGHT (PUZZ_SIZE*ROWS)

typedef struct {
	int x;
	int y;
}Pos;


static int mStartTime;      //測定開始時刻
static int mCount;          //カウンタ
static float mFps;          //fps
static const int N = 60;	//平均を取るサンプル数
static const int FPS = 60;	//設定したFPS
//Init var
int board[ROWS][COLS];
bool Update() {
	if (mCount == 0) { //1フレーム目なら時刻を記憶
		mStartTime = GetNowCount();
	}
	if (mCount == N) { //60フレーム目なら平均を計算する
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = t;
	}
	mCount++;
	return true;
}

int Draw() {
	//Display();
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", mFps);
	return 0;
}

void Wait() {
	int tookTime = GetNowCount() - mStartTime;	//かかった時間
	int waitTime = mCount * 1000 / FPS - tookTime;	//待つべき時間
	if (waitTime > 0) {
		Sleep(waitTime);	//待機
	}
}
void drawCir(int *i,int *j,int *num)
{
	switch (*num)
	{
	case 1:
		DrawCircle(*j * PUZZ_SIZE + (PUZZ_SIZE / 2) + PUZZ_DISPX, *i * PUZZ_SIZE + (PUZZ_SIZE / 2) + PUZZ_DISPY, PUZZ_SIZE / 2, GetColor(255, 0, 0), TRUE);
		break;
	case 2:
		DrawCircle(*j * PUZZ_SIZE + (PUZZ_SIZE / 2) + PUZZ_DISPX, *i * PUZZ_SIZE + (PUZZ_SIZE / 2) + PUZZ_DISPY, PUZZ_SIZE / 2, GetColor(0, 255, 0), TRUE);
		break;
	case 3:
		DrawCircle(*j * PUZZ_SIZE + (PUZZ_SIZE / 2) + PUZZ_DISPX, *i * PUZZ_SIZE + (PUZZ_SIZE / 2) + PUZZ_DISPY, PUZZ_SIZE / 2, GetColor(0, 0, 255), TRUE);
		break;
	case 4:
		DrawCircle(*j * PUZZ_SIZE + (PUZZ_SIZE / 2) + PUZZ_DISPX, *i * PUZZ_SIZE + (PUZZ_SIZE / 2) + PUZZ_DISPY, PUZZ_SIZE / 2, GetColor(255, 255, 0), TRUE);
		break;
	case 5:
		DrawCircle(*j * PUZZ_SIZE + (PUZZ_SIZE / 2) + PUZZ_DISPX, *i * PUZZ_SIZE + (PUZZ_SIZE / 2) + PUZZ_DISPY, PUZZ_SIZE / 2, GetColor(196, 0, 204), TRUE);
		break;
	case 6:
		DrawCircle(*j * PUZZ_SIZE + (PUZZ_SIZE / 2) + PUZZ_DISPX, *i * PUZZ_SIZE + (PUZZ_SIZE / 2) + PUZZ_DISPY, PUZZ_SIZE / 2, GetColor(221, 132, 22), TRUE);
		break;
	default:
		break;
	}
}
int count = 0;
bool visibleflag = false;
int ssx, ssy;
int display(int selectedx = -1,int selectedy = -1)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{DrawFormatString(100, 100, GetColor(255, 0, 0), "c:%d,r:%d",selectedy,selectedx);
			if (i == selectedy && j == selectedx)
			{	
				ssx = j;
				ssy = i;
				if (count % 60 == 0)
				{
					count = 0;
					visibleflag == true ? visibleflag = false : visibleflag = true;
				}
				if(visibleflag==true)
					drawCir(&i, &j, &board[i][j]);
				
				count++;
			}
			else
			{
				drawCir(&i, &j, &board[i][j]);
			}
		}
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 16, 60);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;
	}
	SetAlwaysRunFlag(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
	
	
	/* 1:赤 2:緑 3:青 4:黄 5: 紫 6:ピンク

	*/
	//var
	int mouse;
	Pos mousepos,startpos,offsetpos;
	bool hitingkey = false;
	int curc, curr,tmp;
	startpos.x = startpos.y = 0;
	int r=-1, c=-1;
	bool selectedflag = false;

	//Romdomize puzzles
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			board[i][j] = rand() % 6 + 1;
	//Draw
	display();


	// 移動ルーチン
	while (1)
	{
		// 画面を初期化(真っ黒にする)
		ClearDrawScreen();

		if (CheckHitKey(KEY_INPUT_UP) == 1&&hitingkey==false)
		{
			tmp = board[r][c];
			board[r][c] = board[r - 1][c];
			board[r - 1][c] = tmp;
			hitingkey = true;
		}
		else if (CheckHitKey(KEY_INPUT_UP) == 0)
		{
			hitingkey = false;
		}
		else if (CheckHitKey(KEY_INPUT_DOWN) == 1 && hitingkey == false)
		{
			tmp = board[r][c];
			board[r][c] = board[r + 1][c];
			board[r + 1][c] = tmp; hitingkey = true;
		}
		else if (CheckHitKey(KEY_INPUT_DOWN) == 0)
		{
			hitingkey = false;
		}
		else if (CheckHitKey(KEY_INPUT_LEFT) == 1 && hitingkey == false)
		{
			tmp = board[r][c];
			board[r][c] = board[r][c-1];
			board[r][c-1] = tmp; hitingkey = true;
		}
		else if (CheckHitKey(KEY_INPUT_LEFT) == 0)
		{
			hitingkey = false;
		}
		else if (CheckHitKey(KEY_INPUT_RIGHT) == 1 && hitingkey == false)
		{
			tmp = board[r][c];
			board[r][c] = board[r][c+1];
			board[r][c+1] = tmp; hitingkey = true;
		}
		else if (CheckHitKey(KEY_INPUT_RIGHT) == 0)
		{
			hitingkey = false;
		}
		//とりあえずマウスでは後で
		
		mouse = GetMouseInput();
		GetMousePoint(&mousepos.x, &mousepos.y);
		if ((mouse & MOUSE_INPUT_LEFT) != 0||selectedflag==true)
		{
			startpos.x = mousepos.x;
			startpos.y = mousepos.y;
			//クリック範囲をチェック
			if (startpos.x > PUZZ_DISPWIDTH + PUZZ_DISPX || startpos.x<PUZZ_DISPX || startpos.y>PUZZ_DISPHEIGHT + PUZZ_DISPY || startpos.y < PUZZ_DISPY)
				//selectedflag = false;
				goto draw;
			offsetpos.x = startpos.x - PUZZ_DISPX;
			offsetpos.y = startpos.y - PUZZ_DISPY;
			if (r != offsetpos.x % PUZZ_SIZE || c != offsetpos.y % PUZZ_SIZE)
			{
				DrawFormatString(0, 50, GetColor(255, 0, 0), "ox:%d , oy:%d", offsetpos.x, offsetpos.y);
				r = offsetpos.x / PUZZ_SIZE;
				c = offsetpos.y / PUZZ_SIZE;
				curc = c;
				curr = r;
				selectedflag = true;
				goto draw_end;
			}
			else
			{
				goto draw_end;
			}
		}
	draw:
		DrawFormatString(0, 0, GetColor(255, 0, 0), "x:%d , y:%d", mousepos.x, mousepos.y);
		DrawFormatString(0, 20, GetColor(255, 0, 0), "sx:%d , sy:%d", startpos.x, startpos.y);
		display();
		ScreenFlip();
		continue;

	draw_end:
		DrawFormatString(0, 0, GetColor(255, 0, 0), "x:%d , y:%d", mousepos.x, mousepos.y);
		DrawFormatString(0, 20, GetColor(255, 0, 0), "sx:%d , sy:%d", startpos.x, startpos.y);
		display(r,c);
		ScreenFlip();
		continue;
		


		// Windows 特有の面倒な処理をＤＸライブラリにやらせる
		// -1 が返ってきたらループを抜ける
		if (ProcessMessage() < 0) break;
	}
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;		
}


