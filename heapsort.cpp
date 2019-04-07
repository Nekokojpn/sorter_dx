#include "main.h"
int updateframeh;
int hc = 0;
static inline void swap(int arr[], int a, int b)
{
	addToAccess(a);
	addToAccess(b);
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
	if (hc == updateframeh)
	{
		Display_index_red_fromaccess();
		hc = 0;
	}
	hc++;
}
void heapsort(int arr[], int n_elems)
{
	int i = 0;
	while (++i < n_elems) {
		upheap(arr, i);
	}
	while (--i > 0) {
		swap(arr, 0, i);
		downheap(arr, i);
	}
}

#define LEFT_CHILD(i)  (((i) + 1) * 2 - 1)
#define RIGHT_CHILD(i) (((i) + 1) * 2)
#define PARENT(i)      (((i) + 1) / 2 - 1)


static void upheap(int arr[], int n)
{
	
	while (n > 0) {
		int m = PARENT(n);

		add_arrac();
		add_arrac();
		add_comp();
		addToAccess(m);
		addToAccess(n);
		if (arr[m] < arr[n]) {
			swap(arr, m, n);
		}
		else {
			break;
		}
		if (hc == updateframeh)
		{
			Display_index_red_fromaccess();
			hc = 0;
		}
		hc++;
		n = m;
	}

	
}

static void downheap(int arr[], int n)
{
	int m = 0;
	int tmp = 0;

	for (;;) {
		int l_chld = LEFT_CHILD(m);
		int r_chld = RIGHT_CHILD(m);
		if (l_chld >= n) {
			break;
		}
		add_arrac();
		add_arrac();
		add_comp();
		addToAccess(l_chld);
		addToAccess(tmp);
		if (arr[l_chld] > arr[tmp]) {
			tmp = l_chld;
		}
		add_arrac();
		add_arrac();
		add_comp();
		addToAccess(r_chld);
		addToAccess(tmp);
		if ((r_chld < n) && (arr[r_chld] > arr[tmp])) {
			tmp = r_chld;
		}

		if (tmp == m) {
			break;
		}
		if (hc == updateframeh)
		{
			Display_index_red_fromaccess();
			hc = 0;
		}
		hc++;
		swap(arr, tmp, m);
		m = tmp;
	}
}
void heapsort_call(int arr[], int N)
{	
	initialize_sort(5);
	updateframeh = 5;
	heapsort(arr, N);
	Display();
	sort_destruct();
}