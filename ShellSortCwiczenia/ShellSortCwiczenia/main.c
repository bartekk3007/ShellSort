#include <stdio.h>
#include <stdlib.h>

void printArray(int* tab, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", tab[i]);
	}
	printf("\n");
}

void swap(int* arr, int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int returnCeiling(int dividend, int divisor)
{
	if (dividend % divisor == 0)
	{
		return dividend / divisor;
	}
	else
	{
		return dividend / divisor + 1;
	}
}

int KnuthsInterval(int size)
{
	int interval = 1;
	while (3 * interval + 1 <= returnCeiling(size, 3))
	{
		interval = interval * 3 + 1;
	}
	return interval;
}

void sort(int* arr, int size)
{
	int interval;
	for (interval = KnuthsInterval(size); interval > 0; interval = (interval - 1) / 3)
	{
		for (int i = 0; i < size; i++)
		{
			int j = i;
			if (j - interval >= 0 && arr[j - interval] > arr[j])
			{
				swap(arr, j, j - interval);
				j -= interval;
			}
		}
	}
}

int main(void)
{
	int arr[] = { 55, 13, 34, 21, 89, 5, 8, 144, 1, 2, 3, };
	int size = sizeof(arr) / sizeof(*arr);

	sort(arr, size);

	printArray(arr, size);

	return 0;
}