#include <bits/stdc++.h>
using namespace std;
int n,m;
#define Max 100010
int a[Max],f[Max],b[Max];
int res[Max],p[Max];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&f[i]);
        res[f[i]]++;
        p[f[i]]=i;
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
    }
    int flag =0;
    for(int i=1;i<=m;i++){
        if(!res[b[i]]){
            cout<<"Impossible";
            return 0;
        }
        else if(res[b[i]]>1){
            flag=1;
        }
        else {
            a[i]=p[b[i]];
        }
    }
    if(flag){
        cout<<"Ambiguity";
        return 0;
    }
    cout<<"Possible"<<endl;
    for(int i=1;i<=m;i++) cout<<a[i]<<" ";
    return 0;
}
