#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main()
{
	int s,d;
	int res;
	while(cin>>s>>d)
	{
        if(4*s<d)
		{
			res=10*s-2*d;
		}
		else if(3*s<2*d)
		{
			res=8*s-4*d;
		}
		else if(2*s<3*d)
		{
			res=6*s-6*d;
		}
		else if(s<4*d)
		{
			res=3*s-9*d;
		}
		else res=-1;
		if(res>0) cout<<res<<endl;
		else cout<<"Deficit"<<endl;
	}
	return 0;
}
