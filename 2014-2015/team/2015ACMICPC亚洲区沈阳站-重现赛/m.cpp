#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 1001000
#define INF 999999999999
vector<int>p[Max],h[Max],a_1;
long long val[Max];
int vis[Max],vis_1[Max];
int fa[Max];
long long cnt_1[Max],cnt_2[Max];
#define M 922337203685
long long sum;
int T,n,k;
long long find(int r){
    if(fa[r]!=r){
        return (long long)val[r]+find(fa[r]);
    }
    else return val[r];
}

int main(){
    cin>>T;
    int _case=0;
    while(T--){
        cin>>n>>k;
        memset(vis_1,0,sizeof(vis_1));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
        for(int i=1;i<=n;i++){
            cnt_1[i]=cnt_2[i]=M;
        }
        for(int i=1;i<=n;i++){
            h[i].clear();
        }
        for(int i=1;i<=k;i++){
            p[i].clear();
            int c,m,temp;
            scanf("%d%d",&c,&m);
            val[i]=c;
            for(int j=1;j<=m;j++){
                scanf("%d",&temp);
                p[i].push_back(temp);
                h[temp].push_back(i);
            }
        }
        cout<<"Case #"<<++_case<<": ";
        a_1.clear();
        a_1.push_back(1);
        int cnt=1;
        vis_1[1]=1;
        cnt_1[1]=0;

        while(cnt<=n){
            int tem=0;
            sum=INF;
            for(int i=0;i<a_1.size();i++){
                int q=a_1[i];
                for(int j=0;j<h[q].size();j++){
                    int r=h[q][j];
                    if(vis[r]) continue;
                    long long f=find(r);
                    if(f<=sum&&(!vis_1[r])){
                        sum=f;
                        tem=r;
                        fa[r]=q;
                    }
                }
            }
            if(tem==0) {
                break;
            }
            for(int i=0;i<p[tem].size();i++){
                cnt_1[p[tem][i]]=min(cnt_1[fa[tem]]+sum,cnt_1[p[tem][i]]);
            }
            vis[tem]=1;
            for(int i=0;i<p[tem].size();i++){
                if(!vis_1[p[tem][i]]){
                    vis_1[p[tem][i]]=1;
                    a_1.push_back(p[tem][i]);
                }
            }
            cnt++;
        }

        if(cnt<n){
            cout<<"Evil John"<<endl;
            continue;
        }

        cnt=1;
        a_1.clear();
        a_1.push_back(n);
        memset(vis_1,0,sizeof(vis_1));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
        vis_1[n]=1;

        cnt_2[n]=0;
        while(cnt<=n){
            int tem=0;
            sum=INF;
            int last=0;
            for(int i=0;i<a_1.size();i++){int q=a_1[i];
                for(int j=0;j<h[q].size();j++){int r=h[q][j];
                    if(vis[r]) continue;
                    long long f=find(r);
                    if(f<=sum&&(!vis_1[r])){
                        sum=f;
                        tem=r;
                        fa[r]=q;
                    }
                }
            }
            for(int i=0;i<p[tem].size();i++){
                cnt_2[p[tem][i]]=min(cnt_2[fa[tem]]+sum,cnt_2[p[tem][i]]);
            }

            if(tem==0) break;
            vis[tem]=1;
            for(int i=0;i<p[tem].size();i++){
                if(!vis_1[p[tem][i]]){
                    vis_1[p[tem][i]]=1;
                    a_1.push_back(p[tem][i]);
                }
            }
            cnt++;
        }
        long long maxx=M;
        for(int i=1;i<=n;i++){
            cnt_1[i]=max(cnt_1[i],cnt_2[i]);
            maxx=min(maxx,cnt_1[i]);
        }
        cout<<maxx<<endl;
        for(int i=1;i<=n;i++){
            if(cnt_1[i]==maxx){
                printf("%d ",i);
            }
        }
        cout<<endl;
    }
    return 0;
}
/*
123
3 3
7 2 1 2
7 2 2 3
12 3 1 2 3
*/
