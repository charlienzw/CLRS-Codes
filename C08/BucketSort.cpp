#include <bits/stdc++.h>
using namespace std;

void InsertionSort(vector<double> &A)
{
	for (int j = 1; j<A.size(); j++)
	{
		double key = A[j];
		int i = j - 1;
		while (i >= 0 && A[i]>key)
		{
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = key;
	}
}

void BucketSort(vector<double> &A)
{
	int n = A.size();
	vector<vector<double>> B(n);
	for (int i = 0; i < n; i++)
	{
		B[i].resize(0);
	}
	for(int i=0;i<n;i++)
	{
		B[int(n*A[i])].push_back(A[i]);
	}
	for (int i = 0; i < n; i++)
		InsertionSort(B[i]);
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < B[i].size(); j++)
		{
			A[k] = B[i][j];
			k = k + 1;
		}
	}

}

int main()
{
	int N;
	while (scanf("%d", &N) != EOF)
	{
		vector<double> A(N);
		for (int i = 0; i<A.size(); i++)
			scanf("%lf", &A[i]);
		BucketSort(A);
		for (int i = 0; i<A.size(); i++)
			printf("%lf ", A[i]);
		printf("\n");
	}
	return 0;
}
