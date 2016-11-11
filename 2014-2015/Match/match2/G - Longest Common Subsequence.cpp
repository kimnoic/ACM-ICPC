#include <iostream>
#include <string.h>
using namespace std;

string s1,s2;
int leng1,leng2;
int dp[1001][1001]={};

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}

void search(int a,int b)
{
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
}

int main()
{
    while (getline(cin,s1)&&getline(cin,s2))
    {
        leng1=s1.size();
        leng2=s2.size();
        memset(dp,0,sizeof(dp));
        search(leng1,leng2);
        cout<<dp[leng1][leng2]<<endl;
    }
    return 0;
}
