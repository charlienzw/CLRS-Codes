#include <bits/stdc++.h>
using namespace std;

void RandomizeInPlace(vector<int> &A)
{
	int n = A.size();
	int ri, tmp;
	ri = rand() % n;
	tmp = A[ri];
	A[ri] = A[0];
	A[0] = tmp;
	for (int i = 1; i < n; i++)
	{
		ri = i+rand() % (n - i);
		tmp = A[ri];
		A[ri] = A[i];
		A[i] = tmp;
	}
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		vector<int> A(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &A[i]);
		RandomizeInPlace(A);
		for (int i = 0; i < n; i++)
			printf("%d ", A[i]);
		printf("\n");
	}
	return 0;
}