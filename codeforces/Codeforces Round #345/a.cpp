#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <time.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
#define Max 200010
struct pt{
    int x,y;
}p[Max];
int n;
int x,y;
int cnt;
bool cmp1(pt a,pt b){
    return a.x<b.x;
}
bool cmp2(pt a,pt b){
    return a.y<b.y;
}
bool cmp3(pt a,pt b){
    if(a.x==b.x) return a.y<b.y;
    else return a.x<b.x;
}
void init(){
    cin>>n;
    cnt=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        p[++cnt].x=x;
        p[cnt].y=y;
    }
}
long long ans,res;
void solve(){
    ans=0;
    res=1;
    sort(p+1,p+n+1,cmp1);
    int tx=p[1].x;
    for(int i=2;i<=n;i++){
        if(p[i].x==tx){
            res++;
        }
        else {
            tx=p[i].x;
            ans+=(long long)(res*(res-1)/2);
            res=1;
        }
    }
    if(res!=1){
        ans+=(long long)(res*(res-1)/2);
    }
    res=1;
    sort(p+1,p+n+1,cmp2);
    int ty=p[1].y;
    for(int i=2;i<=n;i++){
        if(p[i].y==ty){
            res++;
        }
        else {
            ty=p[i].y;
            ans+=(long long)(res*(res-1)/2);
            res=1;
        }
    }
    if(res!=1){
        ans+=(long long)(res*(res-1)/2);
    }
    sort(p+1,p+n+1,cmp3);
    tx=p[1].x,ty=p[1].y;
    res=1;
    for(int i=2;i<=n;i++){
        if(p[i].x==tx&&p[i].y==ty){
            res++;
        }
        else {
            ty=p[i].y;
            tx=p[i].x;
            ans-=(long long)(res*(res-1)/2);
            res=1;
        }
    }
    if(res!=1){
        ans-=(long long)(res*(res-1)/2);
    }
}
int main(){
    init();
    solve();
    cout<<ans;
    return 0;
}
