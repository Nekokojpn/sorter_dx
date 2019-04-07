#include "main.h"

int updateframeq;
int qc = 0;
void q_sort(int numbers[], int left, int right)
{
	int pivot, l_hold, r_hold;

	l_hold = left;
	r_hold = right;
	pivot = numbers[left];
	addToAccess(left);
	if (qc == updateframeq)
	{
		Display_index_red_fromaccess();
		qc = 0;
	}
	qc++;
	while (left < right)
	{
		add_arrac();
		add_comp();
		
		while ((numbers[right] >= pivot) && (left < right))
		{
			addToAccess(right);
			if (qc == updateframeq)
			{
				Display_index_red_fromaccess();
				qc = 0;
			}
			qc++;
			right--;
		}
		if (qc == updateframeq)
		{
			Display_index_red_fromaccess();
			qc = 0;
		}
		qc++;
		if (left != right)
		{
			add_arrac();
			add_arrac();
			addToAccess(left);
			addToAccess(right);
			numbers[left] = numbers[right];
			left++;
		}
		if (qc == updateframeq)
		{
			Display_index_red_fromaccess();
			qc = 0;
		}
		qc++;
		add_arrac();
		add_comp();
		addToAccess(left);
		while ((numbers[left] <= pivot) && (left < right))
		{
			addToAccess(left);
			if (qc == updateframeq)
			{
				Display_index_red_fromaccess();
				qc = 0;
			}
			qc++;
			left++;
		}
		if (left != right)
		{
			add_arrac();
			add_arrac();
			numbers[right] = numbers[left];
			right--;
		}
		if (qc == updateframeq)
		{
			Display_index_red_fromaccess();
			qc = 0;
		}
		qc++;
	}
	add_arrac();
	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot)
		q_sort(numbers, left, pivot - 1);
	if (right > pivot)
		q_sort(numbers, pivot + 1, right);
}
void quicksort(int arr[], int left, int right)
{
	initialize_sort(5);
	updateframeq = 5;
	q_sort(arr, left, right);
	Display();
	sort_destruct();
}