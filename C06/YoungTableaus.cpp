#include <bits/stdc++.h>
using namespace std;

class YoungTableaus
{
public:
	YoungTableaus(int m, int n);
	void Init(int N);
	void PrintYT();
	int ExtractMin();
	void MinHeapify(int i, int j);
	void DecreaseKey(int i, int j, int key);
	void Insert(int key);
	void Sort(vector<int> &sortedarray);
	void Search(int &key_i, int &key_j, int key);
private:
	int* mat;
	int existsize;
	int mat_m;
	int mat_n;
};

YoungTableaus::YoungTableaus(int m, int n)
{
	mat_m = m;
	mat_n = n;
	mat = new int[m*n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			mat[i*n + j] = INT_MAX;
}

void YoungTableaus::Init(int N)
{
	existsize = N;
	int i = 0;
	int j = 0;
	while (N--)
	{
		scanf("%d", &mat[i*mat_n + j]);
		if (j < mat_n-1)
			j = j + 1;
		else
		{
			i = i + 1;
			j = 0;
		}
	}
}

void YoungTableaus::PrintYT()
{
	for (int i = 0; i < mat_m; i++)
	{
		for (int j = 0; j < mat_n; j++)
		{
			if (mat[i*mat_n + j] == INT_MAX)
			{
				printf("M ");
			}
			else
			{
				printf("%d ", mat[i*mat_n + j]);
			}
		}
		printf("\n");
	}
}

int YoungTableaus::ExtractMin()
{
	int minvalue = mat[0];
	mat[0] = mat[mat_m*mat_n-1];
	MinHeapify(0, 0);
	existsize = existsize - 1;
	return minvalue;
}

void YoungTableaus::MinHeapify(int i, int j)
{
	int min_i, min_j,tmp;
	if (j<mat_n - 1 && mat[i*mat_n + j]>mat[i*mat_n + j + 1])
	{
		min_i = i;
		min_j = j+1;
	}
	else
	{
		min_i = i;
		min_j = j;
	}
	if (i < mat_m&&mat[min_i*mat_n + min_j]>mat[(i+1)*mat_n+j])
	{
		min_i = i + 1;
		min_j = j;
	}
	if (min_i != i || min_j != j)
	{
		tmp = mat[i*mat_n + j];
		mat[i*mat_n + j] = mat[min_i*mat_n + min_j];
		mat[min_i*mat_n + min_j] = tmp;
		MinHeapify(min_i, min_j);
	}
}

void YoungTableaus::DecreaseKey(int i, int j, int key)
{
	int max_i, max_j,tmp;
	mat[i*mat_n+j] = key;
	if (j > 0 && mat[i*mat_n + j] < mat[i*mat_n + j - 1])
	{
		max_i = i;
		max_j = j - 1;
	}
	else
	{
		max_i = i;
		max_j = j;
	}
	if (i > 0 && mat[max_i*mat_n + max_j] < mat[(i - 1)*mat_n + j])
	{
		max_i = i - 1;
		max_j = j;
	}
	if (max_i != i || max_j != j)
	{
		tmp = mat[i*mat_n + j];
		mat[i*mat_n + j] = mat[max_i*mat_n + max_j];
		mat[max_i*mat_n + max_j] = tmp;
		DecreaseKey(max_i, max_j, key);
	}
}

void YoungTableaus::Insert(int key)
{
	if (mat[mat_m*mat_n - 1] < INT_MAX)
		printf("Error: The Young Tableaus is full.\n");
	else
	{
		DecreaseKey(mat_m, mat_n, key);
		existsize = existsize + 1;
	}
}

void YoungTableaus::Sort(vector<int> &sortedarray)
{
	sortedarray.resize(existsize);
	for (int j = 0; j < sortedarray.size(); j++)
		sortedarray[j] = ExtractMin();
}

void YoungTableaus::Search(int &key_i,int &key_j,int key)
{
	int i1=0, j1=0, i2=mat_m-1, j2=mat_n-1;
	key_i = -1;
	key_j = -1;
	while (i1 <= i2 && j1 <= j2)
	{
		if (key == mat[i1*mat_n + j2])
		{
			key_i = i1;
			key_j = j2;
			break;
		}
		else if (key < mat[i1*mat_n + j2])
		{
			j2 = j2 - 1;
		}
		else
		{
			i1 = i1 + 1;
		}
	}
}

int main()
{
	int m, n,N,instruction,key;
	vector<int> sortedarray;
	printf("Input the size of matrix:\n");
	scanf("%d %d", &m, &n);
	YoungTableaus A(m, n);
	printf("Input the number of elements:\n");
	scanf("%d", &N);
	printf("Input the elements:\n");
	A.Init(N);
	printf("1. Print the Young Tableaus.\n");
	printf("2. Extract the minimum element from the Young Tableaus.\n");
	printf("3. Insert an element to the Young Tableaus.\n");
	printf("4. Sort the elements.\n");
	printf("5. Judge if one element exists in the Young Tableaus.\n");
	printf("6. Exit.\n");
	while (1)
	{
		scanf("%d", &instruction);
		switch(instruction) {
		case 1:
			A.PrintYT();
			break;
		case 2:
			key=A.ExtractMin();
			printf("The element to be extracted is %d\n", key);
			break;
		case 3:
			printf("Input the element to be inserted:\n");
			scanf("%d", &key);
			A.Insert(key);
			break;
		case 4:
			A.Sort(sortedarray);
			printf("Sorted array:\n");
			for (int j = 0; j < sortedarray.size(); j++)
				printf("%d ",sortedarray[j]);
			printf("\n");
			break;
		case 5:
			int key_i, key_j;
			printf("Input the element to be searched:\n");
			scanf("%d", &key);
			A.Search(key_i, key_j, key);
			printf("The element's position is (%d, %d)\n", key_i, key_j);
			break;
		case 6:
			return 0;
		default:
			printf("Invalid instruction.\n");
		}
	}
	return 0;
}

