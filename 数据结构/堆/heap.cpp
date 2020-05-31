#include <stdio.h>

void swap(int* heap, int i, int j)
{
	int temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
}

void heapify(int* heap,int n,int i)
{
	int max = i;
	int cl = 2 * i + 1; //左子结点
	int cr = 2 * i + 2; //右子结点
	if (i >= n)
	{
		return;
	}
	if (cl<n&&heap[cl]>heap[max])  
	{
		max = cl;
	}
	if (cr<n&&heap[cr]>heap[max])
	{
		max = cr;
	}
	if (max != i)
	{
		swap(heap, max, i);
		heapify(heap, n, max);
	}
}

void build_heap(int* heap, int n)
{
	int parent = (n - 2) / 2;
	for (int i = parent; i >= 0; i--)
	{
		heapify(heap, n, i);
	}
}

void heap_sort(int* heap, int n)
{
	build_heap(heap, 10);
	for (int i = n-1; i >= 0; i--)
	{
		swap(heap, 0, i);
		heapify(heap, i,0);
	}
}

int main()
{
	int heap[] = { 2, 5, 1, 10, 4, 6, 8, 3, 9, 7 };

	int test[] = { 1,2, 3 };
	heapify(test, 3, 0);
	build_heap(heap, 10);
	heap_sort(heap, 10);

	return 0;
}