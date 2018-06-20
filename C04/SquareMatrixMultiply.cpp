#include <bits/stdc++.h>
using namespace std;

void SquareMatrixMultiply(vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> &C)
{
	// The size of square matrix A equals to the size of square matrix B
	int n = A.size();
	for (int i=0;i<n;i++)
	{
		for (int j = 0; j < n; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				C[i][j] = C[i][j] + A[i][k] *B[k][j];
			}
		}
	}
}

void SquareMatrixMultiplyRecursive(vector<vector<int>> A,vector<int> field_A,vector<vector<int>> B, vector<int> field_B,vector<vector<int>> &C)
{
	// The size of square matrix A equals to the size of square matrix B
	int n = field_A[1]-field_A[0]+1;
	if (n == 1)
	{
		C[0][0] = A[field_A[0]][field_A[2]] * B[field_B[0]][field_B[2]];
	}
	else
	{
		vector<vector<int>> C1, C2;
		C1.resize(n / 2);
		C2.resize(n / 2);
		for (int i = 0; i < n / 2;i++)
		{
			C1[i].resize(n / 2);
			C2[i].resize(n / 2);
		}
		SquareMatrixMultiplyRecursive(A, { field_A[0],(field_A[0] + field_A[1]) / 2,field_A[2],(field_A[2] + field_A[3])/2 }, B, { field_B[0],(field_B[0] + field_B[1]) / 2,field_B[2],(field_B[2] + field_B[3]) / 2 }, C1);
		SquareMatrixMultiplyRecursive(A, { field_A[0],(field_A[0] + field_A[1]) / 2,(field_A[2] + field_A[3]) / 2 + 1,field_A[3] }, B, { (field_B[0] + field_B[1]) / 2 +1,field_B[1],field_B[2],(field_B[2] + field_B[3]) / 2 }, C2);
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				C[i][j] = C1[i][j] + C2[i][j];
			}
		}
		SquareMatrixMultiplyRecursive(A, { field_A[0],(field_A[0] + field_A[1]) / 2,field_A[2],(field_A[2] + field_A[3]) / 2 }, B, { field_B[0],(field_B[0] + field_B[1]) / 2,(field_B[2] + field_B[3]) / 2+1,field_B[3] }, C1);
		SquareMatrixMultiplyRecursive(A, { field_A[0],(field_A[0] + field_A[1]) / 2,(field_A[2] + field_A[3]) / 2 + 1,field_A[3] }, B, { (field_B[0] + field_B[1]) / 2 + 1,field_B[1],(field_B[2] + field_B[3]) / 2+1,field_B[3] }, C2);
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				C[i][j+n/2] = C1[i][j] + C2[i][j];
			}
		}
		SquareMatrixMultiplyRecursive(A, { (field_A[0] + field_A[1]) / 2 + 1,field_A[1],field_A[2],(field_A[2] + field_A[3]) / 2 }, B, { field_B[0],(field_B[0] + field_B[1]) / 2,field_B[2],(field_B[2] + field_B[3]) / 2 }, C1);
		SquareMatrixMultiplyRecursive(A, { (field_A[0] + field_A[1]) / 2 + 1,field_A[1],(field_A[2] + field_A[3]) / 2+1,field_A[3] }, B, { (field_B[0] + field_B[1]) / 2 + 1,field_B[1],field_B[2],(field_B[2] + field_B[3]) / 2 }, C2);
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				C[i+n/2][j] = C1[i][j] + C2[i][j];
			}
		}
		SquareMatrixMultiplyRecursive(A, { (field_A[0] + field_A[1]) / 2 + 1,field_A[1],field_A[2],(field_A[2] + field_A[3]) / 2 }, B, { field_B[0],(field_B[0] + field_B[1]) / 2,(field_B[2] + field_B[3]) / 2 + 1,field_B[3] }, C1);
		SquareMatrixMultiplyRecursive(A, { (field_A[0] + field_A[1]) / 2 + 1,field_A[1],(field_A[2] + field_A[3]) / 2 + 1,field_A[3] }, B, { (field_B[0] + field_B[1]) / 2 + 1,field_B[1],(field_B[2] + field_B[3]) / 2 + 1,field_B[3] }, C2);
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				C[i + n / 2][j+n/2] = C1[i][j] + C2[i][j];
			}
		}
	}
}

