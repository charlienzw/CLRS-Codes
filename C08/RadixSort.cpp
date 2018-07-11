#include <bits/stdc++.h>
using namespace std;

int Radixnumber(int num, int radix)
{
	return (num / (int)pow(10, radix)) % 10;
}

void CountingSort(vector<int> &A, int radix)
{
	vector<int> B(A.size());
	for (int j = 0; j < B.size(); j++)
		B[j] = A[j];
	vector<int> C(10, 0);
	for (int j = 0; j < B.size(); j++)
	{
		C[Radixnumber(B[j], radix)] = C[Radixnumber(B[j], radix)] + 1;
	}
	for (int i = 1; i < C.size(); i++)
		C[i] = C[i] + C[i - 1];
	for (int j = A.size() - 1; j >= 0; j--)
	{
		A[C[Radixnumber(B[j], radix)] - 1] = B[j];
		C[Radixnumber(B[j], radix)] = C[Radixnumber(B[j], radix)] - 1;
	}
}

void RadixSort(vector<int> &A,int d)
{
	for (int i = 0; i < d; i++)
	{
		CountingSort(A, i);
	}
}

int main()
{
	int N,d;
	while (scanf("%d", &N) != EOF)
	{
		vector<int> A(N);
		for (int i = 0; i<A.size(); i++)
			scanf("%d", &A[i]);
		scanf("%d", &d);
		RadixSort(A,d);
		for (int i = 0; i<A.size(); i++)
			printf("%d ", A[i]);
		printf("\n");
	}
	return 0;
}
