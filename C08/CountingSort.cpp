#include <bits/stdc++.h>
using namespace std;

void CountingSort(vector<int> A,vector<int> &B)
{
	int maxvalue = 0;
	for (int j = 0; j < A.size(); j++)
	{
		if (A[j] > maxvalue)
			maxvalue = A[j];
	}
	vector<int> C(maxvalue+1,0);
	for (int j = 0; j < A.size(); j++)
		C[A[j]] = C[A[j]] + 1;
	for (int i = 1; i < C.size(); i++)
		C[i] = C[i] + C[i - 1];
	for (int j = A.size() - 1; j >= 0; j--)
	{
		B[C[A[j]]-1] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}
}

int main()
{
	int N;
	while (scanf("%d", &N) != EOF)
	{
		vector<int> A(N);
		vector<int> B(N);
		for (int i = 0; i<A.size(); i++)
			scanf("%d", &A[i]);
		CountingSort(A,B);
		for (int i = 0; i<B.size(); i++)
			printf("%d ", B[i]);
		printf("\n");
	}
	return 0;
}
