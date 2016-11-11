#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define Max 50010
double a[Max];
double sum1,sum2;
int n,k;
int main(){
    int T;
    cin>>T;
    while(T--){
        sum1=sum2=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            scanf("%lf",&a[i]);
        }
        if(n==k){
            cout<<0<<endl;
            continue;
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n-k;i++){
            sum1+=a[i];
            sum2+=a[i]*a[i];
        }
        double x=(n-k);
        double sum=sum2-2*sum1*(sum1/x)+(sum1/x)*(sum1/x)*x;
        int cnt=1;
        for(int i=n-k+1;i<=n;i++){
            sum1+=a[i];
            sum1-=a[cnt];
            sum2+=a[i]*a[i];
            sum2-=a[cnt]*a[cnt];
            cnt++;
            sum=min(sum,sum2-2*sum1*(sum1/x)+(sum1/x)*(sum1/x)*x);
        }
        printf("%.10lf\n",sum);
    }
    return 0;
}
