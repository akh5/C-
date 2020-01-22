#include <stdio.h>

void Swap(int*a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void dealsort(int *arr, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int flag = 1;
	int i = start, j = end;
	while (i<j)
	{
		if (arr[i] > arr[j])
		{
			Swap(arr[i], arr[j]);
			flag = !flag;
		}
		if (flag == 1)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	dealsort(arr, start, i - 1);
	dealsort(arr, i + 1, end);
}

void quicksort(int* arr, int n)
{
	dealsort(arr, 0, n - 1);
}

int main()
{

	return 0;
}