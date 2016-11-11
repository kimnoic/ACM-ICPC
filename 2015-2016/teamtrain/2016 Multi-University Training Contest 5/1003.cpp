#include <bits/stdc++.h>
const int maxn=1e6+10;
int a[maxn];
long long sum[maxn];
long long st;

int n,ans;
int main(){
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int flag=0;
        ans=0;
        st=0;
        for(int i=n;i>=1;i--){
            if(!flag){
                if(a[i]>=0) ans++;
                else {
                    st=(long long)-a[i];
                    flag=1;
                }
            }
            else {
                if(a[i]>0){
                    st-=(long long)a[i];
                    if(st<=0){
                        flag=0;
                        ans++;
                    }
                }
                else {
                    st+=(long long)(-a[i]);
                }
            }
        }
        std::cout<<ans<<std::endl;
    }
    return 0;
}
