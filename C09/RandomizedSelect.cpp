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

int RandomizedPartition(vector<int>&A, int p, int r)
{
	int i = p + rand() % (r - p + 1);
	int tmp;
	tmp = A[r];
	A[r] = A[i];
	A[i] = tmp;
	return Partition(A, p, r);
}

int RandomizedSelect(vector<int> A, int p,int r,int i)
{
	if (p == r)
		return A[p];
	int q = RandomizedPartition(A, p, r);
	int k = q - p + 1;
	if (i == k)
	{
		return A[q];
	}
	else if (i < k)
	{
		return RandomizedSelect(A, p, q - 1, i);
	}
	else
	{
		return RandomizedSelect(A, q + 1, r, i - k);
	}
}

int RandomizedSelect_iter(vector<int> A, int i)
{
	int p = 0;
	int r = A.size() - 1;
	while (1)
	{
		if (p == r)
			return A[p];
		int q = RandomizedPartition(A, p, r);
		int k = q - p + 1;
		if (i == k)
		{
			return A[q];
		}
		else if (i < k)
		{
			r = q - 1;
		}
		else
		{
			p = q + 1;
			i = i - k;
		}
	}
}

int main()
{
	int N,i,result,result_iter;
	while (scanf("%d", &N) != EOF)
	{
		vector<int> A(N);
		for (int j = 0; j < N; j++)
			scanf("%d", &A[j]);
		scanf("%d", &i);
		result=RandomizedSelect(A, 0, A.size()-1, i);
		result_iter = RandomizedSelect_iter(A,i);
		printf("%d\n", result);
		printf("%d\n", result_iter);
	}
	return 0;
}