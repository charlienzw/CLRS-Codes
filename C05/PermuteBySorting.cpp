#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> A, vector<int> B)
{
	if (A[1]<B[1])
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PermuteBySorting(vector<int> &A)
{
	int n = A.size();
	vector<vector<int>> AP(n);
	for (int i = 0; i < n; i++)
	{
		AP[i].resize(2);
		AP[i][0] = A[i];
		AP[i][1] = rand() % (n*n*n);
	}
	sort(AP.begin(), AP.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		A[i] = AP[i][0];
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
		PermuteBySorting(A);
		for (int i = 0; i < n; i++)
			printf("%d ", A[i]);
		printf("\n");
	}
	return 0;
}