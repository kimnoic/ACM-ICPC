#include <bits/stdc++.h>
using namespace std;
int s[234234],m,n,divm,divs;
int main(){
while(scanf("%d%d",&n,&m)!=EOF)
    {
        divm=n*n*(n-1)/2;
            divm=n*n*(n-1)/2;
        divm=divm*divm;
        divs=(n+1)*n*(n+1)/2;
        cout<<divs<<endl;
        divs=divs-n*(n+1)*(2*n+1)/6-n;
        cout<<divs<<endl;
        divs*=n*(n*(n+1)/2-1)-(n-1)*n*(2*n-1)/6-n*(n-1)/2;
        divs*=m-1;
        divs=divs*m/2;
        for(int i=1;i<=m-2;i++)
            divm*=n;
        for(int i=2;i<=sqrt(divs);i++)
            while(divm%i==0 && divs%i==0)
            {
                divm/=i;
                divs/=i;
            }
        if(divm!=1)
            cout<<divs<<"/"<<divm<<endl;
        else
            cout<<divs<<endl;
    }
}



