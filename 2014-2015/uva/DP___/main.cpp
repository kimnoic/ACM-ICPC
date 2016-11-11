#include <iostream>

using namespace std;

int del(int l,int r)
{
	if (l==r) return 0;
	int k,ans;
	ans=1e9;
	for (int i=l;i<r;i++)
		ans=min(del(l,i)+del(i+1,r)+a[i]+a[i+1],ans);
	return ans;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
