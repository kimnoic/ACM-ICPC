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
#define Max 10010

double cal(char a[]){
	if(!strcmp(a, "A")) return 4.0;
	else if(!strcmp(a, "A-")) return 3.7;
	else if(!strcmp(a, "B+")) return 3.3;
	else if(!strcmp(a, "B")) return 3.0;
	else if(!strcmp(a, "B-")) return 2.7;
	else if(!strcmp(a, "C+")) return 2.3;
	else if(!strcmp(a, "C")) return 2.0;
	else if(!strcmp(a, "C-")) return 1.7;
	else if(!strcmp(a, "D")) return 1.3;
	else if(!strcmp(a, "D-")) return 1.0;
	else if(!strcmp(a, "F")) return 0;
	else if(!strcmp(a, "P")) return -1;
	else if(!strcmp(a, "N")) return -1;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		char fun[5];
		double cre, sum=0, ans=0;
		while(n--){
			scanf("%lf %s", &cre, fun);
			if(func(fun)!=-1){
				sum+=cre;
				ans+=(fun)*cre;
			}
		}
		if(sum==0)printf("0.00\n");
		else printf("%.2lf\n", ans/sum);
	}
	return 0;
}
