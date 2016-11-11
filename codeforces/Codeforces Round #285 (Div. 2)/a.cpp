#include <iostream>
using namespace std;
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int e=max(3*a/10,a-a/250*c);
	int f=max(3*b/10,b-b/250*d);
	if(e>f) cout<<"Misha";
	else if(e<f) cout<<"Vasya";
	else cout<<"Tie";
	return 0;
}
