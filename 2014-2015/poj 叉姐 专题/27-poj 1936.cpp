#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define Max 100010
char t1[Max],t2[Max];
int al[233];
int bl[233];
int main()
{
	while(~scanf("%s%s",t1,t2))
	{
		int l1=strlen(t1);
		int l2=strlen(t2);
		int flag=0;
		long long pos_1=0,pos_2=0;
		while(1)
		{
			if(pos_1==l1)
			{
				flag=1;
				break;
			}
			else if(pos_2==l2&&pos_1!=l1)
			{
				break;
			}
			if(t1[pos_1]==t2[pos_2])
			{
				pos_1++;
				pos_2++;
			}
			else pos_2++;
		}
		if(!flag) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
