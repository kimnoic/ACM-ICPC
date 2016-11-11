#include<bits/stdc++.h>
using namespace std;
const int lim = 100010;
int m,n;
int up[lim],down[lim],f[lim],totup[lim],totdown[lim],s[lim],ans,home;
int we=0;
int main(){
    cin>>m;
    for(int i=2;i<=m;i++)
    {
        cin>>up[i];
        totup[i]=totup[i-1]+up[i];
    }
    for(int i=2;i<=m;i++){
        cin>>down[i];
        we++;
    }
    for(int i=m;i>=1;i--)
        totdown[i]=totdown[i+1]+down[i+1];
    for(int i=1;i<=m;i++)
        cin>>s[i];
    we--;
    for(int i=1;i<=m;i++)
        f[i]=totup[i]+s[i]+totdown[i];
    sort(f+1,f+m+1);
    we=3;
    cout<<f[1]+f[2]<<endl;
    return 0;
}
