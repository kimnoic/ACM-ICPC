#include <iostream>


using namespace std;


int main()
{
    int sum,n;
	cin>>sum>>n;
	int dp[100001],dp2[100001];
	int a[101];
	int count=0;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];count+=a[i];
	}
	sum=count-sum; dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=sum-a[i];j>=0;j--)
		{
			if(dp[j]!=0)
			{
				if(!dp[j+a[i]])  dp2[j+a[i]]=i; dp[j+a[i]]+=dp[j];
			}
		}
	}
	//cout<<dp[w]<<endl;
	int pos=0;
	if(dp[sum]==0)  cout<<"0";
    else if(dp[sum]==1)
    {
        int ans[102];
	for(int i=n;i>=1;i--)
	{
		if(dp2[sum]==i)
		{
			ans[++pos]=i;sum=sum-a[i];
		}
	}
	for(int i=pos;i>1;i--) cout<<ans[i]<<" "; cout<<ans[1];
    }
    else if(dp[sum]>1) cout<<"-1";
    return 0;
}
