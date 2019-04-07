#include "main.h"
int updateframem;
int mc = 0;
void merge(int arr[], int start, int mid, int end)
{
	int start2 = mid + 1;

	// If the direct merge is already sorted 
	add_arrac();
	add_arrac();
	add_comp();
	if (arr[mid] <= arr[start2]) {
		return;
	}

	// Two pointers to maintain start 
	// of both arrays to merge 
	while (start <= mid && start2 <= end) {

		add_arrac();
		add_arrac();
		add_comp();
		addToAccess(start);
		addToAccess(start2);
		// If element 1 is in right place 
		if (arr[start] <= arr[start2]) {
			if (mc == updateframem)
			{
				Display_index_red_fromaccess();
				mc = 0;
			}
			mc++;
			start++;
		}
		else {
			add_arrac();
			int value = arr[start2];
			int index = start2;
			addToAccess(start2);
			// Shift all the elements between element 1 
			// element 2, right by 1. 
			while (index != start) {
				add_arrac();
				add_arrac();
				arr[index] = arr[index - 1];
				addToAccess(index);
				addToAccess(index - 1);
				index--;
				if (mc == updateframem)
				{
					Display_index_red_fromaccess();
					mc = 0;
				}
				mc++;
			}
			arr[start] = value;

			if (mc == updateframem)
			{
				Display_index_red_fromaccess();
				mc = 0;
			}
			mc++;
			// Update all the pointers 
			start++;
			mid++;
			start2++;
		}
	}
	clearAccess();
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {

		// Same as (l + r) / 2, but avoids overflow 
		// for large l and r 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void merge_sort_call(int arr[], int l, int r)
{
	initialize_sort(60);
	updateframem = 60;
	mergeSort(arr, l, r);
	Display();
	sort_destruct();
}