#include <bits/stdc++.h>
using namespace std;

int Partition(vector<int> &A, int p, int r)
{
	int tmp;
	int x = A[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
	{
		if (A[j] <= x)
		{
			i = i + 1;;
			tmp = A[j];
			A[j] = A[i];
			A[i] = tmp;
		}
	}
	tmp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = tmp;
	return i + 1;
}

void QuickSort(vector<int> &A, int p, int r)
{
	if (p < r)
	{
		int q = Partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}

int RandomizedPartition(vector<int>&A, int p, int r)
{
	int i = p + rand() % (r - p + 1);
	int tmp;
	tmp = A[r];
	A[r] = A[i];
	A[i] = tmp;
	return Partition(A, p, r);
}

void RandomizedQuickSort(vector<int> &A,int p,int r)
{
	if (p < r)
	{
		int q = RandomizedPartition(A, p, r);
		RandomizedQuickSort(A, p, q - 1);
		RandomizedQuickSort(A, q + 1, r);
	}
}

int HoarePartition(vector<int> &A, int p, int r)
{
	int x = A[p];
	int i = p - 1;
	int j = r + 1;
	int tmp;
	while (true)
	{
		while (1)
		{
			j = j - 1;
			if (A[j] <= x)
				break;
		}
		while (1)
		{
			i = i + 1;
			if (A[i] >= x)
				break;
		}
		if (i < j)
		{
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
		else
		{
			return j;
		}
	}
}

void HoareQuickSort(vector<int> &A, int p, int r)
{
	if (p < r)
	{
		int q = HoarePartition(A, p, r);
		HoareQuickSort(A, p, q);
		HoareQuickSort(A, q + 1, r);
	}
}

void Partition3(vector<int> &A, int p, int r, int &q, int &t)
{
	int tmp;
	int x = A[r];
	int i = p - 1, j = p - 1;
	for (int k = p; k <= r - 1; k++)
	{
		if (A[k] < x)
		{     
			i = i + 1;
			j = j + 1;
			tmp = A[k];
			A[k] = A[i];
			A[i] = tmp;
			tmp = A[i];
			A[i] = A[j];
			A[j ] = tmp;
		}
		if (A[k] == x)
		{
			i = i + 1;
			tmp = A[k];
			A[k] = A[i];
			A[i] = tmp;
		}
	}
	tmp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = tmp;
	q = j + 1;
	t = i;
}

void RandomizedPartition3(vector<int> &A, int p, int r,int &q,int &t)
{
	int i = p + rand() % (r - p + 1);
	int tmp;
	tmp = A[r];
	A[r] = A[i];
	A[i] = tmp;
	return Partition3(A, p, r, q, t);
}

void QuickSort3(vector<int> &A, int p, int r)
{
	if (p < r)
	{
		int q, t;
		RandomizedPartition3(A, p, r, q, t);
		QuickSort3(A, p, q - 1);
		QuickSort3(A, t + 1, r);
	}
}

void TailRecursionQuickSort(vector<int> &A, int p, int r)
{
	while (p < r)
	{
		int q = RandomizedPartition(A, p, r);
		TailRecursionQuickSort(A, p, q - 1);
		p = q + 1;
	}
}

void TailRecursionQuickSort3(vector<int> &A, int p, int r)
{
	int q, t;
	while (p < r)
	{
		RandomizedPartition3(A, p, r, q, t);
		if (q - p < r - t)
		{
			TailRecursionQuickSort3(A, p, q-1);
			p = t + 1;
		}
		else
		{
			TailRecursionQuickSort3(A, t + 1, r);
			r = q - 1;
		}
	}
}

int main()
{
	int N,instruction;
	while (scanf("%d", &N) != EOF)
	{
		vector<int> A(N);
		for (int i = 0; i<A.size(); i++)
			scanf("%d", &A[i]);
		printf("1. QuickSort.\n");
		printf("2. RandomizedQuickSort.\n");
		printf("3. HoareQuickSort.\n");
		printf("4. QuickSort3.\n");
		printf("5. TailRecursionQuickSort.\n");
		printf("6. TailRecursionQuickSort3.\n");
		scanf("%d", &instruction);
		switch (instruction)
		{
		case 1:
			QuickSort(A, 0, N - 1);
			for (int i = 0; i<A.size(); i++)
				printf("%d ", A[i]);
			printf("\n");
			break;
		case 2:
			RandomizedQuickSort(A, 0, N - 1);
			for (int i = 0; i<A.size(); i++)
				printf("%d ", A[i]);
			printf("\n");
			break;
		case 3:
			HoareQuickSort(A, 0, N - 1);
			for (int i = 0; i<A.size(); i++)
				printf("%d ", A[i]);
			printf("\n");
			break;
		case 4:
			QuickSort3(A, 0, N - 1);
			for (int i = 0; i<A.size(); i++)
				printf("%d ", A[i]);
			printf("\n");
			break;
		case 5:
			TailRecursionQuickSort(A, 0, N - 1);
			for (int i = 0; i<A.size(); i++)
				printf("%d ", A[i]);
			printf("\n");
			break;
		case 6:
			TailRecursionQuickSort3(A, 0, N - 1);
			for (int i = 0; i<A.size(); i++)
				printf("%d ", A[i]);
			printf("\n");
			break;
		default:
			printf("Invalid instruction.\n");
		}
	}
	return 0;
}
