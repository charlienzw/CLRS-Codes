#include <bits/stdc++.h>
using namespace std;

//O(2^n) Brute Force
int CutRod(vector<int> p,int n)
{
	if (n == 0)
		return 0;
	int	q = INT_MIN;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		tmp = p[i] + CutRod(p, n-1-i);
		if (tmp > q)
			q = tmp;
	}
	return q;
}

//O(n^2) top-down with memoization
int MemoizedCutRodAux(vector<int> p, int n, vector<int> r)
{
	int q, tmp;
	if (r[n] >= 0)
	{
		return r[n];
	}
	if (n == 0)
	{
		q = 0;
	}
	else
	{
		q = INT_MIN;
		for (int i = 1; i <= n; i++)
		{
			tmp = p[i-1] + MemoizedCutRodAux(p, n - i, r);
			if (tmp > q)
				q = tmp;
		}
	}
	r[n] = q;
	return q;
}

int MemoizedCutRod(vector<int> p, int n)
{
	vector<int> r(n + 1);
	for (int i = 0; i <= n; i++)
	{
		r[i] = INT_MIN;
	}
	return MemoizedCutRodAux(p, n, r);
}

//O(n^2) bottom-up method
int BottomUpCutRod(vector<int> p, int n)
{
	vector<int> r(n + 1);
	r[0] = 0;
	int q,tmp;
	for (int j = 1; j <= n; j++)
	{
		q = INT_MIN;
		for (int i = 1; i <= j; i++)
		{
			tmp = p[i-1] + r[j - i];
			if (tmp > q)
			{
				q = tmp;
			}
		}
		r[j] = q;
	}
	return r[n];
}

//Extended bottom-up method
void ExtendedBottomUpCutRod(vector<int> p, int n,vector<int> &r,vector<int> &s)
{
	r.resize(n+1);
	s.resize(n+1);
	r[0] = 0;
	int q;
	for (int j = 1; j <= n; j++)
	{
		q = INT_MIN;
		for (int i = 1; i <= j; i++)
		{
			if (q < p[i-1] + r[j - i])
			{
				q = p[i-1] + r[j - i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
}

void PrintCutRodSolution(vector<int> p, int n)
{
	vector<int> r;
	vector<int> s;
	ExtendedBottomUpCutRod(p, n, r, s);
	printf("%d\n", r[n]);
	while (n > 0)
	{
		printf("%d\n", s[n]);
		n = n - s[n];
	}
}

//Extend bottom-up method with cutting cost C
void ExtendedBottomUpCutRodC(vector<int> p, int n, vector<int> &r, vector<int> &s,int C)
{
	r.resize(n + 1);
	s.resize(n + 1);
	r[0] = 0;
	int q;
	for (int j = 1; j <= n; j++)
	{
		q = INT_MIN;
		for (int i = 1; i <= j; i++)
		{
			if (q < p[i - 1] + r[j - i]-C)
			{
				q = p[i - 1] + r[j - i]-C;
				s[j] = i;
			}
		}
		r[j] = q;
	}
}

void PrintCutRodSolutionC(vector<int> p, int n,int C)
{
	vector<int> r;
	vector<int> s;
	ExtendedBottomUpCutRodC(p, n, r, s,C);
	printf("%d\n", r[n]);
	while (n > 0)
	{
		printf("%d\n", s[n]);
		n = n - s[n];
	}
}

// Extended top-down with memoization
int ExtendedMemoizedCutRodAux(vector<int> p, int n, vector<int> r,vector<int> &s)
{
	int q, tmp;
	if (r[n] >= 0)
	{
		return r[n];
	}
	if (n == 0)
	{
		q = 0;
	}
	else
	{
		q = INT_MIN;
		for (int i = 1; i <= n; i++)
		{
			tmp = p[i - 1] + ExtendedMemoizedCutRodAux(p, n - i, r,s);
			if (tmp > q)
			{
				q = tmp;
				s[n] = i;
			}
		}
	}
	r[n] = q;
	return q;
}

int ExtendedMemoizedCutRod(vector<int> p, int n,vector<int> &s)
{
	vector<int> r(n + 1);
	for (int i = 0; i <= n; i++)
	{
		r[i] = INT_MIN;
	}
	return ExtendedMemoizedCutRodAux(p, n, r,s);
}

void PrintCutRodSolution2(vector<int> p, int n)
{
	vector<int> s(n+1);
	printf("%d\n",ExtendedMemoizedCutRod(p, n, s));
	while (n > 0)
	{
		printf("%d\n", s[n]);
		n = n - s[n];
	}
}

//Test
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		vector<int> p(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &p[i]);
		printf("%d\n", CutRod(p,n));
		printf("%d\n", MemoizedCutRod(p,n));
		printf("%d\n", BottomUpCutRod(p,n));
		PrintCutRodSolution(p,n);
		PrintCutRodSolutionC(p, n, 1);
		PrintCutRodSolution2(p, n);
	}
	return 0;
}