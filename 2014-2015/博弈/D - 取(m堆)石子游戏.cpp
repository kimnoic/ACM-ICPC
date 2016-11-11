#include <iostream>
using namespace std;
#define N 200010
int a[N],b[N],c[N];

int main()
{
    int n,cnt;
    while(cin>>n&&n!=0)
    {
        int ans=0;
        int s=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            s^=a[i];
        }
        cout<<s;
        if(s==0) cout<<"No"<<endl;
        else
        {
        	for(int i=0;i<n;i++)
        {
            if(a[i]>(s^a[i]))
            {
                b[ans]=a[i];
                c[ans]=s^a[i];
                ans++;
            }
        }
        cout<<"Yes"<<endl;
		for(int i=0;i<ans;i++)
			cout<<b[i]<<" "<<c[i]<<endl;
        }
    }

    return 0;
}
