#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include <bits/stdc++.h>
#define maxv 50000
#define ll long long
using namespace std;

int n,k;
vector<int> G[maxv+50];
ll val[maxv+50];
ll prime[maxv+50];
ll convert_three(ll v){
    ll bas=1;ll res=0;
    for(int i=0;i<k;++i){
        int num=0;
        while(v%prime[i]==0){
            v/=prime[i];
            num++;
        }
        num%=3;res+=num*bas;
        bas*=3;
    }
    return res;
}

ll xr(ll x,ll y){
    ll res=0;ll bas=1;
    for(int i=0;i<k;++i){
        res+=((x%3)+(y%3))%3*bas;
        x/=3;y/=3;
        bas*=3;
    }
    return res;
}

ll inv(ll x){
    ll res=0;ll bas=1;
    for(int i=0;i<k;++i){
        res+=((3-(x%3))%3)*bas;
        x/=3;
        bas*=3;
    }
    return res;
}

void print(ll x){
    while(x){
        cout<<x%3;
        x/=3;
    }
    cout<<endl;
}

bool centroid[maxv+50];
int ssize[maxv+50];
int ans;

map<ll,int> sta;
map<ll,int>::iterator it;
int compute_ssize(int v,int p)
{
    int c=1;
    for(int i=0;i<G[v].size();++i){
        int w=G[v][i];
        if(w==p||centroid[w]) continue;
        c+=compute_ssize(G[v][i],v);
    }
    ssize[v]=c;
    return c;
}

pair<int,int> search_centroid(int v,int p,int t)
{
    pair<int,int> res=make_pair(INT_MAX,-1);
    int s=1,m=0;
    for(int i=0;i<G[v].size();++i){
        int w=G[v][i];
        if(w==p||centroid[w]) continue;
        res=min(res,search_centroid(w,v,t));
        m=max(m,ssize[w]);
        s+=ssize[w];
    }
    m=max(m,t-s);
    res=min(res,make_pair(m,v));
    return res;
}

void enumerate_mul(int v,int p,ll d,map<ll,int> &ds)
{
    if(ds.count(d)) ds[d]++;
    else ds[d]=1;
    for(int i=0;i<G[v].size();++i){
        int w=G[v][i];
        if(w==p||centroid[w]) continue;
        enumerate_mul(w,v,xr(d,val[w]),ds);
    }
}

void solve(int v)
{
    compute_ssize(v,-1);
    int s=search_centroid(v,-1,ssize[v]).second;
    centroid[s]=true;
    //cout<<s<<endl;
    for(int i=0;i<G[s].size();++i){
        if(centroid[G[s][i]]) continue;
        solve(G[s][i]);
    }
    sta.clear();
    sta[val[s]]=1;map<ll,int> tds;
    for(int i=0;i<G[s].size();++i){

        if(centroid[G[s][i]]) continue;std:cout<<"v"<<" "<<G[s][i]<<std::endl;
        tds.clear();
        enumerate_mul(G[s][i],s,val[G[s][i]],tds);
        it=tds.begin();
        while(it!=tds.end()){
            ll rev=inv((*it).first);
            if(sta.count(rev)){
                ans+=sta[rev]*(*it).second;
            }
            ++it;
        }
        std::cout<<ans<<std::endl;
        it=tds.begin();
        while(it!=tds.end()){
            ll  vv=xr((*it).first,val[s]);
            if(sta.count(vv)){
                sta[vv]+=(*it).second;
            }
            else{
                sta[vv]=(*it).second;
            }
            ++it;
        }
    }
    centroid[s]=false;
}

int main()
{
    //freopen("in.txt","r",stdin);
    while(cin>>n>>k){
        ans=0;
        for(int i=0;i<k;++i){
            scanf("%I64d",&prime[i]);
        }
        G[0].clear();
        for(int i=1;i<=n;++i){
            scanf("%I64d",&val[i]);
            val[i]=convert_three(val[i]);
            if(val[i]==0) ans++;
            //print(val[i]);
            G[i].clear();
        }
        int u,v;
        for(int i=0;i<n-1;++i){
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        memset(centroid,0,sizeof(centroid));
        solve(1);
        printf("%d\n",ans);
    }
    return 0;
}
