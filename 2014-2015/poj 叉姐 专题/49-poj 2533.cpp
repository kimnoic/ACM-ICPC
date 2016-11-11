#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
int p[1023];
int lis[1023],n;
int search_lis(int a[],int left,int right,int val)
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
        res=max(res,len_lis);
    }
    cout<<res;
    return 0;
}
