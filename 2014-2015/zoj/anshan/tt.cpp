#include <iostream>
#include <math.h>
using namespace std;
int a[11]={0,1,4,6,9,13,16,19,28,40,100};
int n;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=10;i++)
		{
			if(n>=a[i]&&n<=a[i+1]) cout<<a[i]<<" "<<n<<" ";
			else cout<<a[i]<<" ";
		}
	return 0;
}
