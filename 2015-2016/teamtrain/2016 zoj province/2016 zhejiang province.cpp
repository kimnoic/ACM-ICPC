#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 100010

using namespace std;
int a[Max],sum[Max];

int main(){
  int t,n,maxx;
  cin>>t;
  while(t--){
	  maxx=0;
	  scanf("%d",&n);
      for(int i=1;i<=n;i++){
		  scanf("%d",&a[i]);
	  }
	  a[n+1]=0;
	  sum[n+1]=0;
	  for(int i=n;i>=1;i--){
		  if(a[i+1]){
			  sum[i]=sum[i+1]+1;
		  }
		  else
			  sum[i]=sum[i+1];
		  if(a[i]+sum[i]>maxx)
			  maxx=a[i]+sum[i];
	  }
	  cout<<maxx<<endl;
  }
  return 0;
}
