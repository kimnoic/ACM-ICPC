#include<bits/stdc++.h>
using namespace std;
#define Max 666
#define N 0x3f3f3f3f
int fff[Max][Max],s[Max];
int n;
int cal(int l,int r){
    if(l>r)
        return 1;
    if(fff[l][r]!=-1)
        return fff[l][r];
    fff[l][r]=N;
    if(s[l]==s[r])
        fff[l][r]=min(fff[l][r],cal(l+1,r-1));
    for(int i=l;i<r;i++)
        fff[l][r]=min(fff[l][r],cal(l,i)+cal(i+1,r));
    return fff[l][r];
}
int main(){
    memset(fff,-1,sizeof(fff));
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    int cnt=0;
    for(int i=1;i<=n;i++)
        {fff[i][i]=1;cnt++;}
    if(cnt==n)
        cout<<cal(1,n)<<endl;
    return 0;
}
