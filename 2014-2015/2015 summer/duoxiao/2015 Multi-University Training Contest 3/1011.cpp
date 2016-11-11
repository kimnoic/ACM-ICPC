#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <stack>
#include <set>
#include <map>
using namespace std;
int n,k;
int fa[233],p[233];
int main()
{
    while(cin>>n>>k)
    {
        for(int i=1;i<=n;i++) p[i]=1;
        for(int i=1;i<=n;i++) fa[i]=i;
        int a,b;
        for(int i=1;i<n;i++)
        {
            cin>>a>>b;
            fa[b]=a;
            int t=a;
            while(fa[t]!=t)
            {
                p[t]+=p[b];
                t=fa[t];
            }
            p[t]+=p[b];
        }
        int cnt=0;
        for(int i=1;i<=n;i++) if(p[i]==k+1) cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}
