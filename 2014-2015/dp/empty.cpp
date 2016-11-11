#include <iostream>


using namespace std;

8 389 207 155 300 299 170 158 65

int dp(int count[1001], int a[1001], int n)
{
    int now,max,f=1;
    for (int i=n-1;i>=0;i--)
    {
        max = 0;now = i;
        for (int j=i+1;j<n;j++)
            if (a[i] <= a[j] && count[j] > max)  {max = count[j];now = j;}
            count[i] = max+1;
            if (count[i]>f) f = count[i];
    }
    return f;
}
int main()
{
    int i,n;
    int a[1001];
    int p[1001];
    int count[1001];
    while (cin>>n)
    {
        for (i=0;i<n;i++) cin>>a[i];
        cout<<dp(count, a, n)<<endl;
    }
    return 0;
}
