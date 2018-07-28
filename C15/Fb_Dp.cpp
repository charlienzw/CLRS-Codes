#include <bits/stdc++.h>
using namespace std;

int Fb_Dp(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	vector<int> r(n + 1);
	r[0] = 0;
	r[1] = 1;
	for (int i = 2; i < n + 1; i++)
	{
		r[i] = r[i - 2] + r[i - 1];
	}
	return r[n];
}

int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		printf("%d\n", Fb_Dp(n));
	}
	return 0;
}