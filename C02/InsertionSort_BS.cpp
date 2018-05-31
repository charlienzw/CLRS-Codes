#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int>A, int lowinit, int highinit, int x)
{
	int low = lowinit;
	int high = highinit;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (x >= A[mid] && x < A[mid + 1])
			return mid;
		else if (x < A[mid])
			high = mid - 1;
		else low = mid + 1;
	}
	if (high ==lowinit-1)
		return lowinit;
	if (low == highinit+1)
		return highinit+1;
}

void InsertionSort_BS(vector<int> &A)
{
	for (int j = 1; j<A.size(); j++)
	{
		int tmp;
		int key = A[j];
		int pos = BinarySearch(A, 0, j - 1,key);
		for (int i=j-1;i>=pos;i--)
		{
			tmp = A[i + 1];
			A[i+1]=A[i];
			A[i] = tmp;
		}
	}
}

int main()
{
	int N;
	while (scanf("%d", &N) != EOF)
	{
		vector<int> A(N);
		for (int i = 0; i<A.size(); i++)
			scanf("%d", &A[i]);
		InsertionSort_BS(A);
		for (int i = 0; i<A.size(); i++)
			printf("%d ", A[i]);
		printf("\n");
	}
	return 0;
}
