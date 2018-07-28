#include <bits/stdc++.h>
using namespace std;

void MatrixChainOrder(vector<int> p,vector<vector<int>> &m,vector<vector<int>> &s)
{
	int n = p.size() - 1;
	m.resize(n);
	for (int i = 0; i < n; i++)
	{
		m[i].resize(n);
		m[i][i] = 0;
	}
	s.resize(n);
	for (int i = 0; i < n - 1; i++)
	{
		s[i].resize(n);
	}
	for (int l = 2; l <= n; l++)
	{
		for (int i = 0; i <= n-l;i++)
		{
			int j = i + l-1;
			m[i][j] = INT_MAX;
			printf("%d-%d-%d\n", i, j, l);
			for (int k = i; k <= j-1; k++)
			{
				int q = m[i][k] + m[k + 1][j] + p[i] * p[k+1] * p[j+1];
				if (q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
			printf("%d-%d-%d\n", i, j, l);
		}
	}
}

void PrintOptimalParens(vector<vector<int>> s, int i,int j)
{
	if (i == j)
	{
		printf("A");
	}
	else
	{
		printf("(");
		PrintOptimalParens(s, i, s[i][j]);
		PrintOptimalParens(s, s[i][j] + 1, j);
		printf(")");
	}
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		vector<int> p(n+1);
		for (int i = 0; i < n + 1; i++)
		{
			scanf("%d", &p[i]);
		}
		vector<vector<int>> m;
		vector<vector<int>> s;
		MatrixChainOrder(p,m,s);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d ", m[i][j]);
			}
			printf("\n");
		}
		printf("%d\n", m[0][n-1]);
		PrintOptimalParens(s, 0, n - 1);
	}
	return 0;
}