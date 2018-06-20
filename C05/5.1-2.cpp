#include <bits/stdc++.h>
using namespace std;

int myrandom01()
{
	return rand() % 2;
}

double log2(double n)
{
	return log(n) / log(2);
}

int myrandom(int a, int b)
{
	int n = b - a + 1;
	int k;
	if (double(int(log2(n))) != log2(n))
	{
		k = int(log(n) / log(2)) + 1;
	}
	else
	{
		k = log(n) / log(2);
	}
	vector<int> bit_n(k,0);
	int s=0;
	for (int i = 0; i < k; i++)
	{
		if (s + pow(2, k - i - 1) <n)
		{
			bit_n[i] = myrandom01();
			s = s + bit_n[i] * pow(2, k - i - 1);
		}
		else
		{
			bit_n[i] = 0;
		}
	}
	return a+s;
}

int main()
{
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		printf("%d\n", myrandom(a, b));
	}
	return 0;
}