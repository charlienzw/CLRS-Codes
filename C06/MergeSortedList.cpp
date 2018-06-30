#include <bits/stdc++.h>
using namespace std;
#define maxsize 1000

class Heap
{
	public:
		void HeapFromVector(vector<int> V);
		void PrintHeap();
		int Parent(int i);
		int Left(int i);
		int Right(int i);
		Heap(int n);
		~Heap();
		int& operator[](int i);
		void MinHeapify(int i);
		void BuildNewMinHeap();
		void HeapSort();
		int heap_size;
		bool ifminheap();
		int HeapMinimum();
		int* HeapExtractMin();
		void HeapDecreaseKey(int i, int key,int index);
		void MinHeapInsert(int key,int index);
	private:
		int **arr;
};

Heap::Heap(int n)
{
	arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[2];
}

Heap::~Heap()
{
	delete[]arr;
}

void Heap::HeapFromVector(vector<int> V)
{
	heap_size = V.size();
	for (int i = 0; i < heap_size; i++)
	{
		arr[i][0] = V[i];
		arr[i][1] = i;
	}
}

void Heap::PrintHeap()
{
	for (int i = 0; i < heap_size; i++)
		printf("%d,%d ", arr[i][0],arr[i][1]);
	printf("\n");
}

int Heap::Parent(int i)
{
	return (i + 1) / 2 - 1;
}

int Heap::Left(int i)
{
	return (i + 1) * 2 - 1;
}

int Heap::Right(int i)
{
	return (i + 1) * 2;
}

int& Heap::operator[](int i)
{
	return arr[i][0];
}

void Heap::MinHeapify(int i)
{
	int l = Left(i);
	int r = Right(i);
	int smallest = i;
	int tmp;
	if (l < heap_size && arr[l][0] < arr[i][0])
	{
		smallest = l;
	}
	else
	{
		smallest = i;
	}
	if (r < heap_size && arr[r][0] < arr[smallest][0])
	{
		smallest = r;
	}
	if (smallest != i)
	{
		tmp = arr[i][0];
		arr[i][0] = arr[smallest][0];
		arr[smallest][0] = tmp;
		tmp = arr[i][1];
		arr[i][1] = arr[smallest][1];
		arr[smallest][1] = tmp;
		MinHeapify(smallest);
	}
}

void Heap::BuildNewMinHeap()
{
	for (int i = heap_size / 2 - 1; i >= 0; i--)
	{
		MinHeapify(i);
	}
}

bool Heap::ifminheap()
{
	for (int i = 1; i < heap_size; i++)
	{
		if (arr[Parent(i)][0] > arr[i][0])
			return false;
	}
	return true;
}

int Heap::HeapMinimum()
{
	return arr[0][0];
}

int* Heap::HeapExtractMin()
{
	static int minarray[2];
	if (heap_size < 1)
	{
		minarray[0] = -1;
		minarray[1] = -1;
		return minarray;
		printf("Error: No element can be extracted.\n");
	}
	else
	{
		int minvalue = arr[0][0];
		int minindex = arr[0][1];
		arr[0][0] = arr[heap_size - 1][0];
		arr[0][1] = arr[heap_size - 1][1];
		heap_size = heap_size - 1;
		MinHeapify(0);
		minarray[0] = minvalue;
		minarray[1] = minindex;
		return minarray;
	}
}

void Heap::HeapDecreaseKey(int i, int key,int index)
{
	if (key > arr[i][0])
	{
		printf("Error: New key is larger than current key.\n");
	}
	while (i > 0 && arr[Parent(i)][0] > key)
	{
		arr[i][0] = arr[Parent(i)][0];
		arr[i][1] = arr[Parent(i)][1];
		i = Parent(i);
	}
	arr[i][0] = key;
	arr[i][1] = index;
}

void Heap::MinHeapInsert(int key,int index)
{
	heap_size = heap_size + 1;
	arr[heap_size - 1][0] = INT_MAX;
	HeapDecreaseKey(heap_size - 1, key,index);
}

void MergeSortedList(vector<int> A, vector<vector<int>> I, vector<int> &result)
{
	int k = I.size();
	int n = A.size();
	int* returnarray;
	vector<int> V(k);
	for (int i = 0; i < k; i++)
	{
		V[i] = A[I[i][0]];
	}
	Heap H(maxsize);
	H.HeapFromVector(V);
	H.BuildNewMinHeap();
	vector<int> VI(k);
	for (int i = 0; i < k; i++)
	{
		VI[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		 returnarray=H.HeapExtractMin();
		 result[i] = returnarray[0];
		 VI[returnarray[1]] = VI[returnarray[1]] + 1;
		 int insertindex = I[returnarray[1]][0] + VI[returnarray[1]];
		 if (insertindex <= I[returnarray[1]][1])
		 {
			 H.MinHeapInsert(A[insertindex], returnarray[1]);
		 }
	}
}

int main()
{
	int n,k;
	printf("Input the total number of elements:\n");
	scanf("%d", &n);
	vector<int> A(n);
	printf("Input the elements:\n");
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	printf("Input the number of sorted lists:\n");
	scanf("%d", &k);
	vector<vector<int>> I(k);
	for (int i = 0; i < k; i++)
	{
		I[i].resize(2);
		printf("Input the start and end index of No.%d sorted list:\n",i);
		scanf("%d %d", &I[i][0], &I[i][1]);
	}
	vector<int> result(n);
	MergeSortedList(A, I, result);
	printf("Sorted list:\n");
	for (int i = 0; i < n; i++)
		printf("%d ", result[i]);
	printf("\n");
	system("pause");
	return 0;
}