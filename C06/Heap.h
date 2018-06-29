#pragma once

class Heap
{
	public:
		void HeapInit(int N);
		void PrintHeap();
		int Parent(int i);
		int Left(int i);
		int Right(int i);
		Heap(int n);
		~Heap();
		int& operator[](int i);
		void MaxHeapify(int i);
		void MaxHeapify_iter(int i);
		void MinHeapify(int i);
		void BuildNewHeap();
		void HeapSort();
		int heap_size;
		bool ifmaxheap();
		bool ifminheap();
		int HeapMaximum();
		int HeapExtractMax();
		void HeapIncreaseKey(int i, int key);
		void MaxHeapInsert(int key);
		void MaxHeapDelete(int i);
		int HeapMinimum();
		int HeapExtractMin();
		void HeapDecreaseKey(int i, int key);
		void MinHeapInsert(int key);
	private:
		int *arr;
};

