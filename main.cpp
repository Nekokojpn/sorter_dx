#pragma once
#include "main.h"


int ARR[ARR_LENGTH];
static int comparison;
static int arrayaccess;
static int step;
char buf[100];
int access[ARR_LENGTH]; //アクセスした番号を格納しておきます
int success[ARR_LENGTH];//ソート済みの番号を格納しておきます
int ac = 0;//アクセスのスタックカウンタ
int sc = 0;
int updateframe;
int c = 0;

bool dis = false;
int s;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
	ChangeWindowMode(TRUE);
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT,16,144);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	s =  LoadSoundMem("C:\Resources\w.wav");
	PlaySoundMem(s, DX_PLAYTYPE_NORMAL);
	SetAlwaysRunFlag(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
	WaitTimer(1000);
	shuffle();
	
	/*
	radix_sort_lsd_call(ARR);
	WaitTimer(1000);
	shuffle();
	WaitTimer(1000);
	bubble_sort();
	WaitTimer(1000);
	shuffle();
	WaitTimer(1000);
    merge_sort_call(ARR, 0, ARR_LENGTH);
	WaitTimer(1000);
	shuffle();
	WaitTimer(1000);
	quicksort(ARR, 0, ARR_LENGTH);
	WaitTimer(1000);
	*/
	WaitTimer(1000);
	bitonicsort_call(ARR, ARR_LENGTH, 1);
	WaitTimer(1000);
	/*
	shuffle();
	WaitTimer(1000);
	heapsort_call(ARR, ARR_LENGTH);
	*/
	ClearDrawScreen();
	for (int i = 0; i < ARR_LENGTH; i++)
	{
		DrawBox(i*ARR_WIDTH, SCREEN_HEIGHT, i*ARR_WIDTH + ARR_WIDTH, SCREEN_HEIGHT - ARR[i], GetColor(255, 255, 255), TRUE);
	}
	draw_accesses();
	ScreenFlip();
	WaitKey();	
	DxLib_End();
	return 0;
}

