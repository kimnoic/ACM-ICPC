#include <bits/stdc++.h>
using namespace std;

const int maxn = 9000;
int a[maxn],l[maxn],r[maxn];
int mp[maxn*2];
int n;
int main(){
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            l[0]=0;r[0]=0;
            for(int j=1;j<=n;j++){
                l[j]=l[j-1];
                r[j]=r[j-1];
                if(a[j]>a[i]) r[j]++;
                if(a[j]<a[i]) l[j]++;
            }
            memset(mp,0,sizeof(mp));
            mp[0]=1;
            for(int j=1;j<i;j++){
                int temp=l[j]-r[j];
                if(temp>=0) mp[temp]++;
                else mp[8000+temp]++;
            }
            int ans=0;
            for(int j=i;j<=n;j++){
                int temp=l[j]-r[j];
                if(temp>=0) ans+=mp[temp];
                else ans+=mp[8000+temp];
            }
            if(i!=n)
                printf("%d ",ans);
            else printf("%d\n",ans);
        }
    }
    return 0;
}
