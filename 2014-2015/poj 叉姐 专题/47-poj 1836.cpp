#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 1024
double p[Max];
int d1[Max],d2[Max],n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    int res=0;d1[1]=1;
        d2[1]=1;
    for(int i=1;i<=n;i++)
    {
        int m=0;
        for(int j=1;j<i;j++)
        {
            if(p[j]<p[i]&&m<d1[j]) m=d1[j];
        }
        d1[i]=m+1;
    }
    for(int i=n;i>=1;i--)
    {
        int m=0;
        for(int j=n;j>i;j--)
        {
            if(p[j]<p[i]&&m<d2[j]) m=d2[j];
        }
        d2[i]=m+1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        res=max(res,d1[i]+d2[j]);
    }
    cout<<n-res<<endl;
    return 0;
}
