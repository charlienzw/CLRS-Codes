#include <bits/stdc++.h>
using namespace std;

void FindMaxCrossingSubarray(vector<int> &result, vector<int> &A, int low,int mid,int high)
{
	int left_sum = INT_MIN;
	int max_left = mid;
	int sum = 0;
	for (int i = mid; i >= low; i--)
	{
		sum = sum + A[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}
	int right_sum = INT_MIN;
	int max_right = mid + 1;
	sum = 0;
	for (int j = mid + 1; j <= high; j++)
	{
		sum = sum + A[j];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = j;
		}
	}
	result = { max_left,max_right,left_sum + right_sum };
}

void FindMaxSubarray(vector<int> &result,vector<int> &A,int low,int high)
{
	if (high == low)
	{
		result = { low,high,A[low] };
	}
	else
	{
		int mid = (low + high) / 2;
		vector<int> left_result(3);
		FindMaxSubarray(left_result, A, low, mid);
		vector<int> right_result(3);
		FindMaxSubarray(right_result, A, mid+1, high);
		vector<int> cross_result(3);
		FindMaxCrossingSubarray(cross_result, A, low, mid,high);
		if (left_result[2] >= right_result[2] && left_result[2] >= cross_result[2])
		{
			result = left_result;
		}
		else if (right_result[2] >= left_result[2] && right_result[2] >= cross_result[2])
		{
			result = right_result;
		}
		else
		{
			result = cross_result;
		}
	}
}

int main()
{
	int N;
	while (scanf("%d", &N) != EOF)
	{
		vector<int> A(N);
		for (int i = 0; i<A.size(); i++)
			scanf("%d", &A[i]);
		vector<int> result(3);
		FindMaxSubarray(result,A,0,N-1);
		for (int i = 0; i<result.size(); i++)
			printf("%d ", result[i]);
		printf("\n");
	}
	return 0;
}
