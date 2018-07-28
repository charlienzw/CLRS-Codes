#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
	Queue(int N);
	~Queue();
	void Print();
	bool QueueEmpty();
	void Enqueue(int x);
	int Dequeue();
private:
	int* arr;
	int tail = 0;
	int head = 0;
	int maxsize;
};

Queue::Queue(int N)
{
	arr = new int[N];
	maxsize = N;
}

Queue::~Queue()
{
	delete[] arr;
}

void Queue::Print()
{
	if (head < tail)
	{
		for (int i = head; i < tail; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	else if(head>tail)
	{
		for(int i=head;i<maxsize;i++)
			printf("%d ", arr[i]);
		for(int i=0;i<tail;i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
}

bool Queue::QueueEmpty()
{
	if (head==tail) return true;
	else return false;
}

void Queue::Enqueue(int x)
{
	if (tail - head < maxsize)
	{
		arr[tail] = x;
		if (tail == maxsize - 1)
		{
			tail = 0;
		}
		else
		{
			tail = tail + 1;
		}
	}
	else
	{
		printf("Error: overflow\n");
		system("pause");
		exit(1);
	}
}

int Queue::Dequeue()
{
	if (QueueEmpty())
	{
		printf("Error: underflow\n");
		system("pause");
		exit(1);
	}
	else
	{
		int x = arr[head];
		if (head == maxsize - 1)
		{
			head = 0;
		}
		else
		{
			head = head + 1;
		}
		return x;
	}
}

int main()
{
	int N;
	printf("Input the maxsize of queue:\n");
	scanf("%d", &N);
	Queue A(N);
	int instruction, key;
	printf("1. Print the queue.\n");
	printf("2. Judge if the queue is empty.\n");
	printf("3. Enqueue one element to the queue.\n");
	printf("4. Dequeue one element on the head of the queue.\n");
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
			if (A.QueueEmpty())
				printf("The queue is empty.\n");
			else
				printf("The queue is not empty.\n");
			break;
		case 3:
			printf("Input the element to be enqueued:\n");
			scanf("%d", &key);
			A.Enqueue(key);
			break;
		case 4:
			printf("The element to dequeue is %d.\n", A.Dequeue());
			break;
		case 5:
			return 0;
		default:
			printf("Invalid instruction.\n");
		}
	}
	return 0;
}