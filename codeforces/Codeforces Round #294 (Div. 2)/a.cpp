#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define INF 0x3fffff
int w=0,b=0;
void judge(char t)
{
	if(t=='q') b+=9;
	else if(t=='r') b+=5;
	else if(t=='b'||t=='n') b+=3;
	else if(t=='p') b+=1;
	else if(t=='Q') w+=9;
	else if(t=='R') w+=5;
	else if(t=='B'||t=='N') w+=3;
	else if(t=='P') w+=1;
}
int main()
{
	w=0;
	b=0;
	char tt;
	for(int i=1;i<=64;i++)
	{
		cin>>tt;
		judge(tt);
	}
	if(b>w) cout<<"Black";
	else if(w>b) cout<<"White";
	else cout<<"Draw";
	return 0;
}
