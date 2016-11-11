#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <set>
#include <math.h>
using namespace std;
#define N 100010
int b[N],n;
long long f(int i,int j)
{
    cout<<i<<" "<<j<<endl;
    if(i==1&&j==1) return 0;
    long long sum1=f(i-1,j);
    long long sum2=f(i,(j+1)/2)+b[i];
    return min(sum1,sum2);
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>b[i];
        cout<<f(n,1)<<endl;
    }
    return 0;
}
