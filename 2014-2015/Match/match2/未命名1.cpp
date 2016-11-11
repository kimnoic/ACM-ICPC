#include <iostream>
#include<string.h>
using namespace std;

int n;
int dp[7500][6];
int coin[5]={1,5,10,25,50};

int judge(double a)
{
    if(((int)a)/10==0) return 4;
    else return judge(a/10)+1;
}

int search(int all,int num)
{
    if(num==0)   return 1;
    if(dp[all][num]!=-1)  return dp[all][num];  dp[all][num]=0;
    for(int i=0;i<=all/coin[num];i++)   dp[all][num]+=search(all-i*coin[num],num-1);
    return dp[all][num];
}
int main()
{
    cout<<judge(4.00)<<endl;
    memset(dp,-1,sizeof(dp));
    while(cin>>n)  cout<<search(n,4)<<endl;
    return 0;
}
