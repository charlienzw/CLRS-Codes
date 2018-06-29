#include <bits/stdc++.h>
#include "Heap.h"
using namespace std;

Heap::Heap(int n)
{
	arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = 0;
}

Heap::~Heap()
{
	delete []arr;
}

void Heap::HeapInit(int N)
{
	heap_size = N;
	for (int i = 0; i < heap_size; i++)
		scanf("%d", &arr[i]);
}

void Heap::PrintHeap()
{
	for (int i = 0; i < heap_size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int Heap::Parent(int i)
{
	return (i+1)/2-1;
}

int Heap::Left(int i)
{
	return (i+1)*2-1;
}

int Heap::Right(int i)
{
	return (i+1)*2;
}

int& Heap::operator[](int i)
{
	return arr[i];
}

void Heap::MaxHeapify(int i)
{
	int l = Left(i);
	int r = Right(i);
	int largest = i;
	int tmp;
	if (l < heap_size && arr[l] > arr[i])
	{
		largest = l;
	}
	else
	{
		largest = i;
	}
	if (r < heap_size && arr[r] > arr[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		tmp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tmp;
		MaxHeapify(largest);
	}
}

void Heap::MaxHeapify_iter(int i)
{
	while (1)
	{
		int l = Left(i);
		int r = Right(i);
		int largest = i;
		int tmp;
		if (l < heap_size && arr[l] > arr[i])
		{
			largest = l;
		}
		else
		{
			largest = i;
		}
		if (r < heap_size && arr[r] > arr[largest])
		{
			largest = r;
		}
		if (largest != i)
		{
			tmp = arr[i];
			arr[i] = arr[largest];
			arr[largest] = tmp;
			i = largest;
		}
		else
			break;
	}
}

void Heap::MinHeapify(int i)
{
	int l = Left(i);
	int r = Right(i);
	int smallest = i;
	int tmp;
	if (l < heap_size && arr[l] < arr[i])
	{
		smallest = l;
	}
	else
	{
		smallest = i;
	}
	if (r < heap_size && arr[r] < arr[smallest])
	{
		smallest = r;
	}
	if (smallest != i)
	{
		tmp = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = tmp;
		MinHeapify(smallest);
	}
}

void Heap::BuildNewHeap()
{
	for (int i = heap_size / 2 - 1; i >= 0; i--)
	{
		MaxHeapify(i);
	}
}

void Heap::HeapSort()
{
	BuildNewHeap();
	int tmp;
	int heap_size_tmp = heap_size;
	for (int i = heap_size - 1; i >= 1; i--)
	{
		tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		heap_size = heap_size - 1;
		MaxHeapify(0);
	}
	heap_size = heap_size_tmp;
}

bool Heap::ifmaxheap()
{
	for (int i = 1; i < heap_size; i++)
	{
		if (arr[Parent(i)] < arr[i])
			return false;
	}
	return true;
}

bool Heap::ifminheap()
{
	for (int i = 1; i < heap_size; i++)
	{
		if (arr[Parent(i)] > arr[i])
			return false;
	}
	return true;
}

int Heap::HeapMaximum()
{
	return arr[0];
}

int Heap::HeapExtractMax()
{
	if (heap_size < 1)
	{
		return -1;
		printf("Error: No element can be extracted.\n");
	}
	else
	{
		int maxvalue = arr[0];
		arr[0] = arr[heap_size-1];
		heap_size = heap_size - 1;
		MaxHeapify(0);
		return maxvalue;
	}
}

void Heap::HeapIncreaseKey(int i, int key)
{
	if (key < arr[i])
	{
		printf("Error: New key is smaller than current key.\n");
	}
	while (i > 0 && arr[Parent(i)] < key)
	{
		arr[i] = arr[Parent(i)];
		i = Parent(i);
	}
	arr[i] = key;
}

void Heap::MaxHeapInsert(int key)
{
	heap_size = heap_size + 1;
	arr[heap_size-1] = INT_MIN;
	HeapIncreaseKey(heap_size-1, key);
}

void Heap::MaxHeapDelete(int i)
{
	arr[i] = arr[heap_size - 1];
	heap_size = heap_size - 1;
	MaxHeapify(i);
	int key = arr[i];
	while (i > 0 && arr[Parent(i)] < key)
	{
		arr[i] = arr[Parent(i)];
		i = Parent(i);
	}
	arr[i] = key;
}

int Heap::HeapMinimum()
{
	return arr[0];
}

int Heap::HeapExtractMin()
{
	if (heap_size < 1)
	{
		return -1;
		printf("Error: No element can be extracted.\n");
	}
	else
	{
		int minvalue = arr[0];
		arr[0] = arr[heap_size - 1];
		heap_size = heap_size - 1;
		MinHeapify(0);
		return minvalue;
	}
}

void Heap::HeapDecreaseKey(int i, int key)
{
	if (key > arr[i])
	{
		printf("Error: New key is larger than current key.\n");
	}
	while (i > 0 && arr[Parent(i)] > key)
	{
		arr[i] = arr[Parent(i)];
		i = Parent(i);
	}
	arr[i] = key;
}

void Heap::MinHeapInsert(int key)
{
	heap_size = heap_size + 1;
	arr[heap_size - 1] = INT_MAX;
	HeapDecreaseKey(heap_size - 1, key);
}