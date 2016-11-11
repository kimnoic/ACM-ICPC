#include <iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b&&(a!=0&&b!=0))
	{
		if(a%2==0||b%2==0) cout<<"Wonderful!"<<endl;
		else cout<<"What a pity!"<<endl;
	}
}
