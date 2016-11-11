#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int inf=0x3f3f3f3f;

int conc[201]={},price[201]={};
int min(int a,int b)
{
    if(a>b) return b;
    else return a;
}

int sum[20001][21];

int main()
{
    int n;int ans=0;
    while (cin>>n)
    {
        if(ans!=0) cout<<endl;
        ans=1;
        int mmax=0;
    for(int i=1;i<=n;i++)
        {
            cin>>conc[i]>>price[i];
        }
    memset(sum,inf,sizeof(sum));
    sum[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=20000;j>=conc[i];j--)
        {
            for(int k=1;k<=min(n,20);k++)
            {
                if(sum[j-conc[i]][k-1]!=inf)
                    sum[j][k]=min(sum[j][k],sum[j-conc[i]][k-1]+price[i]);
            }
        }
    }
    int c;
    cin>>c;
    for(int i=1;i<=c;i++)
    {
        int number,minn,maxx;
        cin>>number>>minn>>maxx;
        int Min=inf;
        for(int j=number*minn;j<=number*maxx;j++)
            {
                Min=min(Min,sum[j][number]);
            }
        if(Min!=inf) cout<<Min<<endl;
        else cout<<"impossible"<<endl;
    }
    }
    return 0;
}
