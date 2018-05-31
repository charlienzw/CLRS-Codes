#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int> &A, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<int> L(n1 + 1);
	vector<int> R(n2 + 1);
	int i,j;
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
		MergeSort(A, q+1, r);
		Merge(A, p, q, r);
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
		MergeSort(A, 0, A.size() - 1);
		for (int i = 0; i<A.size(); i++)
			printf("%d ", A[i]);
		printf("\n");
	}
	return 0;
}
