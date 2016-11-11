#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
	int a,b,c;
	cin>>a>>b>>c;
	float t;
	t=sqrt(b*b-4*a*c);
	if(t==0)cout<<(-b/(2*a)) ;
	else if(t>0){
		cout<<(-b-t)/(2*a)<<" "<<(-b+t)/(2*a);
	}
	return 0;
}
