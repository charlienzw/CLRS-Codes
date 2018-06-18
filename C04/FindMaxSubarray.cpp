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

void FindMaxSubarray_Recursive(vector<int> &result,vector<int> &A,int low,int high)
{
	if (high == low)
	{
		result = { low,high,A[low] };
	}
	else
	{
		int mid = (low + high) / 2;
		vector<int> left_result(3);
		FindMaxSubarray_Recursive(left_result, A, low, mid);
		vector<int> right_result(3);
		FindMaxSubarray_Recursive(right_result, A, mid+1, high);
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

void FindMaxSubarray_BruteForce(vector<int> &result, vector<int> &A,int low,int high)
{
	int maxsum = INT_MIN;
	int maxleft = 0;
	int maxright = 0;
	for (int i = low; i <=high; i++)
	{
		int sum = 0;
		for (int j = i; j <=high; j++)
		{
			sum = sum + A[j];
			if (sum > maxsum)
			{
				maxsum = sum;
				maxleft = i;
				maxright = j;
			}
		}
	}
	result = { maxleft,maxright,maxsum };
}

void FindMaxSubarray(vector<int> &result, vector<int> &A, int low, int high,int n0)
{
	if (high - low + 1 < n0)
	{
		FindMaxSubarray_BruteForce(result, A, low, high);
	}
	else
	{
		FindMaxSubarray_Recursive(result, A,low, high);
	}
}

void FindMaxSubarray_emptyresult(vector<int> &result, vector<int> &A, int low, int high, int n0)
{
	if (high - low + 1 < n0)
	{
		FindMaxSubarray_BruteForce(result, A, low, high);
	}
	else
	{
		FindMaxSubarray_Recursive(result, A, low, high);
	}
	if (result[2] < 0)
	{
		result={ NULL,NULL,0 };
	}
}

void FindMaxSubarray_lineartime(vector<int> &result, vector<int> &A)
{
	int maxsum = A[0];
	int maxleft = 0;
	int maxright = 0;
	int j=0;
	vector<int> sum_vec(A.size());
	sum_vec[0] = A[0];
	for (int i = 1; i < A.size(); i++)
	{
		if (sum_vec[i - 1] > 0)
		{
			sum_vec[i] = sum_vec[i - 1] + A[i];
		}
		else
		{
			sum_vec[i] = A[i];
			j = i;
		}
		if (sum_vec[i] > maxsum)
		{
			maxsum = sum_vec[i];
			maxleft = j;
			maxright = i;
		}
	}
	result = { maxleft,maxright,maxsum };
}

int main()
{
	int N;
	int n0=44;
	while (scanf("%d", &N) != EOF)
	{
		vector<int> A(N);
		for (int i = 0; i<A.size(); i++)
			scanf("%d", &A[i]);
		vector<int> result(3);
		FindMaxSubarray(result,A,0,N-1,n0);
		for (int i = 0; i<result.size(); i++)
			printf("%d ", result[i]);
		printf("\n");
		FindMaxSubarray_emptyresult(result, A, 0, N - 1, n0);
		for (int i = 0; i<result.size(); i++)
			printf("%d ", result[i]);
		printf("\n");
		FindMaxSubarray_lineartime(result, A);
		for (int i = 0; i<result.size(); i++)
			printf("%d ", result[i]);
		printf("\n");
	}
	return 0;
}
