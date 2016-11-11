#include <iostream>
#include <stdio.h>
#include <queue>
#include <map>
#include <set>
using namespace std;
struct node
{
    int id;
    int num;
    int s;
} arr[1000000];
queue<node> que;
set<pair<int, int> > s;
int main()
{
    long long cnt = 0;
    int n, i;
    cin>>n;
    for (i = 0; i < n; i++)
		{
        arr[i].id = i;
        cin>>arr[i].num>>arr[i].s;
        cnt += (long long)arr[i].num;
		}
	cout<<cnt/2<<endl;
    for(int i = 0; i < n; ++i)
		{
        if(arr[i].num == 1)
			{
				que.push(arr[i]);
			}
		}
    while(!que.empty())
    {
        node top = que.front();
        que.pop();
        if(arr[top.id].num != 1)
			{
				continue;
			}
        printf("%d %d\n", top.id, arr[top.id].s);
        arr[arr[top.id].s].s ^= top.id;
        arr[top.s].num--;
        arr[top.id].s = 0;
        arr[top.id].num--;
        if(arr[top.s].num == 1)
			{
				que.push(arr[top.s]);
			}
	}
    return 0;
}
