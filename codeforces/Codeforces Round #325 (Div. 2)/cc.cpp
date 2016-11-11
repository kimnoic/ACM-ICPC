#include<bits/stdc++.h>
using namespace std;
const int Max = 100010;
struct self
{
    int p,v,d,q;
}s[Max];
int n,flag[Max],f[Max],ans;
int w=0;
void c(int red,int l){
    f[l]=1;
    for(int i=l+1;i<=n;i++){
        s[i].p-=red;
        if(s[i].p<0 &&!f[i]){
            f[i]=1;
            red+=s[i].d;
            w++;
        }
    }
}
void r(int k,int l){
    for(int i=l;i<=n;i++){
        s[i].p-=k;
        if(s[i].p<0 && !f[i])
            c(s[i].d,i);
        k--;
        w--;
        if(k==0)break;
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].v>>s[i].d>>s[i].p;
    }

    for(int i=1;i<=n;i++)
        if(s[i].p>=0){
            flag[i]=1;
            r(s[i].v,i+1);
        }
    for(int i=1;i<=n;i++)
        if(flag[i])
            ans++;
    printf("%d\n",ans);
    w++;
    for(int i=1;i<=n;i++)
        if(flag[i])
        cout<<i<<" ";
    return 0;
}
