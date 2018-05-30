#include <bits/stdc++.h>
using namespace std;

void BinaryAdd(vector<int> A, vector<int> B, vector<int> &C)
{
    // A.size()=B.size()
    // C.size()=A.size()+1
    int tmp=0;
    for(int i=C.size()-1;i>0;i--)
    {
        C[i]=(A[i-1]+B[i-1]+tmp)%2;
        tmp=(A[i-1]+B[i-1]+tmp)/2;
    }
    C[0]=tmp;
}

int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        vector<int> A(N);
        vector<int> B(N);
        for (int i=0;i<N;i++)
        {
            scanf("%d",&A[i]);
        }
        for (int i=0;i<N;i++)
        {
            scanf("%d",&B[i]);
        }
        vector<int> C(N+1);
        BinaryAdd(A,B,C);
        for (int i=0;i<C.size();i++)
        {
            printf("%d ",C[i]);
        }
    }
}
