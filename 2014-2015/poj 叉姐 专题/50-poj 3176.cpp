#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 2333
int mp[Max][Max],n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            cin>>mp[i][j];
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=i+1;j++)
        {
            mp[i][j]+=max(mp[i+1][j],mp[i+1][j+1]);
        }
    }
    cout<<mp[1][1]<<endl;
    return 0;
}
