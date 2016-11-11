#include <iostream>
#include <cmath>
using namespace std;
long long H(long long n){
    if(n<=0)return 0;
      long long res =n;
      long long i,pre=n,tmp;
      for(i=2;i<=n;i++)
        {
            res+=(tmp=n/i);
            if(tmp!=pre)
                {
                    res+=(n/tmp-i)*(tmp);
                    i=n/tmp;
                    pre=tmp;
                }

        }
     return res;
}
int main()
{
    long long n,t;
    cin>>t;
    while(t--)cin>>n,cout<<H(n)<<endl;
    return 0;
}
