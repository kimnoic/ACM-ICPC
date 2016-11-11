#include <bits/stdc++.h>
using namespace std;
int mp[1010];
int mpp[1010];
char st[1010][1010];
int n,m;
char t;
int main(){
    cin>>n>>m;
    int c=0,l=0;
    int flag=0;
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>t;
            st[i][j]=t;
            //cin>>st[i][j];
            if(t=='*'){
                mp[i]++;
                mpp[j]++;
                sum++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int k;
            if(st[i][j]=='*') k=1;
            else k=0;
            //if(i==3&&j==3) cout<<mp[i]<<" "<<mp[j]<<endl;
            if(mp[i]+mpp[j]==sum+k){
                cout<<"YES"<<endl;
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
    if(n>1&&m>1&&flag==0){
        cout<<"NO";
        return 0;
    }
    int ans=0,an=0,f=0,f2=0;
    int p1=0,p2=0;
    for(int i=1;i<=n;i++){
        if(mp[i]){
            if(mp[i]>ans){
                p1=i;
                ans=mp[i];
                f=1;
            }
            else if(mp[i]==ans&&ans!=0){
                f++;
            }
        }
        if(mpp[i]){
            if(mpp[i]>an){
                p2=i;
                an=mpp[i];
                f2=1;
            }
            else if(mpp[i]==an&&an!=0){
                f2++;
            }
        }
    }
    if(f<=1||f2<=1){
        cout<<"YES"<<endl;
        cout<<p1<<" "<<p2;
    }
    else cout<<"NO";
    return 0;
}
