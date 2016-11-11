#include <bits/stdc++.h>
using namespace std;
#define Max 32
int c[Max][Max];
int a[Max];
int solve(int x,int k,int b){
    memset(a,0,sizeof(a));
    int len=0;
    int temp=x;
    while(temp){
        a[++len]=temp%b;
        temp/=b;
    }
    int sum=0,cnt=0;
    for(int i=len;i>=1;i--){
        if(a[i]>=2){
            sum+=c[i][k-cnt];
            break;
        }
        else if(a[i]==1){
            if(i>k-cnt)
                sum+=c[i-1][k-cnt];
            if(++cnt>k) break;
        }
        if((i!=1)&&k==cnt) sum++;
    }
    return sum;
}/*
int sove(int n,int k,int b){
    int bit[35]={0},len=0,t=n;
    while(t){
        bit[len++]=t%b;
        t/=b;
    }
    int sum=0,tot=0;
    for(int i=len-1;i>=0;i--){
        if(bit[i]>1){
            sum+=c[i+1][k-tot];
            break;
        }
        else if(bit[i]==1){
            if(i>=k-tot)  sum+=c[i][k-tot];
            if(++tot>k)  break;
        }
        if(!i&&tot==k)
            sum++;
    }
    return sum;
}*/
int x,y,k,b;
int main(){
    memset(c,0,sizeof(c));
    for(int i=0;i<=Max;i++){
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
    cin>>x>>y>>k>>b;
    cout<<solve(y,k,b)-solve(x-1,k,b);
    return 0;
}
