#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define Max 20010

int t1[Max],t2[Max],c[Max];
bool cmp(int *r,int a,int b,int l){
    return r[a]==r[b] && r[a+l]==r[b+l];
}
void da(int str[],int sa[],int rank[],int height[],int n,int m){
    int i,j,p,*x=t1,*y=t2;
    for(i=0;i<m;i++) c[i]=0;
    for(i=0;i<n;i++) c[x[i]=str[i]]++;
    for(i=1;i<m;i++) c[i]+=c[i-1];
    for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
    for(j=1;j<=n;j<<=1){
        p=0;
        for(i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<m;i++) c[i]=0;
        for(i=0;i<n;i++) c[x[y[i]]]++;
        for(i=1;i<m;i++) c[i]+=c[i-1];
        for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(i=1;i<n;i++) x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        if(p>=n) break;
        m=p;
    }
    int k=0;

    n--;
    for(i=0;i<=n;i++) rank[sa[i]]=i;
    for(i=0;i<n;i++){
        if(k) k--;
        j=sa[rank[i]-1];
        while(str[i+k]==str[j+k]) k++;
        height[rank[i]]=k;
    }
}
int r[Max];
int rank[Max],height[Max],sa[Max];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>r[i];
    for(int i=n-1;i>0;i--) r[i]=r[i]-r[i-1]+90;
    n--;
    for(int i=0;i<n;i++) r[i]=r[i+1];
    r[n]=0;
    da(r,sa,rank,height,n+1,200);

    for(int i=2;i<=n;i++) cout<<height[i]<<endl;
    return 0;
}
