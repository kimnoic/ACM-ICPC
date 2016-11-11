#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define MOD 258280327
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    int n=233;
    int sum=0;
    int pre=0;
    for(int i=1;i<=2000;i++)
    {
        //sum=0;
        for(int j=1;j<=i;j++)
        {
            for(int k=1;k<=i;k++)
            {
                if(gcd(j,k)+j*k/gcd(j,k)>=i) sum++;
            }
        }
        cout<<i<<" "<<sum%MOD<<endl;
        pre=sum;
    }
    return 0;
}
