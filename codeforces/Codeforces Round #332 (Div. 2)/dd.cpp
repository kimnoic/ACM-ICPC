#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
long long m;
#define Max 1743000
long long x,y;
struct pt{
    long long x,y;
}s[Max];
int top=0;
long long n,sum[Max],t[Max];
int k=0;
long long cal(int a,long long tot){
    k=0;
    long long ret=a,l=a,r=tot,mid,q=(long long)tot-sum[a],p=t[a];
    while(l<=r){
        k=1;
        mid=(l+r)/2;
        if((q/p+1>=mid-a)&&(mid-a)*p<=q){
            l=mid+1;
            ret=mid;
        }
        else{
            r=mid-1;
        }
    }
    if(q==p*(ret-a))
        return ret;
    else
        return -1;
}
int main(){
    cin>>m;
    for(int i=1;;i++){
        sum[i]=(long long)sum[i-1]+(long long)i*i;
        t[i]=(long long)t[i-1]+(long long)i;
        if(sum[i]>m){
            n=i;
            break;
        }
    }
    for(int x=1;;x++){
        if(sum[x]>m)
            break;
        y=cal(x,m);
        if(y!=-1){
            s[++top].y=y;
            s[top].x=x;

        }

    }
    int flag=0;
    if(s[top].x==s[top].y){
            cout<<top*2-1<<endl;
            flag=1;
        }
    else
        cout<<top*2<<endl;
    for(int i=1;i<=top;i++){
        printf("%I64d %I64d\n",s[i].x,s[i].y);
    }
    for(int i=top;i>=1;i--){
        if(i==top&&flag) continue;
        printf("%I64d %I64d\n",s[i].y,s[i].x);
    }
    return 0;
}
// 1000000000000000000
