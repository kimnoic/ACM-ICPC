#include <bits/stdc++.h>
using namespace std;
int T;
int a[110],n,m,vis[110];
int v,id;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        for(int i=1;i<=m;i++) {
            scanf("%d%d",&id,&v);
            a[id]=v;
            vis[id]=1;
        }
        for(int i=n;i>=1;i--){
            if(!vis[i-1]) a[i-1]=a[i];
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=a[i];
        }
        if(n<=2){
            cout<<"1/1"<<endl;
            continue;
        }
        if(a[1]==0){
            cout<<"1/1"<<endl;
            continue;
        }
        int p=0,q=sum;
        if(vis[1]==1){
            if(vis[2]){
                p+=a[1];
                p+=a[2];
            }
            else {
                p+=a[1];
                p+=a[1];
                q+=(a[1]-a[2]);
            }
        }
        else {
            if(vis[2]){
                p+=100;
                p+=a[2];
                q+=(100-a[1]);
            }
            else {
                p+=200;
                q+=(100-a[1]);
                q+=(100-a[2]);
            }
        }
        int g=__gcd(p,q);
        cout<<p/g<<"/"<<q/g<<endl;
    }
    return 0;
}
