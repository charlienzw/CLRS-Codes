#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> A, int x)
{
	// A should be a sorted nondecreasing sequence.
	int low = 0;
	int high = A.size() - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (A[mid] == x)
			return mid;
		else if (A[mid] < x)
			low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

void Merge(vector<int> &A, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<int> L(n1 + 1);
	vector<int> R(n2 + 1);
	int i, j;
	for (i = 0; i < n1; i++)
		L[i] = A[p + i];
	for (j = 0; j < n2; j++)
		R[j] = A[q + j + 1];
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	i = 0;
	j = 0;
	for (int k = p; k <= r; k++)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i = i + 1;
		}
		else
		{
			A[k] = R[j];
			j = j + 1;
		}
	}
}

void MergeSort(vector<int> &A, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}

bool TwoSum(vector<int> A, int x)
{
	int j;
	MergeSort(A, 0, A.size() - 1);
	for (int i = 0; i < A.size(); i++)
	{
		j = BinarySearch(A, x - A[i]);
		if (i != j && j != -1)
			return true;
	}
	return false;
}

int main()
{
	int N,x;
	while (scanf("%d", &N) != EOF)
	{
		vector<int> A(N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &A[i]);
		}
		scanf("%d", &x);
		printf("%d",TwoSum(A, x));
		printf("\n");
	}
	return 0;
}
