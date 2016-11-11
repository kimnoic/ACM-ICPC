#include <iostream>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <string.h>
#include <map>
#include <stdlib.h>
using namespace std;
bool solve(int k,int m)
{
    int start = 0,end = k - 1;
    bool flag = true;
    for(int i=2*k;i>k;i--)
    {
        int kill = (m-1)%i;
        if(kill>=start && kill<=end)
        {
            flag = false;
            break;
        }
        start = ((start - m)%i+i)%i;
        end = ((end - m)%i+i)%i;
    }
    return flag;
}
int kk[15];
int main()
{
	int k;
	for(int i=1;i<14;i++)
	{
		for(int m=i+1;;m++)
			if(solve(i,m))
		{
			kk[i]=m;
			break;
		}
	}
	while(cin>>k)
	{
		if(k==0) break;
		cout<<kk[k]<<endl;
	}
	return 0;
}
