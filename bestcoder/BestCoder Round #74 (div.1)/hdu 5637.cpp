#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 20
#define N 100010
const int MOD = 1e9+7;
queue<int >q;
int a[Max],n,m,h[N<<2];
void bfs(){
    memset(h,-1,sizeof(h));
    h[0]=0;
    while(!q.empty()) q.pop();
    int cur=0;
    q.push(0);
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            int t=temp^a[i];
            if(h[t]!=-1) continue;
            h[t]=h[temp]+1;
            q.push(t);
        }
        for(int i=0;i<=17;i++){
            int t=temp^(1<<i);
            if(h[t]!=-1) continue;
            h[t]=h[temp]+1;
            q.push(t);
        }
    }
}
int s,t;
long long ans,res;
int main(){
    int T;
    cin>>T;
    while(T--){
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        bfs();
        int c=0;
        while(m--){
            c++;
            scanf("%d%d",&s,&t);
            res=c*h[s^t];
            ans+=res;
            ans%=MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}
