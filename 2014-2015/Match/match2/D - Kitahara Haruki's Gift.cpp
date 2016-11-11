#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a=0,b=0;
    int t;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        if(t==100) a++;
        else b++;
    }
    int sum=a+b*2;
    if(sum%2==0&&((sum/2)%2==0||((sum/2)%2==1&&a!=0))) cout<<"YES";
    else cout<<"NO";
    return 0;
}
