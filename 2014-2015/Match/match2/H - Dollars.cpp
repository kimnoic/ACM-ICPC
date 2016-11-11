#include <iostream>
#include<string.h>
using namespace std;

double n;
long long dp[30001][13];
int coin[12]={5,10,20,50,100,200,500,1000,2000,5000,10000};

int judge(double a)
{
    if(((int)a)/10==0) return 4;
    else return judge(a/10)+1;
}

int judge2(long long a)
{
    if(a/10==0) return 1;
    else return judge2(a/10)+1;
}

long long search(int all,int num)
{
    if(num==0)   return 1;
    if(dp[all][num]!=-1)  return dp[all][num];  dp[all][num]=0;
    for(int i=0;i<=all/coin[num];i++)   dp[all][num]+=search(all-i*coin[num],num-1);
    return dp[all][num];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    while(cin>>n&&n!=0.00)
    {
        for(int i=1;i<=6-judge(n);i++) cout<<" ";cout<<n;double r=n;r=r*10;
        if(n==(int)n) cout<<".00";
        else if((n-(int)n)<1.00&&r==(int)r) cout<<"0";
        n=(n+0.005)*100;
        long long s=search(n,10);
        for(int i=1;i<=17-judge2(s);i++) cout<<" ";
        cout<<s<<endl;
    }
    return 0;
}
