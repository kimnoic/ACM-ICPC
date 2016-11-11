#include <iostream>

using namespace std;

int maxx(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int number[1001][1001];
    int n;
int dp(int a,int b)
{
    if(a<n)
    return maxx(dp(a+1,b),dp(a+1,b+1))+number[a,b];
    else return  maxx(dp(a+1,b),dp(a+1,b+1));
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++) cin>>number[i][j];
    }
    cout<<dp(1,1);
    return 0;
}
