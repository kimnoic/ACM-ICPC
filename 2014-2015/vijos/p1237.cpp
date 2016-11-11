#include <iostream>
#include <algorithm>
using namespace std;

#define ans 0.6180339887498949;

double judge(double a,double b)
{
    double c=(a/b)-ans;
    if(c>=0) return c;
    else return -c;
}

int main()
{
    int n;
    cin>>n;
    float wing[30010];
    for(int i=1;i<=n;i++) cin>>wing[i];
    sort(wing+1,wing+n+1);
    int t=1;
    int a,b;
    for(int i=1;i<n;i++)
    {
        int low=i,head=n,mid=(low+head)/2;
        //cout<<"mid is"<<mid<<endl;
        while (low<head)
        {
            if(judge(wing[i],wing[mid])>judge(wing[i],wing[head]))
            {
                    low=mid;
                    //cout<<low<<" %% "<<endl;
            }
            else head=mid;
        }
        if(judge(wing[i],wing[mid])<t) {t=judge(wing[i],wing[mid]);a=i;b=mid;
        //cout<<a<<"----"<<endl;
        }
    }
    cout<<a<<endl<<b;
    return 0;
}
