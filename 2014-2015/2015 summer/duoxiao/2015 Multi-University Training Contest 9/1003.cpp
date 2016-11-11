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
#define N 101000
int res[N];
const int MAXN=350;
int prime[MAXN+1];
void getPrime()
{
    memset(prime,0,sizeof(prime));
    for (int i=2;i<=MAXN;i++){
        if (!prime[i]) prime[++prime[0]]=i;
        for (int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++){
            prime[prime[j]*i]=1;
            if (i%prime[j]==0) break;
        }
    }
}
int getFactors(long long x)
{
    long long tmp=x;
    for (int i=1;prime[i]<=tmp/prime[i];i++){
        if (tmp%prime[i]==0){
            return x/prime[i];
        }
    }
    if (tmp!=1){
            return 1;
    }
}
int main()
{
    getPrime();
    for(int i=2;i<=N;i++)
    {
        res[i]=res[i-1];
        res[i]+=getFactors(i);
    }
    int t;
    while(~scanf("%d",&t))
    {
        printf("%d\n",res[t]);
    }
    return 0;
}






