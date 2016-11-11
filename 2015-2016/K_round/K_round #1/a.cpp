#include <bits/stdc++.h>

using namespace std;
#define Max 100010
#define LL long long
int b[Max],g[Max];

bool cmp(int a,int b){
    return a>b;
}
int main(){
    //freopen("a.txt","r",stdin);
    int n,m;
    LL k;
    while(cin>>n>>m>>k){
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        for(int i=1;i<=m;i++)
            scanf("%d",&g[i]);
        sort(b+1,b+n+1,cmp);
        sort(g+1,g+m+1,cmp);
        LL l1=1ll*b[n]*g[m],r1=1ll*b[1]*g[1],mid1;
        LL ans=l1;
        while(l1<=r1){
            mid1=(l1+r1)/2;
            LL sum=0;
            for(int i=1;i<=n;i++){
                int l2=1,r2=m,mid2;
                LL t=0;
                while(l2<=r2){
                    mid2=(l2+r2)/2;
                    if(1ll*b[i]*g[mid2]>=mid1){
                        t=mid2;
                        l2=mid2+1;
                    }
                    else
                        r2=mid2-1;
                }
                sum+=t;
            }
            if(sum>=k){
                ans=mid1;
                l1=mid1+1;
            }
            else
            r1=mid1-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
