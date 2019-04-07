#include "main.h"
int updateframeb;
int bc = 0;
void compAndSwap(int a[], int i, int j, int dir)
{
	add_step();
	add_arrac();
	add_arrac();
	add_comp();
	addToAccess(i);
	addToAccess(j);
	if (dir == (a[i] > a[j]))
	{
		std::swap(a[i], a[j]);
	}
	if (bc == updateframeb)
	{
		Display_index_red_fromaccess();
		bc = 0;
	}
	bc++;
}

/*It recursively sorts a bitonic sequence in ascending order,
  if dir = 1, and in descending order otherwise (means dir=0).
  The sequence to be sorted starts at index position low,
  the parameter cnt is the number of elements to be sorted.*/
void bitonicMerge(int a[], int low, int cnt, int dir)
{
	
	if (cnt > 1)
	{
		int k = cnt / 2;
		for (int i = low; i < low + k; i++)
		{
			compAndSwap(a, i, i + k, dir);
		}
		if (bc == updateframeb)
		{
			Display_index_red_fromaccess();
			bc = 0;
		}
		bc++;
		bitonicMerge(a, low, k, dir);
		if (bc == updateframeb)
		{
			Display_index_red_fromaccess();
			bc = 0;
		}
		bc++;
		bitonicMerge(a, low + k, k, dir);
		if (bc == updateframeb)
		{
			Display_index_red_fromaccess();
			bc = 0;
		}
		bc++;
	}
}

/* This function first produces a bitonic sequence by recursively
	sorting its two halves in opposite sorting orders, and then
	calls bitonicMerge to make them in the same order */
void bitonicSort(int a[], int low, int cnt, int dir)
{
	if (cnt > 1)
	{
		int k = cnt / 2;

		// sort in ascending order since dir here is 1 
		bitonicSort(a, low, k, 1);

		// sort in descending order since dir here is 0 
		bitonicSort(a, low + k, k, 0);

		// Will merge wole sequence in ascending order 
		// since dir=1. 
		bitonicMerge(a, low, cnt, dir);
	}
}

/* Caller of bitonicSort for sorting the entire array of
   length N in ASCENDING order */
void bitonicsort_call(int a[], int N, int up)
{
	initialize_sort(10);
	updateframeb = 10;
	bitonicSort(a, 0, N, up);
	Display();
	sort_destruct();
}