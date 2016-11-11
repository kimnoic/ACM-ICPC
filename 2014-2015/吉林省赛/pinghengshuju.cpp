#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;
#define Max 233
int main()
{
    int T=1000,n;
    //freopen("10.in","r",stdin);
    freopen("2.in","w",stdout);
    srand(time(NULL));
    cout<<T<<endl;
    while(T--)
    {
        long long res=(long long)rand()*rand()*rand()%1000000+1;
        cout<<res<<endl;
    }
    return 0;
}
