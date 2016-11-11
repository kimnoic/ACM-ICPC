#include <iostream>
using namespace std;
#define Max 233
int main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(n%2) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
