#include <bits/stdc++.h>
using namespace std;

void minmax(vector<int> A, int &minimum, int &maximum)
{
	if (A.size() % 2 != 0)
	{
		minimum = A[0];
		maximum = A[0];
		for (int i = 1; i < A.size(); i=i+2)
		{
			if (A[i] >= A[i + 1])
			{
				if (A[i] > maximum)
					maximum=A[i];
				if (A[i + 1] < minimum)
					minimum = A[i + 1];
			}
			else
			{
				if (A[i+1] > maximum)
					maximum = A[i+1];
				if (A[i] < minimum)
					minimum = A[i];
			}
		}
	}
	else
	{
		if (A[0] >= A[1])
		{
			maximum = A[0];
			minimum = A[1];
		}
		else
		{
			maximum = A[1];
			minimum = A[0];
		}
		for (int i = 2; i < A.size(); i=i+2)
		{
			if (A[i] >= A[i + 1])
			{
				if (A[i] > maximum)
					maximum = A[i];
				if (A[i + 1] < minimum)
					minimum = A[i + 1];
			}
			else
			{
				if (A[i + 1] > maximum)
					maximum = A[i + 1];
				if (A[i] < minimum)
					minimum = A[i];
			}
		}
	}
}

int main()
{
	int N, minimum, maximum;
	while (scanf("%d", &N) != EOF)
	{
		vector<int> A(N);
		for (int i = 0; i < A.size(); i++)
			scanf("%d", &A[i]);
		minmax(A, minimum, maximum);
		printf("minimum: %d\n",minimum);
		printf("maximum: %d\n", maximum);
	}
	return 0;
}