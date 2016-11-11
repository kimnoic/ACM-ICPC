#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 233
const int MOD = 1e9+7;
int n;
int a[Max];
char b[Max];
int f[Max][Max];int l,r,k;

long long check(char t,int a,int b)
{
    if(t=='+') return a+b;
    else if(t=='-') return a-b;
    else if(t=='*') return a*b;
}

int cal[Max];int c[Max][Max];
void init()
{
    cal[0]=1;
    cal[1]=1;
    int k=1;
    while(k<102)
    {
        k++;
        cal[k]=cal[k-1]*k;
        cal[k]%=MOD;
    }
    c[1][0]=c[1][1]=1;
    for(int i=2;i<=100;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0) c[i][j]=1;
            else c[i][j]=c[i-1][j]+c[i-1][j-1];
            c[i][j]%=MOD;
        }
    }
}


int main()
{
    init();
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        scanf("%s",b+1);
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++) f[i][i]=a[i];
        for(int top=1;top<n;top++)
        {
            for(int j=1;j+top<=n;j++)
            {
                l=j;
                r=j+top;
                for(k=l;k<r;k++)
                {
                    f[l][r]+=check(b[k],f[l][k],f[k+1][r])*c[l-k+1][r-l+1];
                    if(f[l][r]>0) f[l][r]%=MOD;
                    //cout<<f[l][k]<<" "<<b[k]<<" "<<f[k+1][r]<<" = "<<f[l][r]<<"   "<<l<<" "<<r<<endl;
                }
            }
        }
        if(f[1][n]<0) f[1][n]+=MOD;
        cout<<f[1][n]<<endl;
    }
    return 0;
}
