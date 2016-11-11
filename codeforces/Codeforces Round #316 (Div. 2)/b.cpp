#include <bits/stdc++.h>
using namespace std;
long long m,n;
int main()
{
    cin>>n>>m;
    if(n==1)
    {
         cout<<"1";
         return 0;
    }
    if(m>n/2)cout<<m-1;
    else cout<<m+1;
    return 0;
}
