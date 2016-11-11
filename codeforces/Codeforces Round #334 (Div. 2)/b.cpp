#include<bits/stdc++.h>
using namespace std;
#define Max 100010

int f[Max],g[Max];
int flag[Max];
int m,n;
int l,r,mid,ans;

bool judge(int u){
    memset(flag,0,sizeof(flag));
    int ret=0;
    int l=1,r=m;
    int q=0;
q++;
    while(r>=1 && l<=m && l<=r){
        while(l<=m && flag[l]==1)
            l++;
        if(l>m)
            return ret<=n;
        while(r>=1 && flag[r]==1)
            r--;
        if(r<1)
            return ret<=n;
        if(f[l]+f[r]<=u){
            ret++;
            if(ret>n)
                return 0;
            flag[l]=1;
            flag[r]=1;
            l++;
            r--;
            q++;
        }
        else{
            ret++;
            flag[r]=1;
            r--;
        }
    }
    return ret<=n;
}
int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        scanf("%d",&f[i]);
    }
    sort(f+1,f+m+1);
    for(int i=1;i<=m;i++)
        g[m-i+1]=f[i];
    l=f[m];
    r=f[m]*2;
    int y;
    ans=f[m];
    while(l<=r){
        mid=(l+r)/2;
        if(judge(mid)){
            ans=mid;
            r=mid-1;
            y=0;
        }
        else
            l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
