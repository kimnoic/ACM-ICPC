#include<bits/stdc++.h>
using namespace std;
int m,n;
#define Max 100100
struct pt{
    int val,flag,pro;
}p[Max];
int cnt=0;
int l[Max],r[Max],ans[Max];
int now,st;
bool cmp(pt a,pt b){
    if(a.val==b.val){
        if(a.flag==b.flag){
                return a.pro<b.pro;
            }
        else
            return a.flag>b.flag;
    }
    else
        return a.val<b.val;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&p[i].val,&p[i].flag);
        p[i].pro=i;
    }
    now=1;st=2;
    ans[1]=1;
    sort(p+1,p+m+1,cmp);
    int flag=0;
    for(int i=1;i<=m;i++){
        if(p[i].flag==1){
            now++;
            ans[now]=1;
            cnt++;
            r[p[i].pro]=now;
            l[p[i].pro]=1;
            ans[now]=now;
            st=2;
        }
        else{
            jmp:
            while(ans[st]>now && st<=now) st++;
            if(st>now){
                flag=1;
                break;
            }
            else{
                ans[st]++;
                if(ans[st]==st) ans[st]++;
                cnt-=2;
                if(ans[st]>now)
                    goto jmp;
                r[p[i].pro]=ans[st];
                l[p[i].pro]=st;
                if(ans[st]>now)
                    st++;
            }
        }
    }
    if(flag){
        cout<<"-1";
        cnt++;
    }
    else{
        for(int i=1;i<=m;i++)
            printf("%d %d\n",l[i],r[i]);
    }
    return 0;
}
