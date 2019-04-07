#include "main.h"
int updateframer;
int rc = 0;
void radix_sort_lsd_call(int array[]) 
{
	initialize_sort(5);
	updateframer = 5;
	radix_sort_lsd(array, RADIX);
	Display();
	sort_destruct();
}

void radix_sort_lsd(int array[], int radix)
{

	// Determine minimum and maximum values
	int minValue = array[0];
	int maxValue = array[0];
	for (int i = 1; i < ARR_LENGTH; i++) {
		add_arrac();
		if (array[i] < minValue) {
			minValue = array[i];
			add_arrac();
		}	
		else if (array[i] > maxValue) {
			maxValue = array[i];
			add_arrac();
		}
		if (rc == updateframer)
		{
			Display_index_red_fromaccess();
			rc = 0;
		}
		rc++;
		add_arrac();
	}

	// Perform counting sort on each exponent/digit, starting at the least
	// significant digit
	int exponent = 1;
	while ((maxValue - minValue) / exponent >= 1) {
		CountingSortByDigit(array, radix, exponent, minValue);
		exponent *= radix;
		if (rc == updateframer)
		{
			Display_index_red_fromaccess();
			rc = 0;
		}
		rc++;
	}
}

void CountingSortByDigit(int array[], int radix, int exponent, int minValue)
{
	int bucketIndex;
	int buckets[RADIX];
	int output[ARR_LENGTH];

	// Initialize bucket
	for (int i = 0; i < radix; i++) {
		add_arrac();
		buckets[i] = 0;
		if (rc == updateframer)
		{
			Display_index_red_fromaccess();
			rc = 0;
		}
		rc++;
	}

	// Count frequencies
	for (int i = 0; i < ARR_LENGTH; i++) {
		add_arrac();
		bucketIndex = (int)(((array[i] - minValue) / exponent) % radix);
		buckets[bucketIndex]++;
		if (rc == updateframer)
		{
			Display_index_red_fromaccess();
			rc = 0;
		}
		rc++;
	}

	// Compute cumulates
	for (int i = 1; i < radix; i++) {
		buckets[i] += buckets[i - 1];
		if (rc == updateframer)
		{
			Display_index_red_fromaccess();
			rc = 0;
		}
		rc++;
	}

	// Move records
	for (int i = ARR_LENGTH - 1; i >= 0; i--) {
		add_arrac();
		bucketIndex = (int)(((array[i] - minValue) / exponent) % radix);
		output[--buckets[bucketIndex]] = array[i];
		if (rc == updateframer)
		{
			Display_index_red_fromaccess();
			rc = 0;
		}
		rc++;
	}

	// Copy back
	for (int i = 0; i < ARR_LENGTH; i++) {
		add_arrac();
		array[i] = output[i];
		if (rc == updateframer)
		{
			Display_index_red_fromaccess();
			rc = 0;
		}
		rc++;
	}
}