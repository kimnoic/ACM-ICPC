#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000010;
int top=0;
bool notprime[MAXN];//值为false 表示素数，值为true 表示非素数
int p[MAXN];
void init(){
    memset(notprime,false,sizeof(notprime));
    notprime[0]=notprime[1]=true;
    for(int i=2;i<MAXN;i++)
        if(!notprime[i]){
        if(i>MAXN/i)continue;
 //直接从i*i 开始就可以，小于i 倍的已经筛选过了, 注意是j+=i
        for(int j=i*i;j<MAXN;j+=i)
        notprime[j]=true;
    }
    memset(p,0,sizeof(p));
    for(int i=2;i<=MAXN;i++){
        if(!notprime[i]){
            p[++top]=i;
        }
    }
}
long long n;
int main(){
    init();
    cin>>n;
    int k=1;
    while(n>=(p[k]*p[k])&&k<=top){
        if(n%(p[k]*p[k])==0){
            n/=p[k];
        }
        else {
            k++;
        }
    }
    cout<<n;
    return 0;
}
