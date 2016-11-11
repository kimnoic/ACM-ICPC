#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <stack>
#include <set>
#include <map>
using namespace std;
char mp[55][55];
int n,len;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",mp[i]);
            len=strlen(mp[i]);
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<len;j++)
            {
                if(mp[i][j]=='G')
                {
                    int a=i,b=j;
                    while(mp[a][b]!='B'&&mp[a][b]!='.'&&a>=1&&a<=n&&b>=0&&b<len)
                    {
                        if(mp[a][b]=='G') mp[a][b]='B';
                        else mp[a][b]='.';
                        a-=1;b-=1;
                    }
                    a=i+1;b=j+1;
                    while(mp[a][b]!='B'&&mp[a][b]!='.'&&a>=1&&a<=n&&b>=0&&b<len)
                    {
                        if(mp[a][b]=='G') mp[a][b]='B';
                        else mp[a][b]='.';
                        a++;b++;
                    }
                    cnt++;
                    a=i;b=j;
                    while(mp[a][b]!='R'&&mp[a][b]!='.'&&a>=1&&a<=n&&b>=0&&b<len)
                    {
                        if(mp[a][b]=='G') mp[a][b]='R';
                        else mp[a][b]='.';
                        a-=1;b+=1;
                    }
                    a=i+1;b=j-1;
                    while(mp[a][b]!='R'&&mp[a][b]!='.'&&a>=1&&a<=n&&b>=0&&b<len)
                    {
                        if(mp[a][b]=='G') mp[a][b]='R';
                        else mp[a][b]='.';
                        a+=1;b-=1;
                    }
                    cnt++;
                }
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=0;j<len;j++)
        {
            if(mp[i][j]=='R')
            {
                int a=i,b=j;
                while(mp[a][b]!='B'&&mp[a][b]!='.'&&a>=1&&a<=n&&b>=0&&b<len)
                {
                    mp[a][b]='.';
                    a++;
                    b++;
                }
                a=i-1;b=j-1;
                while(mp[a][b]!='B'&&mp[a][b]!='.'&&a>=1&&a<=n&&b>=0&&b<len)
                {
                    mp[a][b]='.';
                    a--;
                    b--;
                }
                cnt++;
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=0;j<len;j++)
        {
            if(mp[i][j]=='B')
            {
                int a=i,b=j;
                while(mp[a][b]!='R'&&mp[a][b]!='.'&&a>=1&&a<=n&&b>=0&&b<len)
                {
                    mp[a][b]='.';
                    a++;
                    b--;
                }
                a=i-1;b=j+1;
                while(mp[a][b]!='R'&&mp[a][b]!='.'&&a>=1&&a<=n&&b>=0&&b<len)
                {
                    mp[a][b]='.';
                    a--;
                    b++;
                }
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
