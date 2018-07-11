#include <bits/stdc++.h>
using namespace std;

int CountInterval(vector<int> A, int a,int b)
{
	int maxvalue = 0;
	for (int j = 0; j < A.size(); j++)
	{
		if (A[j] > maxvalue)
			maxvalue = A[j];
	}
	vector<int> C(maxvalue + 1, 0);
	for (int j = 0; j < A.size(); j++)
		C[A[j]] = C[A[j]] + 1;
	for (int i = 1; i < C.size(); i++)
		C[i] = C[i] + C[i - 1];
	if (a == 0)
		return C[b];
	else
		return C[b] - C[a - 1];
}

int main()
{
	int N,a,b;
	while (scanf("%d", &N) != EOF)
	{
		vector<int> A(N);
		for (int i = 0; i<A.size(); i++)
			scanf("%d", &A[i]);
		scanf("%d %d", &a, &b);
		int result=CountInterval(A, a, b);
		printf("%d\n",result);
	}
	return 0;
}
