#include <bits/stdc++.h>
using namespace std;

void RandomSample(int m, int n, vector<int> &S)
{
	if (m == 0)
	{
		vector<int> Stmp;
		S = Stmp;
	}
	else
	{
		vector<int> Stmp;
		RandomSample(m - 1, n - 1, Stmp);
		int i = rand() % n;
		int flag = 0;
		for (int j = 0; j < Stmp.size(); j++)
		{
			if (Stmp[j] == i)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			Stmp.push_back(n - 1);
		}
		else
		{
			Stmp.push_back(i);
		}
		S = Stmp;
	}
}

int main()
{
	int m,n;
	while (scanf("%d %d", &m,&n) != EOF)
	{
		vector<int> S;
		RandomSample(m, n, S);
		for (int i = 0; i < S.size(); i++)
		{
			printf("%d ", S[i]);
		}
		printf("\n");
	}
	return 0;
}