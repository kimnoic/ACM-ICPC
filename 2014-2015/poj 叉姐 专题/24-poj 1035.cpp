#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
char word[10010][20];
int len[10010];
char tmp[233];
int fab(int a,int b)
{
	if(a-b<=1&&b-a<=1) return 1;
	else return 0;
}
int main()
{
	int top=1;
	while(scanf("%s",word[top]))
	{
		if(word[top][0]=='#') break;
		len[top]=strlen(word[top]);
		top++;
	}
	top--;
	while(scanf("%s",tmp))
	{
		if(tmp[0]=='#') break;
		int flag=0;
		for(int i=1;i<=top;i++)
		{
			if(strcmp(tmp,word[i])==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			cout<<tmp<<" is correct"<<endl;
			continue;
		}
		cout<<tmp<<":";
		int leng=strlen(tmp);
        for(int i=1;i<=top;i++)
		{
			if(fab(leng,len[i]))
			{
				int cnt=0;
				int pos;
				for(int j=0;j<leng;j++)
				{
                    if(tmp[j]!=word[i][j])
					{
						pos=j;
						cnt++;
						break;
					}
				}

				if(len[i]>leng)
				{
					for(int j=pos;j<leng;j++)
					{
						if(tmp[j]!=word[i][j+1])
						{
							cnt++;
							break;
						}
					}
				}
				else if(len[i]<leng)
				{
					for(int j=pos+1;j<leng;j++)
					{
						if(tmp[j]!=word[i][j-1])
						{
							cnt++;
							break;
						}
					}
				}
				else
				{
					for(int j=pos+1;j<leng;j++)
					{
						if(tmp[j]!=word[i][j])
						{
							cnt++;
							break;
						}
					}
				}
				if(cnt<=1)
				{
					cout<<" "<<word[i];
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