void bubble_sort()
{
	initialize_sort(150);
	int i, j, temp;
	for (i = 0; i < ARR_LENGTH - 1; i++)
	{	
		for (j = ARR_LENGTH - 1; j > i; j--)
		{
			add_step();
			addToAccess(j);
			add_comp();
			add_arrac();
			add_arrac();
			if (ARR[j - 1] > ARR[j])
			{
				temp = ARR[j - 1];
				ARR[j - 1] = ARR[j];
				ARR[j] = temp;
			}
			if (c == updateframe)//更新フレーム間
			{
				Display_index_red_fromaccess();
				c = 0;
			}
			c++;
		}
		addToSuccess(i);
	}
	Display();
	clearAccess();
	clearSuccess();
}
void add_step()
{
	step++;
}
void add_comp()
{
	comparison++;
}
void add_arrac()
{
	arrayaccess++;
}
int Display()
{
	ClearDrawScreen();
	draw_accesses();
	for (int i = 0; i < ARR_LENGTH; i++)
	{
		DrawBox(i*ARR_WIDTH, SCREEN_HEIGHT, i*ARR_WIDTH + ARR_WIDTH, SCREEN_HEIGHT - ARR[i], GetColor(255, 255, 255), TRUE);
	}
	ScreenFlip();
	return 0;
}
int Display_index_red(int index)
{
	ClearDrawScreen();
	draw_accesses();
	for (int i = 0; i < ARR_LENGTH; i++)
	{
		if (i == index)
		{
			DrawBox(i*ARR_WIDTH, SCREEN_HEIGHT, i*ARR_WIDTH + ARR_WIDTH, SCREEN_HEIGHT - ARR[i], GetColor(255, 0, 0), TRUE);
			continue;
		}
		DrawBox(i*ARR_WIDTH, SCREEN_HEIGHT, i*ARR_WIDTH + ARR_WIDTH, SCREEN_HEIGHT - ARR[i], GetColor(255, 255, 255), TRUE);
	}
	ScreenFlip();
	return 0;
}
//かならずstartindex<endindex
int Display_index_red_range(int startindex,int endindex)
{
	ClearDrawScreen();
	draw_accesses();
	for (int i = 0; i < ARR_LENGTH; i++)
	{
		if (i >= startindex&&i<=endindex)
		{
			DrawBox(i * ARR_WIDTH, SCREEN_HEIGHT, i * ARR_WIDTH + ARR_WIDTH, SCREEN_HEIGHT - ARR[i], GetColor(255, 0, 0), TRUE);
			continue;
		}
		DrawBox(i * ARR_WIDTH, SCREEN_HEIGHT, i * ARR_WIDTH + ARR_WIDTH, SCREEN_HEIGHT - ARR[i], GetColor(255, 255, 255), TRUE);
	}
	ScreenFlip();
	return 0;
}
int Display_index_red_fromaccess()
{
	ClearDrawScreen();
	draw_accesses();
	for (int i = 0; i < ARR_LENGTH; i++)
	{	
		DrawBox(i * ARR_WIDTH, SCREEN_HEIGHT, i * ARR_WIDTH + ARR_WIDTH, SCREEN_HEIGHT - ARR[i], GetColor(255, 255, 255), TRUE);
		for(int j = 0; j<ARR_LENGTH;j++)
		{
			if (access[j] == i)
			{
				DrawBox(i * ARR_WIDTH, SCREEN_HEIGHT, i * ARR_WIDTH + ARR_WIDTH, SCREEN_HEIGHT - ARR[i], GetColor(255, 0, 0), TRUE);
				pls(ARR[i]);
				break;
			}
			if (success[j] == i)
			{
				DrawBox(i * ARR_WIDTH, SCREEN_HEIGHT, i * ARR_WIDTH + ARR_WIDTH, SCREEN_HEIGHT - ARR[i], GetColor(0, 255, 0), TRUE);
			}
		}
		
	}
	clearAccess();
	ScreenFlip();
	return 0;
}
void draw_accesses()
{
	DrawFormatString(0, 0, GetColor(255, 255, 0), "Array accesses: %d Comparisons: %d Update frame: %d",arrayaccess, comparison,updateframe);
}
int addToAccess(int arr_index)
{
	access[ac] = arr_index;
	ac++;
	return 0;
}
int clearAccess()
{
	ac = 0;
	for (int i = 0; i < ARR_LENGTH; i++)
	{
		access[i] = -1;
	}
	return 0;
}
int addToSuccess(int arr_index)
{
	success[sc] = arr_index;
	sc++;
	return 0;
}
int clearSuccess()
{
	sc = 0;
	for (int i = 0; i < ARR_LENGTH; i++)
	{
		success[i] = -1;
	}
	return 0;
}
void initialize_sort(int updframe)
{
	updateframe = updframe;
	comparison = 0;
	arrayaccess = 0;
	step = 0;
	clearAccess();
	clearSuccess();
}
void shuffle()
{
	initialize_sort(0);
	for (int i = 0; i < ARR_LENGTH; i++)
	{
		addToAccess(i);
		ARR[i] = (i + 1); //* ARR_MAXVALUE) / (SCREEN_HEIGHT - 100);
		
		if (c == 2)
		{
			Display_index_red_fromaccess();
			c = 0;
		}
		c++;
	}
	shuffle_Arr(ARR, ARR_LENGTH);
	Display();
}
void pls(int val)
{

	SetFrequencySoundMem(200 + val,s);
	PlaySoundMem(s, DX_PLAYTYPE_NORMAL);
}
void sort_destruct()
{
	clearAccess();
	clearSuccess();
}
void shuffle_Arr(int ary[], int size)
{
	c = 0;
	WaitTimer(1000);
	for (int i = 0; i < size; i++)
	{
		
		int j = rand() % size;
		int t = ary[i];
		ary[i] = ary[j];
		ary[j] = t;
		addToAccess(i);
		addToAccess(j);
		if (c == 2)
		{
			Display_index_red_fromaccess();
			c = 0;
		}
		c++;
	}
}
