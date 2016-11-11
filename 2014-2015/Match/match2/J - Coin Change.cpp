#include <iostream>

using namespace std;

int main()
{
    int n;
    for(int i=1;i<=7489;i++)
    {
        long long ans=0;
        int a=i/50;
        for(int a1=a;a1>=0;a1--)
        {
            int b=(i-a1*50)/25;
            for(int b1=b;b1>=0;b1--)
            {
                int c=(i-a1*50-b1*25)/10;
                for(int c1=c;c1>=0;c1--)
                {
                    int d=(i-a1*50-b1*25-c1*10)/5;
                    for(int d1=d;d1>=0;d1--) ans++;
                }
            }
        }
        cout<<ans<<",";
    }
    return 0;
}
