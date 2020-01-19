#include <stdio.h>
#include <stdlib.h>

void dealmergesort(int* arr,int* temp,int start,int end)
{
	if (start >= end){
		return;
	}
	int mid = (start + end) / 2;

	dealmergesort(arr, temp, start, mid);
	dealmergesort(arr, temp, mid + 1, end);

	int left = start;   //左侧数组的起始指针
	int right = mid + 1;  //右侧数组的起始指针
	int merge = left;  //temp的起始指针

	for (; left <= mid && right <= end;merge++)
	{
		if (arr[left] <= arr[right])
		{
			temp[merge] = arr[left];
			left++;
		}
		else
		{
			temp[merge] = arr[right];
			right++;
		}
	}
	for (; left <= mid; left++, merge++)
	{
		temp[merge] = arr[left];
	}
	for (; right <= end; right++, merge++)
	{
		temp[merge] = arr[right];
	}
	for (int i = start; i <= end; i++)
	{
		arr[i] = temp[i];
	}
}

void mergesort(int* arr, int n)
{
	int* temp = (int*)malloc(n*sizeof(int));

	dealmergesort(arr, temp, 0, n-1);
	free(temp);
}

int main()
{
	int arr[] = { 7, 9, 6, 3, 5, 4, 1, 2 };
	mergesort(arr, 8);
	
	return 0;
}