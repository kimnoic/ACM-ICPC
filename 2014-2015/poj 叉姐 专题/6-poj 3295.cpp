#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stack>

using namespace std;
stack <int >stk;
char tp[233];
int p,q,r,s,t;
int ta,tb;
char k='0';
int len;
void judge(char t)
{
	if(t=='p') stk.push(p);
	else if(t=='q') stk.push(q);
	else if(t=='r') stk.push(r);
	else if(t=='s') stk.push(s);
	else if(t=='t') stk.push(t);
}
bool getSult()
{
    int a,b;
    for(int i=len-1;i>=0;i--)
    {
        switch(tp[i])
        {
            case 'K':
                a=stk.top();
                stk.pop();
                b=stk.top();
                stk.pop();
                stk.push(a&&b);
                break;
            case 'A':
                a=stk.top();
                stk.pop();
                b=stk.top();
                stk.pop();
                stk.push(a||b);
                break;
            case 'N':
                a=stk.top();
                stk.pop();
                stk.push(!a);
                break;
            case 'C':
                a=stk.top();
                stk.pop();
                b=stk.top();
                stk.pop();
                stk.push(!a||b);
                break;
            case 'E':
                a=stk.top();
                stk.pop();
                b=stk.top();
                stk.pop();
                stk.push(a==b);
                break;
            default:
            	judge(tp[i]);

        }
    }
    return stk.top();

}
int f=0;
int main()
{
	while(~scanf("%s",tp))
	{
		if(tp[0]=='0') break;
		len =strlen(tp);
		f=1;
		for(int i=0;i<32;i++)
		{
			p=i%2;
			q=(i>>1)%2;
			r=(i>>2)%2;
			s=(i>>3)%2;
			t=(i>>4)%2;
			while(!stk.empty())
            stk.pop();
            /*
			for(int j=len-1;j>=0;j--)
			{
				if(tp[j]>='a'&&tp[j]<='z')
				{
					judge(tp[j]);
				}
				else if(tp[j]>='A'&&tp[j]<='Z')
				{
					if(tp[j]=='K')
					{
						ta=stk.top();
						stk.pop();
						tb=stk.top();
						stk.pop();
						stk.push(ta&&tb);
					}
					else if(tp[j]=='A')
					{
						ta=stk.top();
						stk.pop();
						tb=stk.top();
						stk.pop();
						stk.push(ta||tb);
					}
					else if(tp[j]=='C')
					{
						ta=stk.top();
						stk.pop();
						tb=stk.top();
						stk.pop();
						stk.push((!ta)||tb);
					}
					else if(tp[j]=='E')
					{
						ta=stk.top();
						stk.pop();
						tb=stk.top();
						stk.pop();
						stk.push(ta==tb);
					}
					else if(tp[j]=='N')
					{
						ta=stk.top();
						stk.pop();
						stk.push(!ta);
					}
				}
			}
			*/
			if(!getSult())
			{
				f=0;
				break;
			}
			/*
			ta=stk.top();
			if(!ta)
			{
				f=0;
				break;
			}
			*/
		}
		if(!f)
		{
			cout<<"not"<<endl;
		}
		else cout<<"tautology"<<endl;
	}
	return 0;
}
//ApNp
