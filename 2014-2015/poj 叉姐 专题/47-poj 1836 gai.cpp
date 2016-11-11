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
double lis[Max],lds[Max];
int n;
int search_lis(double a[],int left,int right,double val)
{
    int mid=(left+right)/2;
    int r=right;int l=left;
    while(l<r)
    {
        if(a[mid]==val) return mid;
        else if(a[mid]>val)
        {
            r=mid;
            mid=(l+r)/2;
        }
        else
        {
            l=mid+1;
            mid=(l+r)/2;
        }
    }
    return l;
}

int search_lds(double a[],int left,int right,double val)
{
    int mid=(left+right)/2;
    int r=right;int l=left;
    while(l<r)
    {
        mid=(l+r)/2;
        if(a[mid]==val) return mid;
        else if(a[mid]<val)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return l;
}

int main()
{
    cin>>n;
    int res=0;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int m=1;m<=n;m++)
    {
        int len_lis=1;
        for(int i=1;i<=m;i++)
        {
            lis[len_lis]=23333;
            int k=search_lis(lis,1,len_lis,p[i]);
            if(k==len_lis) len_lis++;lis[k]=p[i];
        }
        len_lis--;
        int len_lds=1;
        lis[m]=233;
        for(int i=m+1;i<=n;i++)
        {
            lis[m+len_lds]=-1;
            int k=search_lds(lis,m,m+len_lds,p[i]);
            if(k==m+len_lds) {len_lds++;}lis[k]=p[i];
        }
        len_lds--;
        res=max(res,len_lis+len_lds);
    }
    cout<<n-res<<endl;
    return 0;
}
