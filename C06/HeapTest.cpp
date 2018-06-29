#include <bits/stdc++.h>
#include "Heap.h"
using namespace std;
#define maxsize 1000

int main()
{
	Heap A(maxsize);
	int heap_size, index,instruction,key;
	printf("Please input the size of array(<=1000):\n");
	scanf("%d", &heap_size);
	printf("Please input the elements of the array:\n");
	A.HeapInit(heap_size);
	printf("Functions:\n");
	printf("1. Print this heap.\n");
	printf("2. Check if the heap is a max-heap.\n");
	printf("3. Check if the heap is a min-heap.\n");
	printf("4. Maxheapify the heap with recursion.\n");
	printf("5. Maxheapify the heap with iteration.\n");
	printf("6. Minheapify the heap.\n");
	printf("7. Build a max-heap.\n");
	printf("8. HeapSort.\n");
	printf("9. Get the maximum of the heap.\n");
	printf("10. Extract the maximum of the heap.\n");
	printf("11. Increase the key of the heap.\n");
	printf("12. Insert one element at the end of the max-heap.\n");
	printf("13. Get the minimum of the heap.\n");
	printf("14. Extract the minimum of the heap.\n");
	printf("15. Decrease the key of the heap.\n");
	printf("16. Insert one element at the end of the min-heap.\n");
	printf("17. Delete one element of the max-heap.\n");
	printf("0. Exit.\n");
	while (1)
	{

		scanf("%d", &instruction);
		switch (instruction) {
			case 1:
				A.PrintHeap();
				break;
			case 2:
				if (A.ifmaxheap() == true)
				{
					printf("This is a max-heap.\n");
				}
				else
				{
					printf("This is not a max-heap.\n");
				}
				break;
			case 3:
				if (A.ifminheap() == true)
				{
					printf("This is a min-heap.\n");
				}
				else
				{
					printf("This is not a min-heap.\n");
				}
				break; 
			case 4:
				printf("Please Input the maxheapify-index(>=0&&<heap_size)\n");
				scanf("%d", &index);
				A.MaxHeapify(index);
				break;
			case 5:
				printf("Please Input the maxheapify-index(>=0&&<heap_size)\n");
				scanf("%d", &index);
				A.MaxHeapify_iter(index);
				break;
			case 6:
				printf("Please Input the minheapify-index(>=0&&<heap_size)\n");
				scanf("%d", &index);
				A.MinHeapify(index);
				break;
			case 7:
				A.BuildNewHeap();
				break;
			case 8:
				A.HeapSort();
				break;
			case 9:
				printf("%d\n", A.HeapMaximum());
				break;
			case 10:
				printf("%d has been extracted.\n", A.HeapExtractMax());
				break;
			case 11:
				printf("Input the index to be increased to:\n");
				scanf("%d", &index);
				printf("Input the key to be increased:\n");
				scanf("%d", &key);
				A.HeapIncreaseKey(index,key);
				break;
			case 12:
				printf("Input the key to be inserted:\n");
				scanf("%d", &key);
				A.MaxHeapInsert(key);
				break;
			case 13:
				printf("%d\n", A.HeapMinimum());
				break;
			case 14:
				printf("%d has been extracted.\n", A.HeapExtractMin());
				break;
			case 15:
				printf("Input the index to be increased to:\n");
				scanf("%d", &index);
				printf("Input the key to be increased:\n");
				scanf("%d", &key);
				A.HeapDecreaseKey(index, key);
				break;
			case 16:
				printf("Input the key to be inserted:\n");
				scanf("%d", &key);
				A.MinHeapInsert(key);
				break;
			case 17:
				printf("Input the index to be deleted:\n");
				scanf("%d", &index);
				A.MaxHeapDelete(index);
				break;
			case 0:
				return 0;
			default: 
				printf("Invalid Instruction.\n");
		}
	}
	return 0;
}



