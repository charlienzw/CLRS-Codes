#include <bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int> &A)
{
    for (int j=0;j<A.size()-1;j++)
    {
        int min_index=j;
        for (int i=j+1;i<A.size();i++)
        {
            if (A[i]<A[min_index])
            {
                min_index=i;
            }
        }
        int tmp=A[j];
        A[j]=A[min_index];
        A[min_index]=tmp;
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
        SelectionSort(A);
        for (int i=0;i<A.size();i++)
            printf("%d ",A[i]);
        printf("\n");
    }
    return 0;
}
