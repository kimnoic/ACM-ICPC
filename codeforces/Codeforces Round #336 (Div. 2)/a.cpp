#include<bits/stdc++.h>
using namespace std;
#define Max 1125
int m,n;
struct pt{
    int f,time;
}s[Max];
int ans=0,now=1;
bool cmp(pt a,pt b){
    return a.f>b.f;
}
int temp=0;
int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        scanf("%d%d",&s[i].f,&s[i].time);
    sort(s+1,s+m+1,cmp);
    while(n){
            temp++;
        while(n==s[now].f){
            ans=max(ans,s[now].time);
            now++;
            if(now==0)
                break;
        }
        ans++;
        n--;
    }
    printf("%d",ans);
    return 0;
}
