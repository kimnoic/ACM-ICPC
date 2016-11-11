#include <iostream>
using namespace std;
int main()
{
	double a1,b1;
	cin>>a1>>b1;
	int p=(double)(a1*100+0.5);
	int q=(double)(b1*100+0.5);
	for (int i = 1; ; i++)
		{
         int a = p * i / 10000;
         int b = q * i / 10000;
	//cout<<a<<" "<<b<<endl;
         if ((a < b) && (q * i % 10000 > 0)) {
             cout << i << endl;
             return 0;
         }}
	return 0;
}
