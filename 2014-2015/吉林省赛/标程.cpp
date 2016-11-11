#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
#define Max 233
int main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int k=sqrt(n);
        if(k%2==0)
        printf("0\n");
        else printf("1\n");
    }
    return 0;
}
