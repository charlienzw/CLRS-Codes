#include <bits/stdc++.h>
using namespace std;

void ComputePrefixFunction(string P,vector<int>& pi)
{
	int m = P.length();
	pi.resize(m);
	pi[0] = 0;
	int k = 0;
	for (int q = 1; q < m; q++)
	{
		while (k >0 && P[k] != P[q])
		{
			k = pi[k-1];
		}
		if (P[k] == P[q])
			k = k + 1;
		pi[q] = k;
	}
}

void KMPMatcher(string T, string P)
{
	int n = T.length(), m = P.length();
	vector<int> pi;
	ComputePrefixFunction(P,pi);
	int q = 0;
	for (int i = 0; i < n; i++)
	{
		while (q > 0 && P[q] != T[i])
			q = pi[q-1];
		if (P[q] == T[i])
			q = q + 1;
		if (q == m)
		{
			printf("%d\n", i - m + 1);
			q = pi[q-1];
		}
	}
}

int main()
{
	string T, P;
	cin >> T;
	cin >> P;
	KMPMatcher(T, P);
	system("pause");
}