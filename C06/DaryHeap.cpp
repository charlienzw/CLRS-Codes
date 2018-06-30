#include <bits/stdc++.h>
using namespace std;
#define maxsize 1000

class DaryHeap{
public:
	DaryHeap(int n,int D);
	void Init(int N);
	void PrintHeap();
	int Parent(int i);
	int Child(int i, int d);
	void MaxHeapify(int i);
	int ExtractMax();
	void Insert(int key);
	void IncreaseKey(int i, int k);
private:
	int *arr;
	int Dvalue;
	int heap_size;
};

DaryHeap::DaryHeap(int n, int D)
{
	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}
	Dvalue = D;
}

void DaryHeap::Init(int N)
{
	heap_size = N;
	for (int i = 0; i < heap_size; i++)
	{
		scanf("%d", &arr[i]);
	}
}

int DaryHeap::Parent(int i)
{
	return (i + Dvalue - 1) / Dvalue - 1;
}

int DaryHeap::Child(int i, int d)
{
	return (i + 1)*Dvalue+d - Dvalue + 1;
}

void DaryHeap::PrintHeap()
{
	for (int i = 0; i < heap_size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void DaryHeap::MaxHeapify(int i)
{
	vector<int> c(Dvalue);
	for (int d = 0; d < Dvalue; d++)
	{
		c[d] = Child(i, d);
	}
	int largest = i;
	int tmp;
	for (int d = 0; d < Dvalue; d++)
	{
		if (c[d]<heap_size&&arr[c[d]]>arr[i])
		{
			largest = c[d];
		}
	}
	if (largest != i)
	{
		tmp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tmp;
		MaxHeapify(largest);
	}
}

int DaryHeap::ExtractMax()
{
	if (heap_size < 1)
	{
		return -1;
		printf("Error: No element can be extracted.\n");
	}
	else
	{
		int maxvalue = arr[0];
		arr[0] = arr[heap_size - 1];
		heap_size = heap_size - 1;
		MaxHeapify(0);
		return maxvalue;
	}
}

void DaryHeap::Insert(int key)
{
	heap_size = heap_size + 1;
	arr[heap_size - 1] = INT_MIN;
	IncreaseKey(heap_size - 1, key);
}

void DaryHeap::IncreaseKey(int i, int key)
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

int main()
{
	int D;
	printf("Please input the D parameter:\n");
	scanf("%d", &D);
	DaryHeap A(maxsize,D);
	int heap_size, index, instruction, key;
	printf("Please input the size of array(<=1000):\n");
	scanf("%d", &heap_size);
	printf("Please input the BuildNewMaxHeap of the array:\n");
	A.Init(heap_size);
	printf("Functions:\n");
	printf("1. Print this heap.\n");
	printf("2. Extract the max element of the heap.\n");
	printf("3. Insert a new element to the heap.\n");
	printf("4. Increase one element's key of the heap.\n");
	printf("0. Exit.\n");
	while (1)
	{
		scanf("%d", &instruction);
		switch (instruction) {
		case 1:
			A.PrintHeap();
			break;
		case 2:
			key=A.ExtractMax();
			printf("%d has been extracted.\n", key);
			break;
		case 3:
			printf("Input the element to be inserted to the end:\n");
			scanf("%d", &key);
			A.Insert(key);
			break;
		case 4:
			printf("Please Input the key to be increased to:\n");
			scanf("%d", &key);
			printf("Please input the index to be increased;\n");
			scanf("%d", &index);
			A.IncreaseKey(index,key);
			break;
		case 0:
			return 0;
		default:
			printf("Invalid Instruction.\n");
		}
	}
	return 0;
}

