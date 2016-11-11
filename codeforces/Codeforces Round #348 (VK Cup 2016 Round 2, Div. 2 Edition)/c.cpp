#include <bits/stdc++.h>
using namespace std;
#define Max 110
int mp[Max][Max];
int n,m,q;
struct pt{
    int a,b,c,t;
}p[10010];
int main(){
    cin>>n>>m>>q;
    memset(mp,0,sizeof(mp));
    for(int i=1;i<=q;i++){
        int t;
        cin>>t;
        if(t==1){
            int b;
            cin>>b;
            p[i].t=t;
            p[i].a=b;
        }
        else if(t==2){
            int b;
            cin>>b;
            p[i].t=t;
            p[i].b=b;
        }
        else {
            int a,b,c;
            cin>>a>>b>>c;
            p[i].t=t;
            p[i].a=a;p[i].b=b;p[i].c=c;
        }
    }
    for(int i=q;i>=1;i--){

        if(p[i].t==1){
            int t=p[i].a;
            int temp=mp[t][m];
            for(int i=m;i>1;i--){
                mp[t][i]=mp[t][i-1];
            }
            mp[t][1]=temp;
        }
        else if(p[i].t==2){
            int t=p[i].b;
            int temp=mp[n][t];
            for(int i=n;i>1;i--){
                mp[i][t]=mp[i-1][t];
            }
            mp[1][t]=temp;
        }
        else {
            int x=p[i].a;
            int y=p[i].b;
            int z=p[i].c;
            mp[x][y]=z;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<mp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}






