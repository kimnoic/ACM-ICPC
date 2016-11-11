#include <bits/stdc++.h>
using namespace std;
#define N 1000000
int num[N];
int n,m,k,res,last,len;
int main()
{
    cin>>n>>m;
    res=0;
    for(int i=0; i<m; ++i)
    {
        cin>>k;
        last=len=0;
        for(int i=0; i<k; ++i)
        {
            cin>>num[i];
            if(num[i]==last+1)
            {
                last++;
                len++;
            }
        }
        res=max(res,len);
    }
    cout<<(n-m-res+1)+(n-res);
    return 0;
}
