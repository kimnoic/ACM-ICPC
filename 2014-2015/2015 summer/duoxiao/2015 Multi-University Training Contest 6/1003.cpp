#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
int T;
int n,m;
int b[233];
vector<int>a[15];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        long long res=(n+1)*n/2;
        if(res%m!=0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        for(int i=1;i<=m;i++)
            a[i].clear();
            int flag=1;
        for(int i=n%(2*m)+2*m+1;i<=n&&i<n-i;i++)
        {
            a[flag].push_back(i);
            a[flag].push_back(n-i);
            flag++;
            if(flag==m+1) flag=1;
        }
        int sum=0;
        int len=n%(2*m)+2*m;
        len=min(len,n);
        for(int i=1;i<=len;i++)
        {
            sum+=i;
            b[i]=1;
        }
        int val=sum/m;
        int y=m;
        for(int i=1;i<=m;i++)
        {
            int sum=0;
            while(sum!=val)
            {
                int s=val-sum;int pos=len;
                while(!b[pos])
                {
                    pos--;
                }
                if(s<pos)
                {
                    pos=s;
                    while(!b[pos])
                    {
                        pos--;
                    }
                    sum+=pos;
                    b[pos]=0;
                    a[i].push_back(pos);
                    continue;
                }
                sum+=pos;
                b[pos]=0;
                a[i].push_back(pos);

            }
        }
        for(int i=1;i<=m;i++)
        {
            int l=a[i].size();
            cout<<l;
            for(int j=0;j<l;j++)
            {
                printf(" %d",a[i][j]);
            }
            cout<<endl;
        }
    }
    return 0;
}
