#include<bits/stdc++.h>
using namespace std;

int inv(int a, int m)
{
	int m0 = m, t, q;
	int x0 = 0, x1 = 1;
	if (m == 1)
		return 0;
	while (a > 1)
	{
		q = a / m;
		t = m;
		m = a % m;
		a = t;
		t = x0;
		x0 = x1 - q * x0;
		x1 = t;
	}
	if (x1 < 0)
		x1 = x1 + m0;
	return x1;
}

int CRT(vector<int> num, vector<int> rem)
{
	int prod = 1;
	for (int i = 0; i < num.size(); i++)
	{
		prod = prod * num[i];
	}
	int res = 0;
	int pp;
	for (int i = 0; i < num.size(); i++)
	{
		pp = prod / num[i];
		res = res + rem[i] * inv(pp, num[i])*pp;
	}
	return res % prod;
}

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> num(n);
	vector<int> rem(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &rem[i]);
	}
	printf("%d\n",CRT(num,rem));
	system("pause");
	return 0;
}