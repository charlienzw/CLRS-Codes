#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> A, int x)
{
	// A should be a sorted nondecreasing sequence.
	int low = 0;
	int high = A.size() - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (A[mid] == x)
			return mid;
		else if (A[mid] < x)
			low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

int main()
{
	int N,x,i;
	while (scanf("%d", &N) != EOF)
	{
		vector<int> A(N);
		for (int i = 0; i<A.size(); i++)
			scanf("%d", &A[i]);
		scanf("%d", &x);
		i=BinarySearch(A,x);
		printf("%d\n",i);
	}
	return 0;
}
