#include <bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &A)
{
	int tmp;
	for (int i = 0; i < A.size() - 1; i++)
	{
		for (int j = A.size() - 1; j >= i + 1; j--)
		{
			if (A[j] < A[j - 1])
			{
				tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
			}
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
		BubbleSort(A);
		for (int i = 0; i<A.size(); i++)
			printf("%d ", A[i]);
		printf("\n");
	}
	return 0;
}
