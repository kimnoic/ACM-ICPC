#include<iostream>

using namespace std;

int s1[40001],s2[40001];

int T,n,ans;
int main()
{
   cin>>T;
   while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>s1[i];
        ans=1;
        s2[1] = s1[1];
        for(int i=2;i<=n;i++)
            {
                if(s2[ans]<s1[i])
                {
                    s2[++ans] = s1[i];
                }
                int left=1,right=ans,mid;
                while(left<=right)
                    {
                        mid = (left+right)/2;
                        if(s2[mid]<s1[i])  left = mid+1;
                        else   right = mid-1;
                    }
                s2[left] = s1[i];
            }
         cout<<ans<<endl;
    }
    return 0;
}
