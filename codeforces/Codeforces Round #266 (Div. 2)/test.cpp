#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
void splitN(int n,int m);
// n是需要拆分的数，m是拆分的进度。
int x[1024]={0},total=0; // total用于计数拆分的方法数，x[]用于存储解
int main()
{      int n;       printf("please input the natural number n:");     scanf("%d",&n);int k;cin>>k;     splitN(n,1);      printf("There are %d ways to split natural number %d. ",total,n); }
void splitN(int n,int m)  {
	//n是需要拆分的数，m是拆分的进度
	int rest,i,j;         for(i=1;i<=n;i++)
	{
		//从1开始尝试拆分
		if(i>=x[m-1])          {
				//拆分的数大于或等于前一个从而保证不重复
				 x[m]=i ;// 将这个数计入结果中
				 rest=n-i ;// 剩下的数是n-i，如果已经没有剩下的了，并且进度(总的拆分个数)大于1，说明已经得到一个结果了
				  if(rest==0&&m>1)
					{                  total++;                  printf("%d\t",total);
				  for(j=1;j<m;j++)                 {                      printf("%d+",x[j]);                 }
				   printf("%d ",x[m]);         printf("\n");              }
				  else             {                  splitN(rest,m+1);}}}}
// 否则将剩下的数进行进度为m+1拆分             }              x[m]=0;//
