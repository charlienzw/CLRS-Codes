#include <bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int> &A)
{
    for(int j=1;j<A.size();j++)
    {
        int key=A[j];
        int i=j-1;
        while(i>=0&&A[i]>key)
        {
            A[i+1]=A[i];
            i=i-1;
        }
        A[i+1]=key;
    }
}

int main()
{
    int N;
    while(scanf("%d",&N) != EOF)
    {
        vector<int> A(N);
        for (int i=0;i<A.size();i++)
            scanf("%d",&A[i]);
        InsertionSort(A);
        for (int i=0;i<A.size();i++)
            printf("%d ",A[i]);
        printf("\n");
    }
    return 0;
}
