#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int f[10][10];int digit[9];
int cal(int n){
    int cnt=0;
    while(n){
        cnt++;
        n/=10;
    }
    return cnt;
}
void caldigit(int n,int len)//计算n的digit数组
{
    memset(digit,0,sizeof(digit)) ;
    for(int i=1 ;i<=len ;i++)
    {
        digit[i]=n%10 ;
        n/=10 ;
    }
}
int solve(int n)//计算[0,n]区间满足条件的数字个数
{
    int ans=0 ;
    int len=cal(n) ;
    caldigit(n,len) ;
    for(int i=len ;i>=1 ;i--)
    {
        for(int j=0 ;j<digit[i] ;j++)//枚举第i位取值
        {
            if(!(j==2 && digit[i+1]==6) && j!=4)//第i位满足条件
                ans+=f[i][j] ;
        }
        if(digit[i]==4 || (digit[i]==2 && digit[i+1]==6))//第i位已经不满足条件，则i位以后都不可能满足条件，结束循环
            break ;
    }
    return ans ;
}
int main(){
    f[0][0]=1;
    for(int i=1;i<=7;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                if(j!=4&&!(j==6&&k==2)){
                    f[i][j]+=f[i-1][k];
                }
            }
        }
    }
    int n,m;
    while(cin>>m>>n){
        if(m==0&&n==0) break;
        else cout<<solve(n+1)-solve(m)<<endl;
    }
    return 0;
}