void SquareMatrixMultiplyStrassen(vector<vector<int>> A, vector<int> field_A, vector<vector<int>> B, vector<int> field_B, vector<vector<int>> &C)
{
	// The size of square matrix A equals to the size of square matrix B
	int n = field_A[1] - field_A[0] + 1;
	if (n == 1)
	{
		C[0][0] = A[field_A[0]][field_A[2]] * B[field_B[0]][field_B[2]];
	}
	else
	{
		vector<vector<int>> S1;
		S1.resize(n / 2);
		for (int i = 0; i < n / 2; i++)
		{
			S1[i].resize(n / 2);
			for (int j = 0; j < n / 2; j++)
			{
				S1[i][j] = B[field_B[0]+i][field_B[2] +j+ n / 2] - B[field_B[0] + i + n / 2][field_B[2] + j + n / 2];
			}
		}
		vector<vector<int>> S2;
		S2.resize(n / 2);
		for (int i = 0; i < n / 2; i++)
		{
			S2[i].resize(n / 2);
			for (int j = 0; j < n / 2; j++)
			{
				S2[i][j] = A[field_A[0] + i][field_A[2] + j] + A[field_A[0] + i][field_A[2] + j + n / 2];
			}
		}
		vector<vector<int>> S3;
		S3.resize(n / 2);
		for (int i = 0; i < n / 2; i++)
		{
			S3[i].resize(n / 2);
			for (int j = 0; j < n / 2; j++)
			{
				S3[i][j] = A[field_A[0] + i+n/2][field_A[2] + j] + A[field_A[0] + i + n / 2][field_A[2] + j + n / 2];
			}
		}
		vector<vector<int>> S4;
		S4.resize(n / 2);
		for (int i = 0; i < n / 2; i++)
		{
			S4[i].resize(n / 2);
			for (int j = 0; j < n / 2; j++)
			{
				S4[i][j] = B[field_B[0] + i+n/2][field_B[2] + j] - B[field_B[0] + i][field_B[2] + j];
			}
		}
		vector<vector<int>> S5;
		S5.resize(n / 2);
		for (int i = 0; i < n / 2; i++)
		{
			S5[i].resize(n / 2);
			for (int j = 0; j < n / 2; j++)
			{
				S5[i][j] = A[field_A[0] + i][field_A[2] + j] + A[field_A[0] + i + n / 2][field_A[2] + j + n / 2];
			}
		}
		vector<vector<int>> S6;
		S6.resize(n / 2);
		for (int i = 0; i < n / 2; i++)
		{
			S6[i].resize(n / 2);
			for (int j = 0; j < n / 2; j++)
			{
				S6[i][j] = B[field_B[0] + i][field_B[2] + j] + B[field_B[0] + i + n / 2][field_B[2] + j + n / 2];
			}
		}
		vector<vector<int>> S7;
		S7.resize(n / 2);
		for (int i = 0; i < n / 2; i++)
		{
			S7[i].resize(n / 2);
			for (int j = 0; j < n / 2; j++)
			{
				S7[i][j] = A[field_A[0] + i][field_A[2] + j + n / 2] - A[field_A[0] + i + n / 2][field_A[2] + j + n / 2];
			}
		}
		vector<vector<int>> S8;
		S8.resize(n / 2);
		for (int i = 0; i < n / 2; i++)
		{
			S8[i].resize(n / 2);
			for (int j = 0; j < n / 2; j++)
			{
				S8[i][j] = B[field_B[0] + i+n/2][field_B[2] + j] + B[field_B[0] + i + n / 2][field_B[2] + j + n / 2];
			}
		}
		vector<vector<int>> S9;
		S9.resize(n / 2);
		for (int i = 0; i < n / 2; i++)
		{
			S9[i].resize(n / 2);
			for (int j = 0; j < n / 2; j++)
			{
				S9[i][j] = A[field_A[0] + i][field_A[2] + j] - A[field_A[0] + i + n / 2][field_A[2] + j];
			}
		}
		vector<vector<int>> S10;
		S10.resize(n / 2);
		for (int i = 0; i < n / 2; i++)
		{
			S10[i].resize(n / 2);
			for (int j = 0; j < n / 2; j++)
			{
				S10[i][j] = B[field_B[0] + i][field_B[2] + j] + B[field_B[0] + i][field_B[2] + j + n / 2];
			}
		}
		vector<vector<int>> P1;
		vector<vector<int>> P2;
		vector<vector<int>> P3;
		vector<vector<int>> P4;
		vector<vector<int>> P5;
		vector<vector<int>> P6;
		vector<vector<int>> P7;
		P1.resize(n / 2);
		P2.resize(n / 2);
		P3.resize(n / 2);
		P4.resize(n / 2);
		P5.resize(n / 2);
		P6.resize(n / 2);
		P7.resize(n / 2);
		for (int i = 0; i < n / 2; i++)
		{
			P1[i].resize(n / 2);
			P2[i].resize(n / 2);
			P3[i].resize(n / 2);
			P4[i].resize(n / 2);
			P5[i].resize(n / 2);
			P6[i].resize(n / 2);
			P7[i].resize(n / 2);
		}
		SquareMatrixMultiplyStrassen(A, { field_A[0],(field_A[0] + field_A[1]) / 2,field_A[2],(field_A[2] + field_A[3]) / 2 }, S1, { 0,n / 2 - 1,0,n / 2 - 1 }, P1);
		SquareMatrixMultiplyStrassen(S2, { 0,n / 2 - 1,0,n / 2 - 1 }, B, {(field_B[0]+field_B[1])/2+1,field_B[1],(field_B[2]+field_B[3])/2+1,field_B[3]},P2);
		SquareMatrixMultiplyStrassen(S3, { 0,n / 2 - 1,0,n / 2 - 1 }, B, { field_B[0],(field_B[0] + field_B[1]) / 2,field_B[2],(field_B[2] + field_B[3]) / 2 },P3);
		SquareMatrixMultiplyStrassen(A, { (field_A[0] + field_A[1]) / 2 + 1,field_A[1],(field_A[2] + field_A[3]) / 2 + 1,field_A[3] }, S4, { 0,n / 2 - 1,0,n / 2 - 1 }, P4);
		SquareMatrixMultiplyStrassen(S5, { 0,n / 2 - 1,0,n / 2 - 1 }, S6, { 0,n / 2 - 1,0,n / 2 - 1 }, P5);
		SquareMatrixMultiplyStrassen(S7, { 0,n / 2 - 1,0,n / 2 - 1 }, S8, { 0,n / 2 - 1,0,n / 2 - 1 }, P6);
		SquareMatrixMultiplyStrassen(S9, { 0,n / 2 - 1,0,n / 2 - 1 }, S10, { 0,n / 2 - 1,0,n / 2 - 1 }, P7);
		for (int i = 0; i < n/2; i++)
		{
			for (int j = 0; j < n/2; j++)
			{
				C[i][j] = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];
				C[i][j + n / 2] = P1[i][j] + P2[i][j];
				C[i + n / 2][j] = P3[i][j] + P4[i][j];
				C[i + n / 2][j + n / 2] = P5[i][j] + P1[i][j] - P3[i][j] - P7[i][j];
			}
		}
	}
}

double log2(double n)
{
	return log(n) / log(2);
}

int main()
{
	int n,N;
	while (scanf("%d", &n) != EOF)
	{
		if (double(int(log2(n)))!=log2(n))
		{
			N = pow(2, int(log2(n)) + 1);
		}
		else
		{
			N = n;
		}
		vector<vector<int>> A;
		A.resize(N);
		for (int i = 0; i < N; i++)
			A[i].resize(N, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &A[i][j]);
			}
		}
		vector<vector<int>> B;
		B.resize(N);
		for (int i = 0; i < N; i++)
			B[i].resize(N, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &B[i][j]);
			}
		}
		vector<vector<int>> C;
		C.resize(N);
		for (int i = 0; i < N; i++)
		{
			C[i].resize(N);
		}
		SquareMatrixMultiply(A, B, C);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d ", C[i][j]);
			}
			printf("\n");
		}
		SquareMatrixMultiplyRecursive(A, { 0,N - 1,0,N - 1 }, B, { 0,N - 1,0,N - 1 }, C);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d ", C[i][j]);
			}
			printf("\n");
		}
		SquareMatrixMultiplyStrassen(A, { 0,N - 1,0,N - 1 }, B, { 0,N - 1,0,N - 1 }, C);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d ", C[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}