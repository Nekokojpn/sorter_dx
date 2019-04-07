#pragma once
#include "DxLib.h"
#include <stdlib.h>
#include <random>
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#include <thread>
#include <cassert>
#include <math.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")


#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024
#define ARR_LENGTH 1024
#define ARR_MAXVALUE 700
#define RADIX 100
#define ARR_WIDTH (SCREEN_WIDTH / ARR_LENGTH)


int Display();
int Display_index_red(int index);
int Display_index_red_range(int startindex, int endindex);
int Display_index_red_fromaccess();
int addToAccess(int arr_index);
int clearAccess();
int addToSuccess(int arr_index);
int clearSuccess();
void sort_destruct();

void draw_accesses();
void add_arrac();
void add_comp();
void add_step();
void initialize_sort(int updframe);
void bubble_sort();
void merge(int arr[], int start, int mid, int end);
void mergeSort(int arr[], int l, int r);
void merge_sort_call(int arr[], int l, int r);
void shuffle();
void q_sort(int numbers[], int left, int right);
void quicksort(int arr[], int left, int right);
void bitonicsort_call(int a[], int N, int up);
void bitonicSort(int a[], int low, int cnt, int dir);
void bitonicMerge(int a[], int low, int cnt, int dir);
void compAndSwap(int a[], int i, int j, int dir);
void heapsort_call(int arr[], int N);
static void downheap(int arr[], int n);
static void upheap(int arr[], int n);
void heapsort(int arr[], int n_elems);
static inline void swap(int arr[], int a, int b);
void shuffle_Arr(int ary[], int size);
void radix_sort_lsd_call(int array[]);
void radix_sort_lsd(int array[], int radix);
void CountingSortByDigit(int array[], int radix, int exponent, int minValue);
void pls(int val);

