#include <bits/stdc++.h>
using namespace std;

class interval {
public:
	int start;
	int end;
	bool operator <(const interval &L)
	{
		if (end < L.start)
			return true;
		else
			return false;
	}
	bool operator ==(const interval &L)
	{
		if (start <= L.start&&end >= L.start)
			return true;
		else
			return false;
	}
	bool operator >(const interval &L)
	{
		if (start >L.start)
			return true;
		else
			return false;
	}
	friend ostream &operator<<(ostream &output,
		const interval &L)
	{
		output << "[" << L.start << ", " << L.end << "]";
		return output;
	}

	friend istream &operator>>(istream  &input, interval &L)
	{
		input >> L.start >> L.end;
		return input;
	}
	void operator=(const interval &L)
	{
		start = L.start;
		end = L.end;
	}
};

void FuzzyIntervalPartition(vector<interval> &A, int p, int r, int &q, int &t)
{
	interval tmp;
	interval x = A[r];
	int i = p - 1, j = p - 1;
	for (int k = p; k <= r - 1; k++)
	{
		if (A[k] < x)
		{
			i = i + 1;
			j = j + 1;
			tmp = A[k];
			A[k] = A[i];
			A[i] = tmp;
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
		if (A[k] == x)
		{
			i = i + 1;
			tmp = A[k];
			A[k] = A[i];
			A[i] = tmp;
		}
	}
	tmp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = tmp;
	q = j + 1;
	t = i;
}

void FuzzyIntervalRandomizedPartition(vector<interval> &A, int p, int r, int &q, int &t)
{
	int i = p + rand() % (r - p + 1);
	interval tmp;
	tmp = A[r];
	A[r] = A[i];
	A[i] = tmp;
	return FuzzyIntervalPartition(A, p, r, q, t);
}

void FuzzyIntervalQuickSort(vector<interval> &A, int p, int r)
{
	if (p < r)
	{
		int q, t;
		FuzzyIntervalRandomizedPartition(A, p, r, q, t);
		FuzzyIntervalQuickSort(A, p, q - 1);
		FuzzyIntervalQuickSort(A, t + 1, r);
	}
}

int main()
{
	int N;
	while (scanf("%d", &N) != EOF)
	{
		vector<interval> A(N);
		for (int i = 0; i < A.size(); i++)
			cin>>A[i];
		FuzzyIntervalQuickSort(A, 0, N - 1);
		for (int i = 0; i < A.size(); i++)
			cout << A[i] << " ";
		cout << endl;
	}
	return 0;
}