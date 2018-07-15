#include <bits/stdc++.h>
using namespace std;

int Partition(vector<int> &A, int p, int r,int x)
{
	int selectj = p;
	for (int j = p; j <= r; j++)
	{
		if (A[j] == x)
		{
			selectj = j;
			break;
		}
	}
	int tmp;
	tmp = A[selectj];
	A[selectj] = A[r];
	A[r] = tmp;
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

void InsertionSort(vector<int> &A,int p,int r)
{
	for (int j = p+1; j<=r; j++)
	{
		int key = A[j];
		int i = j - 1;
		while (i >= p && A[i]>key)
		{
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = key;
	}
}

int GetMedian(vector<int> A, int p, int r)
{
	InsertionSort(A,p,r);
	return A[p + (r - p) / 2];
}

int LinearSelect(vector<int> A, int p,int r,int i)
{
	if (r - p + 1 == 1) return A[p];
	int splitsize = 5;
	vector<int> medianarray;
	medianarray.resize(0);
	for (int j = p; j <=r; j = j + splitsize)
	{
		if (j + splitsize <= r)
			medianarray.push_back(GetMedian(A, j, j + splitsize-1));
		else
			medianarray.push_back(GetMedian(A, j, r));
	}
	int medianofmedian = LinearSelect(medianarray, 0, medianarray.size() - 1,(medianarray.size()-1)/2);
	int k=Partition(A, p, r, medianofmedian);
	if (i == k-p) return medianofmedian;
	else if (i < k-p) return LinearSelect(A, p, k - 1, i);
	else return LinearSelect(A, k + 1, r, i - k);
}

int main()
{
	int N,i,result;
	while (scanf("%d", &N) != EOF)
	{
		vector<int> A(N);
		for (int j = 0; j < A.size(); j++)
			scanf("%d", &A[j]);
		scanf("%d", &i);
		result=LinearSelect(A,0,A.size()-1,i-1);
		printf("%d\n", result);
	}
	return 0;
}