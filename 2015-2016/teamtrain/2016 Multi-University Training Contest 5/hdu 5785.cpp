#include <bits/stdc++.h>
const int maxn=1000010;
const int mod=1000000007;
char s[maxn],ma[maxn*2];
int mp[maxn*2];
void manacher(char s[],int len){
    int l=0;
    ma[l++]='$';
    ma[l++]='#';
    for(int i=0;i<len;i++){
        ma[l++]=s[i];
        ma[l++]='#';
    }
    ma[l]=0;
    int mx=0,id=0;
    for(int i=0;i<l;i++){
        mp[i]=mx>i?std::min(mp[2*id-i],mx-i):1;
        while(ma[i+mp[i]]==ma[i-mp[i]]) mp[i]++;
        if(i+mp[i]>mx){
            mx=i+mp[i];
            id=i;
        }
    }
}
int g[maxn],sum[maxn],pre[maxn];
int main(){
    while(~scanf("%s",s)){
        int len=strlen(s);
        manacher(s,len);
        memset(g,0,sizeof(g));
        memset(sum,0,sizeof(sum));
        for(int i=2;i<=2*len;i++){
            if(i&1){
                g[i/2+mp[i]/2]++;
                g[i/2]--;
                sum[i/2+mp[i]/2]=(sum[i/2+mp[i]/2]+i/2-mp[i]/2+1)%mod;
                sum[i/2]=(sum[i/2]-i/2-1)%mod;
            }
            else {
                g[i/2+mp[i]/2-1]++;
                g[i/2-1]--;
                sum[i/2+mp[i]/2-1]=(sum[i/2+mp[i]/2-1]+i/2-mp[i]/2+1)%mod;
                sum[i/2-1]=(sum[i/2-1]-i/2-1)%mod;
            }
        }
        for(int i=len-1;i>0;i--){
            sum[i]=(sum[i]+sum[i+1]+g[i+1])%mod;
            g[i]+=g[i+1];
        }
        memset(g,0,sizeof(g));
        memset(pre,0,sizeof(pre));
        for(int i=2;i<=2*len;i++){
            if(i&1){
                g[i/2-mp[i]/2+1]++;
                g[i/2+1]--;
                pre[i/2-mp[i]/2+1]=(pre[i/2-mp[i]/2+1]+i/2+mp[i]/2)%mod;
                pre[i/2+1]=(pre[i/2+1]-i/2)%mod;
            }
            else {
                g[i/2-mp[i]/2+1]++;
                g[i/2+1]--;
                pre[i/2-mp[i]/2+1]=(pre[i/2-mp[i]/2+1]+i/2+mp[i]/2-1)%mod;
                pre[i/2+1]=(pre[i/2+1]-i/2+1)%mod;
            }
        }
        for(int i=2;i<=len;i++) pre[i]=(pre[i]+pre[i-1]-g[i-1])%mod,g[i]+=g[i-1];
        long long ans=0;
        for(int i=1;i<len;i++){
            ans=(ans+(long long)sum[i]*pre[i+1])%mod;
        }
        printf("%I64d\n",(ans+mod)%mod);
    }
    return 0;
}
