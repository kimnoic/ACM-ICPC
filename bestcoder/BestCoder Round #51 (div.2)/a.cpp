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

int i,j,m,n,k,T;

int modular_multi(int x,int y,int mo)
{
    int t;
    x%=mo;
    for(t=0;y;x=(x<<1)%mo,y>>=1)
        if (y&1)
            t=(t+x)%mo;
    return t;
}

int modular_exp(int num,int t,int mo)
{
    int ret=1,temp=num%mo;
    for(;t;t>>=1,temp=modular_multi(temp,temp,mo))
        if (t&1)
            ret=modular_multi(ret,temp,mo);
    return ret;
}
const int S=3;
bool miinter_rabbin(int n)
{
    if (n==2)return true;
    if (n<2||!(n&1))return false;
    int t=0;
    int a,x,y,u=n-1;
    while((u&1)==0) t++,u>>=1;
    for(int i=0;i<S;i++)
    {
        a=rand()%(n-1)+1;
        x=modular_exp(a,u,n);
        for(int j=0;j<t;j++)
        {
            y=modular_multi(x,x,n);
            if (y==1&&x!=1&&x!=n-1)
                return false;
            x=y;
        }
        if (x!=1)
            return false;
    }
    return true;
}

int main(int argc, const char * argv[])
{
    cin>>T;
    int y=1;
    while (T--)
    {
        cin>>n;
        y++;
        if (n==4) printf("2\n");
        else if (miinter_rabbin(n))
            printf("%d\n",n-1);
        else printf("0\n");
    }
    return 0;
}
