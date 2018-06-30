#include <bits/stdc++.h>
using namespace std;

class YoungTableaus
{
public:
	YoungTableaus(int m, int n);
	void Init(int N);
	void PrintYT();
	int ExtractMin();
private:
	int* mat;
	int existsize;
	int mat_m;
	int mat_n;
};

YoungTableaus::YoungTableaus(int m, int n)
{
	mat_m = m;
	mat_n = n;
	mat = new int[m*n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			mat[i*n + j] = INT_MAX;
}

void YoungTableaus::Init(int N)
{
	existsize = N;
	int i = 0;
	int j = 0;
	while (N--)
	{
		scanf("%d", &mat[i*mat_n + j]);
		if (i>=j)
			j = j + 1;
		else
		{
			j = j - 1;
			i = i + 1;
		}
	}
}

void YoungTableaus::PrintYT()
{
	for (int i = 0; i < mat_m; i++)
	{
		for (int j = 0; j < mat_n; j++)
		{
			if (mat[i*mat_n + j] == INT_MAX)
			{
				printf("M ");
			}
			else
			{
				printf("%d ", mat[i*mat_n + j]);
			}
		}
		printf("\n");
	}
}

int YoungTableaus::ExtractMin()
{
	return 0;
}

int main()
{
	int m, n,N;
	printf("Input the size of matrix:\n");
	scanf("%d %d", &m, &n);
	YoungTableaus A(m, n);
	printf("Input the number of elements:\n");
	scanf("%d", &N);
	printf("Input the elements:\n");
	A.Init(N);
	A.PrintYT();
	system("pause");
	return 0;
}

