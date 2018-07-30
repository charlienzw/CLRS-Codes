#include <bits/stdc++.h>
using namespace std;

void PrintLCS(vector<vector<int>> b, vector<int> X, int i, int j)
{
	if (i == -1 || j == -1)
		return;
	if (b[i][j] == 1)
	{
		PrintLCS(b, X, i - 1, j - 1);
		printf("%d", X[i]);
	}
	else if (b[i][j] == 2)
	{
		PrintLCS(b, X, i - 1, j);
	}
	else
	{
		PrintLCS(b, X, i, j - 1);
	}
}

void LCSLength(vector<int> X, vector<int> Y, vector<vector<int>> &b, vector<vector<int>> &c)
{
	int m = X.size();
	int n = Y.size();
	b.resize(m);
	for (int i = 0; i < m; i++)
	{
		b[i].resize(n);
	}
	c.resize(m + 1);
	for (int i = 0; i <= m; i++)
	{
		c[i].resize(n + 1);
	}
	for (int i = 0; i <= m; i++)
		c[i][0] = 0;
	for (int j = 0; j <= n; j++)
		c[0][j] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (X[i-1] == Y[j-1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i - 1][j - 1] = 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i-1][j-1] = 2;
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i-1][j-1] = 0;
			}
		}
	}
}

int main()
{
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		vector<int> X(m);
		for (int i = 0; i < m; i++) scanf("%d", &X[i]);
		vector<int> Y(n);
		for (int i = 0; i < n; i++) scanf("%d", &Y[i]);
		vector<vector<int>> b;
		vector<vector<int>> c;
		LCSLength(X,Y,b,c);
		printf("%d\n",c[m][n]);
		PrintLCS(b,X,m-1,n-1);
		printf("\n");
	}
	return 0;
}