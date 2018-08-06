#include <bits/stdc++.h>
using namespace std;

int Euclid(int a, int b)
{
	if (b == 0)
		return a;
	else
		return Euclid(b, a%b);
}

int Euclid_iter(int a, int b)
{
	int tmp;
	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

void ExtendedEuclid(int a, int b,int &d,int &x,int &y,vector<vector<int> >&res)
{
	if (b == 0)
	{
		d = a;
		x = 1;
		y = 0;
		vector<int> tmp;
		tmp.push_back(d);
		tmp.push_back(x);
		tmp.push_back(y);
		res.push_back(tmp);
	}
	else
	{
		int d_, x_, y_;
		ExtendedEuclid(b, a%b,d_,x_,y_,res);
		d=d_;
		x=y_;
		y=x_ - a / b * y_;
		vector<int> tmp;
		tmp.push_back(d);
		tmp.push_back(x);
		tmp.push_back(y);
		res.push_back(tmp); 
	}
}

int Euclid_mul(vector<int> A)
{
	int res = A[0];
	for (int i = 1; i < A.size(); i++)
	{
		res = Euclid(A[i], res);
	}
	return res;
}

int lcm(vector<int> A)
{
	int res = A[0];
	for (int i = 1; i < A.size(); i++)
	{
		res = (A[i] * res) / Euclid(A[i], res);
	}
	return res;
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n",Euclid(a, b));
	printf("%d\n", Euclid_iter(a, b));
	vector<vector<int> > res;
	int d, x, y;
	ExtendedEuclid(a, b,d,x,y,res);
	for (int i = res.size()-1; i>=0; i--)
	{
		for (int j = 0; j < res[0].size(); j++)
		{
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	int n;
	scanf("%d", &n);
	vector<int> A(n);
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);
	printf("%d\n",Euclid_mul(A));
	printf("%d\n", lcm(A));
	system("pause");
	return 0;
}