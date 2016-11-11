#include <iostream>

using namespace std;

int a[1000001];
int p[1000001];
int add[100001];

//8 3
//1 3 -1 -3 5 3 6 7

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    p[1]=a[1];int pos=0;add[1]=1;
    for(int i=2;i<=n;i++)
    {

        if(i<=k)
        {
            pos=i;
            for(int j=i-1;a[i]>=p[j]&&j>=1;j--)
            {
                pos=j+1;p[j+1]=p[j];add[j]=j+1;
            }
            p[pos+1]=p[pos];add[pos+1]=add[pos];
            if(pos!=i)
            {p[pos]=a[i];add[pos]=add[pos+1];}
            else {p[pos]=a[i];add[pos]=pos;}
            cout<<"add is"<<add[pos]<<endl;
        }
        if(i>k)
        {
            pos=i;
            for(int j=i-k;j<i;j++)
            {
                p[j]=p[j+1];
                add[j]=add[j+1];
            }
            for(int j=i-1;j>i-k&&a[i]>=p[j];j--)
            {
                pos=j+1;p[j+1]=p[j];add[j]=j+1;
            }
            p[pos]=a[i];add[pos]=i;
            //cout<<"this is"<<pos<<endl;
        }
    }
    for(int i=k;i<=n;i++) cout<<p[i-k+1]<<" ";cout<<endl;
    for(int i=k;i<=n;i++) cout<<p[i]<<" ";
    return 0;
}
