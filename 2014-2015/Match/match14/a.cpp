#include <iostream>
#include <string.h>

#define N 1000000007

using namespace std;
string s;
long long int sum = 0;
int main()
{
    int t;
    cin>>t;
    int casew=0;
    while(t--)
    {
        casew++;
        cin>>s;sum=0;
        int tt=s.size();
        int l=(tt-1)/2;
        int r=tt/2;
        if(l==r)
          {
              sum=(int)s[r]-48;
              l--;r++;
          }
          for(;l>=0&&r<tt;l--,r++)
        {
            if((int)s[l]>(int)s[r])
            {
                sum =(sum*2+(int )s[l]-48)%N;
                sum =(sum*2+(int)s[r] -48)%N;
            }
          else
           {
                sum =(sum*2+(int)s[r]-48)%N;
                sum =(sum*2+(int)s[l]-48)%N;
           }
        }
        sum=sum%N;
        cout<<"Case #"<<casew<<": "<<sum<<endl;
    }
}
