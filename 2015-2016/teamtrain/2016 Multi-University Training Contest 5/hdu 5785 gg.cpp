#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<bitset>
#include<math.h>
#include<vector>
#include<string>
#include<stdio.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N=1000010;
const int mod=100000000;
const int MOD1=1000000007;
const int MOD2=1000000009;
const double EPS=0.00000001;
typedef long long ll;
const ll MOD=1000000007;
const int INF=1000000010;
const ll MAX=1ll<<55;
const double pi=acos(-1.0);
typedef double db;
typedef unsigned long long ull;
char s[2*N];
int p_ma[2*N];
void Manacher(char s[],int les) {
    int i,mx,id;
    for (i=les-1;i>=0;i--) {
        s[2*i+2]=s[i];s[2*i+3]='#';
    }
    mx=id=0;s[1]=s[2*les+2]='#';les=les<<1|1;
    for (i=1;i<=les;i++) {
        if (mx>i) p_ma[i]=min(p_ma[2*id-i],mx-i);
        else p_ma[i]=1;
        for (;i-p_ma[i]>0&&s[i-p_ma[i]]==s[i+p_ma[i]];p_ma[i]++);
        if (i+p_ma[i]>mx) mx=i+p_ma[i],id=i;
    }
}
int g[N],pre[N],suf[N];
int main()
{
    int i,len;
    ll ans;
    while (scanf("%s", s)!=EOF) {
        len=strlen(s);
        Manacher(s,len);
        for (i=1;i<=len;i++) g[i]=suf[i]=0;
        for (i=2;i<=2*len;i++){
        if (i&1) {
            g[i/2+p_ma[i]/2]++;g[i/2]--;
            suf[i/2+p_ma[i]/2]=(suf[i/2+p_ma[i]/2]+i/2-p_ma[i]/2+1)%MOD;
            suf[i/2]=(suf[i/2]-i/2-1)%MOD;
        } else {
            g[i/2+p_ma[i]/2-1]++;g[i/2-1]--;
            suf[i/2+p_ma[i]/2-1]=(suf[i/2+p_ma[i]/2-1]+i/2-p_ma[i]/2+1)%MOD;
            suf[i/2-1]=(suf[i/2-1]-i/2-1)%MOD;
        }
        cout<<i<<" "<<suf[2]<<endl;
        }
        for(i=0;i<=len;i++) {
            cout<<i<<" "<<g[i]<<" "<<suf[i]<<endl;
        }
        for (i=len-1;i;i--) suf[i]=(suf[i]+suf[i+1]+g[i+1])%MOD,g[i]+=g[i+1];

        for (i=1;i<=len;i++) g[i]=pre[i]=0;
        for (i=2;i<=2*len;i++)
        if (i&1) {
            g[i/2-p_ma[i]/2+1]++;g[i/2+1]--;
            pre[i/2-p_ma[i]/2+1]=(pre[i/2-p_ma[i]/2+1]+i/2+p_ma[i]/2)%MOD;
            pre[i/2+1]=(pre[i/2+1]-i/2)%MOD;
        } else {
            g[i/2-p_ma[i]/2+1]++;g[i/2+1]--;
            pre[i/2-p_ma[i]/2+1]=(pre[i/2-p_ma[i]/2+1]+i/2+p_ma[i]/2-1)%MOD;
            pre[i/2+1]=(pre[i/2+1]-i/2+1)%MOD;
        }
        for (i=2;i<=len;i++) pre[i]=(pre[i]+pre[i-1]-g[i-1])%MOD,g[i]+=g[i-1];
        for(i=0;i<=len;i++) {
            cout<<i<<" "<<pre[i+1]<<" "<<suf[i]<<endl;
        }
        for (ans=0,i=1;i<len;i++) ans=(ans+(ll)suf[i]*pre[i+1])%MOD;
        printf("%I64d\n", (ans+MOD)%MOD);
    }
    return 0;
}
