#include <bits/stdc++.h>
using namespace std;
#define Max 1000010
int s[Max],a[Max],n;
struct pt{
    int p,d,vis;
}c[100010];
int d[100010];
bool cmp(pt a,pt b){
    return a.p<b.p;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&c[i].p,&c[i].d);
        s[c[i].p]=1;
        a[c[i].p]=1;
    }
    sort(c+1,c+n+1,cmp);
    for(int i=1;i<=Max;i++){
        s[i]+=s[i-1];
    }
    int sum=n;
    for(int i=1;i<=n;i++){
        d[i]=1;
        int t=c[i].p-c[i].d;
        d[i]+=d[s[t-1]];
        sum=min(sum,n-d[i]);

    }
    cout<<sum<<endl;
    return 0;
}
