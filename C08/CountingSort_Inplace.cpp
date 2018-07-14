#include <bits/stdc++.h>
using namespace std;

void CountingSort_Inplace(vector<int> &A)
{
	int maxvalue = 0;
	for (int j = 0; j < A.size(); j++)
	{
		if (A[j] > maxvalue)
			maxvalue = A[j];
	}
	vector<int> C(maxvalue + 1, 0);
	int tmp;
	for (int j = 0; j < A.size(); j++)
		C[A[j]] = C[A[j]] + 1;
	int k = 0;
	for (int i = 0; i < C.size(); i++)
	{
		for (int j = 0; j < C[i]; j++)
		{
			A[k] = i;
			k = k + 1;
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
		CountingSort_Inplace(A);
		for (int i = 0; i<A.size(); i++)
			printf("%d ", A[i]);
		printf("\n");
	}
	return 0;
}
