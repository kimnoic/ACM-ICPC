#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
const double eps = 1e-5;
long long x,y;
int main()
{
	while(~scanf("%lld%lld",&x,&y))
	{
		if(x>y){
			printf("-1\n");
			continue;
		}
		double l=y*1.0/x-eps;
		double r=(y+1)*1.0/x;
		double a=1.0,b=1.0;
		for(long long i=0;;i++){
			if(a/b>=l&&a/b<r){
				printf("%d\n",i+x-(LL)b);
				break;
			}
			if(a/b<l){
				if((a+1)/b>=r){
					a+=a/b;
					b+=1;
				}
				else{
					if((a+(long long)(b*l-a+1))/b<r){
						i+=(long long)(b*l-a);
						a+=(long long)(b*l-a+1);
						continue;
					}
					if((a+(long long)(b*l-a))/b<r){
						i+=(long long)(b*l-a-1);
						a+=(long long)(b*l-a);
						continue;
					}
				}
			}
		}
	}
	return 0;
}
