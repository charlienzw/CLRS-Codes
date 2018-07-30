#include <bits/stdc++.h>
using namespace std;

void PrintLCS(vector<vector<int>> b, vector<int> X, int i, int j)
{
	if (i == -1 || j == -1)
		return;
	if (b[i][j] == 1)
	{
		PrintLCS(b, X, i - 1, j - 1);
		printf("%d ", X[i]);
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
	int n = X.size();
	b.resize(n);
	for (int i = 0; i < n; i++)
	{
		b[i].resize(n);
	}
	c.resize(n + 1);
	for (int i = 0; i <= n; i++)
	{
		c[i].resize(n + 1);
	}
	for (int i = 0; i <= n; i++)
		c[i][0] = 0;
	for (int j = 0; j <= n; j++)
		c[0][j] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (X[i - 1] == Y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i - 1][j - 1] = 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i - 1][j - 1] = 2;
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i - 1][j - 1] = 0;
			}
		}
	}
}

void LIS(vector<int> X)
{
	vector<int> Y(X.size());
	for (int i = 0; i < X.size(); i++)
		Y[i] = X[i];
	sort(Y.begin(), Y.end());
	vector<vector<int>> b;
	vector<vector<int>> c;
	LCSLength(X, Y, b, c);
	PrintLCS(b, X,X.size()-1, X.size()-1);
	printf("\n");
}

int BS(vector<int> X, vector<int> T, int l, int r,int key)
{
	while (r - l > 1)
	{
		int m = l + (r - l) / 2;
		if (X[T[m]] >= key)
			r = m;
		else
			l = m;
	}

	return r;
}

void LIS_BS(vector<int> X)
{
	// Add boundary case, when array n is zero
	// Depend on smart pointers
	int n = X.size();
	vector<int> tailIndices(n, 0); // Initialized with 0 
	vector<int> prevIndices(n, -1); // initialized with -1

	int len = 1; // it will always point to empty location
	for (int i = 1; i < n; i++)
	{
		if (X[i] < X[tailIndices[0]])
		{
			// new smallest value
			tailIndices[0] = i;
		}
		else if (X[i] > X[tailIndices[len - 1]])
		{
			// X[i] wants to extend largest subsequence
			prevIndices[i] = tailIndices[len - 1];
			tailIndices[len++] = i;
		}
		else
		{
			// X[i] wants to be a potential condidate of
			// future subsequence
			// It will replace ceil value in tailIndices
			int pos = BS(X, tailIndices, -1,len - 1, X[i]);
			prevIndices[i] = tailIndices[pos - 1];
			tailIndices[pos] = i;
		}
	}
	vector<int> res;
	for (int i = tailIndices[len - 1]; i >= 0; i = prevIndices[i])
		res.push_back(X[i]);
	while (res.size() != 0)
	{
		printf("%d ",res.back());
		res.pop_back();
	}
	printf("\n");
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		vector<int> X(n);
		for (int i = 0; i < n; i++) scanf("%d", &X[i]);
		LIS(X);
		LIS_BS(X);
	}
	return 0;
}