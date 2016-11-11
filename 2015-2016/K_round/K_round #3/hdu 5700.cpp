#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
long long sum[maxn];
int a[maxn],l,r,n,m,k;
multiset<int>st;
vector<int>vc[maxn];
int main(){
    while(~scanf("%d%d%d",&n,&k,&m)){
        for(int i=0;i<=n;i++) vc[i].clear();
        memset(sum,0,sizeof(sum));
        st.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum[i]+=sum[i-1];
            sum[i]+=a[i];
        }
        int cnt=0;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&l,&r);
            cnt=max(cnt,l);
            vc[l].push_back(r);
        }
        long long ans=0;
        for(int i=1;i<=cnt;i++){
            for(int j=0;j<vc[i].size();j++){
                st.insert(vc[i][j]);
            }
            while(st.size()>k){
                st.erase(st.begin());
            }
            if(st.size()==k&&*st.begin()>=i){
                ans=max(ans,sum[*st.begin()]-sum[i-1]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
