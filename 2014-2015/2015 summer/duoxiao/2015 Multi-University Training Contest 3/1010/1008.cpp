#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
long long l,r;
long long res;
long long MIN(long long a,long long b)
{
    if(a<b) return a;
    else return b;
}
void dfs(long long ll,long long rr)
{
    if(rr>=res||rr>2*r) return ;
    if(ll==0)
    {
        res=rr;
        return ;
    }

    long long len=rr-ll+1;
    if(ll-len>=0)
        dfs(ll-len,rr);
    if(ll-len>=1)
        dfs(ll-len-1,rr);
    dfs(ll,rr+len);
    dfs(ll,rr+len-1);
}
int main()
{
    while(~scanf("%lld%lld",&l,&r))
    {
        res=1e16;
        dfs(l,r);
        if(res==1e16) cout<<"-1"<<endl;
        else cout<<res<<endl;
    }
    return 0;
}
