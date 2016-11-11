#include <bits/stdc++.h>
using namespace std;
#define Max 200010
int v[Max],vis[Max];
int n;
int a,b,c;
int p[10],pp[10];
int main(){
    cin>>n;
    memset(vis,0,sizeof(vis));
    cin>>a>>b>>c;
    int aa=max(max(a,b),c);
    int cc=min(min(a,b),c);
    p[2]=(a+b+c)-aa-cc;
    p[1]=cc,p[3]=aa;
    p[4]=p[1]+p[2];
    p[5]=p[1]+p[3];
    p[6]=p[2]+p[3];
    p[7]=p[1]+p[2]+p[3];
    int sum=p[7];
    sort(p+1,p+8);
    for(int i=1;i<=n;i++) cin>>v[i];
    sort(v+1,v+n+1);
    int cnt=1;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(v[i]<=p[cnt]){
            pp[cnt]=i;
        }
        else {
            i--;
            cnt++;
        }
    }
    cnt=6;
    memset(vis,0,sizeof(vis));
    if(v[n]>sum){
        cout<<-1;
        return 0;
    }
    for(int i=n;i>=1;i--){
        if(!pp[cnt]){
            cnt--;
            continue;
        }
        if(i<=max(pp[1],max(pp[2],pp[3]))) break;
        if(vis[i]) continue;
        //cout<<i<<" "<<ans<<" "<<cnt<<" "<<p[cnt]<<endl;
        if(v[i]>=p[cnt]){
            ans++;
            vis[i]=1;
            if(v[i]>p[cnt]) continue;
            int tem=0;
            for(int i=1;i<=3;i++){
                if((sum-p[cnt])==p[i]) {
                    tem=i;
                    break;
                }
            }
            //cout<<"tem"<<" "<<tem<<endl;
            int pos=pp[tem];
            while(pos>0){
                if(!vis[pos]){
                    vis[pos]=1;
                    pp[tem]=pos;
                    break;
                }
                pos--;
            }
        }
        else{
            cnt--;
            i++;
            if(cnt<3) break;
        }
    }
    int s=0;
    int rc=1;
    int ccc[5];
    memset(ccc,0,sizeof(ccc));
    //cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(v[i]<=p[rc]){
                ccc[rc]++;
            }
            else {
                rc++;
                i--;
            }
        }
    }
    ans+=max(ccc[3],max((ccc[2]+ccc[3]+1)/2,(ccc[1]+ccc[2]+ccc[3]+2)/3));
    cout<<ans;
    return 0;
}
