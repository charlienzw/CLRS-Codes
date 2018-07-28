#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
	Stack(int N);
	~Stack();
	void Print();
	bool StackEmpty();
	void Push(int x);
	int Pop();
private:
	int* arr;
	int top = -1;
	int maxsize;
};

Stack::Stack(int N)
{
	arr = new int[N];
	maxsize = N;
}

Stack::~Stack()
{
	delete[] arr;
}

void Stack::Print()
{
	for (int i = 0; i <= top; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

bool Stack::StackEmpty()
{
	if (top == -1) return true;
	else return false;
}

void Stack::Push(int x)
{
	if (top == maxsize - 1)
	{
		printf("Error:overflow\n");
		system("pause");
		exit(1);
	}
	else
	{
		top = top + 1;
		arr[top] = x;
	}
}

int Stack::Pop()
{
	if (StackEmpty())
	{
		printf("Error: underflow\n");
		system("pause");
		exit(1);
	}
	else
	{
		top = top - 1;
		return arr[top + 1];
	}
}

int main()
{
	printf("Input the maxsize of stack.\n");
	int N;
	scanf("%d", &N);
	Stack A(N);
	int instruction,key;
	printf("1. Print the stack.\n");
	printf("2. Judge if the stack is empty.\n");
	printf("3. Push one element to the stack.\n");
	printf("4. Pop one element on the top of the stack.\n");
	printf("5. Exit.\n");
	while (1)
	{
		scanf("%d", &instruction);
		switch (instruction)
		{
		case 1:
			A.Print();
			break;
		case 2:
			if (A.StackEmpty())
				printf("The stack is empty.\n");
			else
				printf("The stack is not empty.\n");
			break;
		case 3:
			printf("Input the element to be pushed:\n");
			scanf("%d", &key);
			A.Push(key);
			break;
		case 4:
			printf("The element to pop is %d.\n", A.Pop());
			break;
		case 5:
			return 0;
		default:
			printf("Invalid instruction.\n");
		}
	}
	return 0;
}