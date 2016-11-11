#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 5010
int p[Max][2];int e;char t1[Max],t2[Max];int n;
int main()
{

    while(cin>>n)
    {scanf("%s",t1+1);
    memset(p,0,sizeof(p));
    for(int i=1;i<=n;i++) t2[i]=t1[n+1-i];
    for(int i=1;i<=n;i++)
    {
        e=1-e;
        for(int j=1;j<=n;j++)
        {

            if(t1[i]==t2[j]) p[j][e]=p[j-1][1-e]+1;
            else p[j][e]=max(p[j-1][e],p[j][1-e]);
        }
    }
    cout<<n-p[n][e]<<endl;}
    return 0;
}
