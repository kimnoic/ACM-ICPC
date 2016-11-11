#include <bits/stdc++.h>
using namespace std;
#define Max 100010
set<int>s[Max];
int f[Max];
int n;int top;
set<int>::iterator it;
int res_a[Max],res_b[Max];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>f[i];
    for(int i=2;i<=n;i++){
        int a=1;
        int b=i;
        int cnt=0;
        while(cnt<n){
            it=s[a].find(b);
            if(it!=s[a].end()) break;
            it=s[b].find(a);
            if(it!=s[b].end()) break;
            top=0;
            res_a[++top]=a;
            res_b[top]=b;
            s[a].insert(b);
            s[b].insert(a);
            a=f[a];
            b=f[b];
            cnt++;
        }
        cout<<cnt<<endl;
        if(cnt==n-1){
            cout<<"YES"<<endl;
            for(int j=1;j<=top;j++) cout<<res_a[j]<<" "<<res_b[j]<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
