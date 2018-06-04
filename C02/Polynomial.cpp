#include <bits/stdc++.h>
using namespace std;

int Horner(vector<int> a, int x) //theta(n)
{
	int y = 0;
	for (int i = a.size()-1; i >= 0; i--)
	{
		y = a[i] + x * y;
	}
	return y;
}

int Naive(vector<int> a, int x) //theta(nlogn)
{
	int y = 0;
	for (int k = 0; k < a.size(); k++)
	{
		y = y + a[k] * pow(x, k);
	}
	return y;
}

int main()
{
	int n,x,y;
	while(scanf("%d",&n)!=EOF)
	{
		vector<int> a(n + 1);
		for (int i = 0; i <= n; i++)
			scanf("%d", &a[i]);
		scanf("%d", &x);
		y = Horner(a,x);
		printf("%d\n", y);
		y = Naive(a,x);
		printf("%d\n", y);
	}
	return 0;
}
