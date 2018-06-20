#include <bits/stdc++.h>
using namespace std;

int BlasedRandom(double p)
{
	double rp = double(int(rand() % 100))/100 ;
	if (rp < p)
		return 1;
	else
	{
		return 0;
	}
}

int myrandom01(double p)
{
	int a = BlasedRandom(p);
	int b = BlasedRandom(p);
	if (a == b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	double p;
	while (scanf("%lf", &p) != EOF)
	{
		printf("%d\n", myrandom01(p));
	}
	return 0;
}