#include <bits/stdc++.h>
using namespace std;
long long n,m,res;

bool vis2[10],vis1[10];
int a,b;
void dfs2(int cnt,long long ans,int cnt2){
    if(ans>m)
        return ;
    if(cnt==cnt2){
        res++;
    }
    else {
        for(int i=0;i<7;i++){
            if(!vis2[i]){
                vis2[i]=1;
                dfs2(cnt+1,ans*7+i,cnt2);
                vis2[i]=0;
            }

        }
    }
}
void dfs1(int cnt,long long ans,int cnt1){
    if(ans>n)
        return ;
    if(cnt==cnt1){
        //memset(vis2,0,sizeof(vis2));
        for(int i=0;i<7;i++){
            vis2[i]=vis1[i];
        }
        dfs2(0,0,b);
    }else {
        for(int i=0;i<7;i++){
            if(!vis1[i]){
                vis1[i]=1;
                dfs1(cnt+1,ans*7+i,cnt1);
                vis1[i]=0;
            }
        }
    }
}

int main() {
    cin>>n>>m;
    n--;
    m--;
    long long temp;
    temp=n;
    while(temp){
        temp/=7;
        a++;
    }
    temp=m;
    while(temp){
        temp/=7;
        b++;
    }
    a=max(1,a);
    b=max(1,b);
    if(a+b<=7)
        dfs1(0,0,a);
    cout<<res;
    return 0;
}
