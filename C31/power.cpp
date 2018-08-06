#include <bits/stdc++.h>
using namespace std;

int Exponentiation(int a, int b)
{
	int res = 1;
	while (b > 0)
	{
		if (b & 1) res = res * a;
		b = b >> 1;
		a = a * a;
	}
	return res;
}

int ModularExponentiation(int a, int b, int n)
{
	int res = 1;
	a = a % n;
	while (b > 0)
	{
		if (b & 1) res = (res*a) % n;
		b = b >> 1;
		a = (a*a) % n;
	}
	return res;
}

int main()
{
	int a, b, n;
	scanf("%d %d %d", &a, &b, &n);
	printf("%d\n",Exponentiation(a, b));
	printf("%d\n",ModularExponentiation(a, b, n));
	system("pause");
	return 0;
}