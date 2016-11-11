#include <iostream>
using namespace std;
int n,m;
void work()
{
    n=n/2;m=m/2;
}
int main()
{
    int t;
    cin>>t;
    int casew=1;
    while(t--)
    {
        cin>>n>>m;
                cout<<"Case #"<<casew<<": ";casew++;
        int sum=n*m;
        work();
        int ana=n*m/2;
        if((n*m)%2) ana ++;
        ana=ana*4;
        int bob=sum-ana;
        if(bob>ana)cout <<"Bob"<<endl;
        else if(ana==bob) cout<<"Draw"<<endl;
        else cout<<"Ana"<<endl;
    }

    return 0;
}
