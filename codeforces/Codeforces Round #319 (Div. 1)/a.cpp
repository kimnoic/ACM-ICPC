#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN=1010;
bool notprime[MAXN];//ֵΪfalse ��ʾ������ֵΪtrue ��ʾ������
void init(){
    memset(notprime,false,sizeof(notprime));
    notprime[0]=notprime[1]=true;
    for(int i=2;i<MAXN;i++)
    if(!notprime[i]){
    for(int j=i*i;j<MAXN;j+=i)
    notprime[j]=true;
    }
}
int k[MAXN];
int t;
int main(){
    cin>>n;
    init();
    int top=0;
    for(int i=2;i<=n;i++){
        if(!notprime[i]){
                t=i;
            while(t<=n){
                k[++top]=t;
                t*=i;
            }
        }
    }
    cout<<top<<endl;
    for(int i=1;i<=top;i++){
        cout<<k[i]<<" ";
    }
    return 0;
}
