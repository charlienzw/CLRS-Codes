#include <bits/stdc++.h>
using namespace std;

void ComplexNumberMultiply(int a, int b, int c, int d, vector<int> &result)
{
	result[0] = (a + b)*c - b * (c + d);
	result[1] = (a - b)*d + b * (c + d);
}

int main()
{
	int a, b, c, d;
	while (scanf("%d %d %d %d", &a, &b, &c, &d) != EOF)
	{
		vector<int> result(2);
		ComplexNumberMultiply(a, b, c, d, result);
		printf("%d+%di\n", a*c-b*d, a*d+b*c);
		printf("%d+%di\n", result[0], result[1]);
	}
}