#include <bits/stdc++.h>
using namespace std;

int Radixnumber(int num, int radix)
{
	return (num / (int)pow(10, radix)) % 10;
}

void CountingSort(vector<int> &A, int radix)
{
	vector<int> B(A.size());
	for (int j = 0; j < B.size(); j++)
		B[j] = A[j];
	vector<int> C(10, 0);
	for (int j = 0; j < B.size(); j++)
	{
		C[Radixnumber(B[j], radix)] = C[Radixnumber(B[j], radix)] + 1;
	}
	for (int i = 1; i < C.size(); i++)
		C[i] = C[i] + C[i - 1];
	for (int j = A.size() - 1; j >= 0; j--)
	{
		A[C[Radixnumber(B[j], radix)] - 1] = B[j];
		C[Radixnumber(B[j], radix)] = C[Radixnumber(B[j], radix)] - 1;
	}
}

int Radixnumber(string str, int radix)
{
	return str[str.size()-1-radix]-96;
}

void CountingSort(vector<string> &A, int radix)
{
	vector<string> B(A.size());
	for (int j = 0; j < B.size(); j++)
		B[j] = A[j];
	vector<int> C(27, 0);
	for (int j = 0; j < B.size(); j++)
	{
		C[Radixnumber(B[j], radix)] = C[Radixnumber(B[j], radix)] + 1;
	}
	for (int i = 1; i < C.size(); i++)
		C[i] = C[i] + C[i - 1];
	for (int j = A.size() - 1; j >= 0; j--)
	{
		A[C[Radixnumber(B[j], radix)] - 1] = B[j];
		C[Radixnumber(B[j], radix)] = C[Radixnumber(B[j], radix)] - 1;
	}
}

void RadixSort(vector<int> &A, int d)
{
	for (int i = 0; i < d; i++)
	{
		CountingSort(A, i);
	}
}

void RadixSort(vector<string> &A, int d)
{
	for (int i = 0; i < d; i++)
	{
		CountingSort(A, i);
	}
}

int digitlen(int num)
{
	int length = 1;
	while (num / 10 != 0)
	{
		num = num / 10;
		length++;
	}
	return length;
}

void BucketRadixSort(vector<int> &A)
{
	int n = A.size();
	int maxlen = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (digitlen(A[i]) > maxlen)
			maxlen = digitlen(A[i]);
	}
	vector<vector<int>> B(maxlen);
	for (int i = 0; i < B.size(); i++)
	{
		B[i].resize(0);
	}
	for (int i = 0; i<n; i++)
	{
		B[digitlen(A[i])-1].push_back(A[i]);
	}
	for (int i = 0; i < B.size(); i++)
	{
		RadixSort(B[i], i + 1);
	}
	int k = 0;
	for (int i = 0; i < B.size(); i++)
	{
		for (int j = 0; j < B[i].size(); j++)
		{
			A[k] = B[i][j];
			k = k + 1;
		}
	}
}

void PlusRadixSort(vector<string> &A)
{
	int n = A.size();
	int maxlen = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i].size() > maxlen)
			maxlen = A[i].size();
	}
	vector<string> B(A.size());
	for (int i = 0; i < B.size(); i++)
	{
		B[i].resize(maxlen);
		for (int j = 0; j < B[i].size(); j++)
		{
			if (j < A[i].size()) B[i][j] = A[i][j];
			else B[i][j] = 96;
		}
	}
	RadixSort(B, maxlen);
	for (int i = 0; i < B.size(); i++)
	{
		A[i] = B[i];
		for (int j = 0; j < A[i].size(); j++)
		{
			if (A[i][j] == 96) A[i][j] = '\0';
		}
	}
}

int main()
{
	int N,flag;
	vector<int> A;
	vector<string> B;
	printf("1. Input an integer array.\n");
	printf("2. Input a string array.\n");
	while (scanf("%d", &flag) != EOF)
	{
		switch (flag)
		{
		case 1:
			scanf("%d",&N);
			A.resize(N);
			for (int i = 0; i < A.size(); i++)
				cin >> A[i];
			BucketRadixSort(A);
			for (int i = 0; i<A.size(); i++)
				cout << A[i] << " ";
			cout << endl;
			break;
		case 2:
			scanf("%d", &N);
			B.resize(N);
			for (int i = 0; i<B.size(); i++)
				cin>>B[i];
			PlusRadixSort(B);
			for (int i = 0; i<B.size(); i++)
				cout<<B[i]<<" ";
			cout<<endl;
			break;
		default:
			printf("Invalid Instruction.\n");
		}
	}
	return 0;
}
