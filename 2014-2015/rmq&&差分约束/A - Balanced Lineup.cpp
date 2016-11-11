#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int cow[50001];
int n,q;
int minn[50001][21],maxx[50001][21];

int min(int a,int b)
{
    if(a>b) return b;
    else return a;
}

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}

void searchmin()
{
    for(int i=1;i<=n;i++) minn[i][0]=cow[i];
    int sum=log((double)(n+1))/log(2.0);
    for(int j=1;j<=sum;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
            minn[i][j]=min(minn[i][j-1],minn[i+(1<<(j-1))][j-1]);
    }
}



void searchmax()
{
    for(int i=1;i<=n;i++) maxx[i][0]=cow[i];
    int sum=log((double)(n+1))/log(2.0);
    for(int j=1;j<=sum;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            maxx[i][j]=max(maxx[i][j-1],maxx[i+(1<<(j-1))][j-1]);//cout<<"maxx is"<<i<<" "<<j<<" "<<maxx[i][j]<<endl;
        }
    }
}


int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) scanf("%d",&cow[i]);
    int l,r;
    searchmin();searchmax();
    for(int i=1;i<=q;i++)
    {
        cin>>l>>r;
        int k=(int)(log((double)(r-l+1))/log(2.0));
        printf("%d\n",max(maxx[l][k],maxx[r-(1<<k)+1][k])-min(minn[l][k],minn[r-(1<<k)+1][k]));
    }
    return 0;
}
