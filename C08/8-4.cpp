#include <bits/stdc++.h>
using namespace std;

int Partition(vector<vector<int>> &Aplus, vector<vector<int>> &Bplus, int p, int r)
{
	vector<int> tmp;
	int x = Bplus[r][0];
	int y = Aplus[r][0];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
	{
		if (Aplus[j][0] <= x)
		{
			i = i + 1;;
			tmp = Aplus[j];
			Aplus[j] = Aplus[i];
			Aplus[i] = tmp;
		}
	}
	tmp = Aplus[i + 1];
	Aplus[i + 1] = Aplus[r];
	Aplus[r] = tmp;
	i = p - 1;
	for (int j = p; j <= r - 1; j++)
	{
		if (Bplus[j][0] <= y)
		{
			i = i + 1;;
			tmp = Bplus[j];
			Bplus[j] = Bplus[i];
			Bplus[i] = tmp;
		}
	}
	tmp = Bplus[i + 1];
	Bplus[i + 1] = Bplus[r];
	Bplus[r] = tmp;
	return i + 1;
}

int RandomizedPartition(vector<vector<int>> &Aplus, vector<vector<int>> &Bplus, int p,int r)
{
	int i = p + rand() % (r - p + 1);
	int j;
	for (j = p; j <=r; j++)
	{
		if (Bplus[j][0] == Aplus[i][0])
			break;
	}
	vector<int> tmp;
	tmp = Aplus[r];
	Aplus[r] = Aplus[i];
	Aplus[i] = tmp;
	tmp = Bplus[r];
	Bplus[r] = Bplus[j];
	Bplus[j] = tmp;
	return Partition(Bplus, Aplus, p, r);
}

void QuickSort(vector<vector<int>> &Aplus, vector<vector<int>> &Bplus,int p,int r)
{
	if (p < r)
	{
		int q=RandomizedPartition(Aplus, Bplus, p,r);
		QuickSort(Aplus, Bplus, p,q-1);
		QuickSort(Aplus, Bplus, q+1,r);
	}
}

void QuickGetPair(vector<int> A, vector<int> B, vector<int> &pair)
{
	int n = A.size();
	vector<vector<int>> Aplus(A.size());
	vector<vector<int>> Bplus(B.size());
	for (int i = 0; i < n; i++)
	{
		Aplus[i].resize(2);
		Bplus[i].resize(2);
		Aplus[i][0] = A[i];
		Bplus[i][0] = B[i];
		Aplus[i][1] = i;
		Bplus[i][1] = i;
	}
	QuickSort(Aplus, Bplus, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		pair[Aplus[i][1]] = Bplus[i][1];
	}
}

void GetPair(vector<int> A, vector<int> B, vector<int> &pair)
{
	for (int i=0;i < A.size(); i++)
	{
		for (int j=0; j < B.size(); j++)
		{
			if (A[i] == B[j])
			{
				pair[i]=j;
				break;
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
		vector<int> B(N);
		for (int i = 0; i<A.size(); i++)
			scanf("%d", &A[i]);
		for (int i = 0; i<B.size(); i++)
			scanf("%d", &B[i]);
		vector<int> pair(N);
		GetPair(A, B, pair);
		for (int i = 0; i < pair.size(); i++)
			printf("%d ", pair[i]);
		printf("\n");
		QuickGetPair(A, B ,pair);
		for (int i = 0; i < pair.size(); i++)
			printf("%d ", pair[i]);
		printf("\n");
	}
	return 0;
}
