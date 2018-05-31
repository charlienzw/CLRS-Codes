#include <bits/stdc++.h>
using namespace std;

void Merge_NoSentinel(vector<int> &A, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<int> L(n1);
	vector<int> R(n2);
	int i, j;
	for (i = 0; i < n1; i++)
		L[i] = A[p + i];
	for (j = 0; j < n2; j++)
		R[j] = A[q + j + 1];
	i = 0;
	j = 0;
	int k = p;
	while (i < n1&&j < n2)
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
		k = k + 1;
	}
	if (i == n1)
	{
		while (k <= r)
		{
			A[k] = R[j];
			k = k + 1;
			j = j + 1;
		}
	}
	else
	{
		while (k <= r)
		{
			A[k] = L[i];
			k = k + 1;
			i = i + 1;
		}
	}
}

void MergeSort_NoSentinel(vector<int> &A, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		MergeSort_NoSentinel(A, p, q);
		MergeSort_NoSentinel(A, q + 1, r);
		Merge_NoSentinel(A, p, q, r);
	}
}

int main()
{
	int N;
	int tmp;
	while (scanf("%d", &N) != EOF)
	{
		vector<int> A(N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &A[i]);
		}
		MergeSort_NoSentinel(A, 0, A.size() - 1);
		for (int i = 0; i<A.size(); i++)
			printf("%d ", A[i]);
		printf("\n");
	}
	return 0;
}
