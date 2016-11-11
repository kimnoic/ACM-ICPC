#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	long long n,a,b,sr,snow,an,bn,ans,ansnow,ansl,ansr,num;
	cin>>n>>a>>b;
	sr=6*n;
	if(a*b>=sr) {cout<<a*b<<endl<<a<<" "<<b;return 0;}
	ans=1e20;
	an=a;
	bn=b;
	bn=sr/an;
	if(bn*an!=sr)bn++;
	ansnow=bn*an;
	if(ansnow<ans){ans=ansnow;ansl=an;ansr=bn;}
	an=a;
	bn=b;an=sr/bn;
	if(an*bn!=sr) an++;
	ansnow=an*bn;
	if(ansnow<ans)
	{
		ans=ansnow;ansl=an;ansr=bn;
	}
	an=a;
	bn=b;
	num=(long long)((long long)sqrt((long long)(a+b)*(a+b)+(long long)a*b-sr)-(a+b))/(long long)2;
	an+=num;
	bn+=num;
	ansnow=bn*an;
	while(ansnow<sr){an+=1;bn+=1;ansnow=an*bn;};
	if(ansnow<ans){ans=ansnow;ansl=an;ansr=bn;}
	cout<<ans<<endl;
	cout<<ansl<<" "<<ansr;
	return 0;
}
