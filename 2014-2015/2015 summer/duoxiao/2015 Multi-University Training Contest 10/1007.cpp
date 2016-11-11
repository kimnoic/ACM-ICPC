#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define N 45000010
using namespace std;
int n,m,tot,top,sz;
int v[100010],num[200010],h[200010];
int flag[100010],A[100010],B[100010],K[100010],root[100010];
int sum[N],ls[N],rs[N];
int L[30],R[30],a,b;
int lowbit(int x)
{return x&(-x);}
int find(int x)
{
    int l=1,r=tot,mid;
    while(l<=r)
    {
         int mid=(l+r)>>1;
         if(h[mid]<x)l=mid+1;
         else r=mid-1;
        }
    return l;
}
void updata(int last,int l,int r,int &rt,int w,int x)
{
     rt=++sz;
     sum[rt]=sum[last]+x;ls[rt]=ls[last];rs[rt]=rs[last];
     if(l==r)  return;
     int mid=(l+r)>>1;
     if(w<=mid)  updata(ls[last],l,mid,ls[rt],w,x);
     else  updata(rs[last],mid+1,r,rs[rt],w,x);
}
int query(int l,int r,int k)
{
     if(l==r)  return l;
     int i,suml=0,sumr=0;
     for(i=1;i<=a;i++)  suml+=sum[ls[L[i]]];
     for(i=1;i<=b;i++)  sumr+=sum[ls[R[i]]];
     int mid=(l+r)>>1;
     if(sumr-suml>=k)
     {
         for(i=1;i<=a;i++)  L[i]=ls[L[i]];
         for(i=1;i<=b;i++)  R[i]=ls[R[i]];
         return query(l,mid,k);
     }
     else
     {
         for(i=1;i<=a;i++)  L[i]=rs[L[i]];
         for(i=1;i<=b;i++)  R[i]=rs[R[i]];
         return query(mid+1,r,k-(sumr-suml));
     }
}
int main()
{
    int s;
	scanf("%d",&n);
	//n=100000;
	for(int i=1;i<=n;i++)
	{
	    //v[i]=i;
	    scanf("%d",&v[i]);
	    num[++top]=v[i];
    }
    cin>>m;
    //m=100000;
    for(int i=1;i<=m;i++)
    {
        //s=i%2+1;
    	scanf("%d",&s);
    	scanf("%d%d",&A[i],&B[i]);
    	//A[i]=1;
    	//B[i]=n;
    	if(s==2){
                scanf("%d",&K[i]);
                //K[i]=i;
        flag[i]=1;}
    	else num[++top]=B[i];
    }
    sort(num+1,num+top+1);
    h[++tot]=num[1];
    for(int i=2;i<=top;i++)
       if(num[i]!=num[i-1])
          h[++tot]=num[i];
    for(int i=1;i<=n;i++)
    {
    	int t=find(v[i]);
    	for(int j=i;j<=n;j+=lowbit(j))
    	    updata(root[j],1,tot,root[j],t,1);
    }
    for(int i=1;i<=m;i++)
    	{if(flag[i])
    	{
    		a=0;b=0;A[i]--;
    		for(int j=A[i];j>0;j-=lowbit(j))
    		   L[++a]=root[j];
 		    for(int j=B[i];j>0;j-=lowbit(j))
 		       R[++b]=root[j];
            printf("%d\n",h[query(1,tot,K[i])]);
    	}
    	else
        {
             int t=find(v[A[i]]);
             for(int j=A[i];j<=n;j+=lowbit(j))
			     updata(root[j],1,tot,root[j],t,-1);
             v[A[i]]=B[i];
             t=find(B[i]);
             for(int j=A[i];j<=n;j+=lowbit(j))
                 updata(root[j],1,tot,root[j],t,1);
        }}
	return 0;
}
