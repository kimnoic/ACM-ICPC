#include <bits/stdc++.h>
using namespace std;
#define Max 100010
struct pt{
    int val,flag,pro;
}p[Max];
bool cmp(pt a,pt b){
    return pt.a<pt.b;
}
int m,n;
int f[Max],g[Max];
int main(){
    cin>>n>>m;
    memset(p,0,sizeof(p));
    for(int i=1;i<=m;i++){
        cin>>p[i].val;
        cin>>p[i].flag;
        p[i].pro=i;
    }
    sort(p+1,p+m+1,cmp);
    int flag=0;
    int cnt=1,num=0,tm,maxx,tmp;
    int sum=0;
    for(int i=1;i<=m;i++){
        tm=num;
        if(p[i].flag){
            f[i]=1;
            g[i]=++cnt;
            num++;
        }
        if(tm!=num&&num>=2){
            sum+=(num-1);
            continue;
        }
        if(sum==0&&!p[i].flag){
            flag=1;
            break;
        }

    }
    return 0;
}
