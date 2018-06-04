#include <bits/stdc++.h>
using namespace std;

int Invertions(vector<int> &A, int p, int r) //theta(nlogn)
{
	if (p == r)
	{
		return 0;
	}
	else
	{
		int q = (p + r) / 2;
		int invertions_num = 0;;
		int invertions_left = Invertions(A, p, q);
		int	invertions_right = Invertions(A, q + 1, r);
		int n1 = q - p + 1;
		int n2 = r - q;
		vector<int> L(n1 + 1);
		vector<int> R(n2 + 1);
		int i, j;
		for (i = 0; i < n1; i++)
			L[i] = A[p + i];
		for (j = 0; j < n2; j++)
			R[j] = A[q + j + 1];
		L[n1] = INT_MAX;
		R[n2] = INT_MAX;
		i = 0;
		j = 0;
		int tmp = 0;
		for (int k = p; k <= r; k++)
		{
			if (L[i] <= R[j])
			{
				A[k] = L[i];
				i = i + 1;
				invertions_num = invertions_num + tmp;
			}
			else
			{
				A[k] = R[j];
				j = j + 1;
				tmp = tmp + 1;
			}
		}
		return invertions_num + invertions_left + invertions_right; 
	}
}

int main()
{
	int N,num;
	while (scanf("%d", &N) != EOF)
	{
		vector<int> A(N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &A[i]);
		}
		num = Invertions(A,0,N-1);
		printf("%d\n", num);
	}
	return 0;
}
