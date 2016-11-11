#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100010;
const int K = 32;
const int H = 100007;
int n, k, ans;
int num[N][K];

struct Node
{
	int pos;
	int next;
};
Node node[N];
int cur;
int hashTable[H];

bool cmp(int x1, int x2)
{
	for (int i = 0; i < k; ++i)
	{
		if (num[x1][i] != num[x2][i]) return false;
	}
	return true;
}

bool allsame(int x)
{
	for (int i = 0; i < k - 1; ++i)
	{
		if (num[x][i] != num[x][i + 1]) return false;
	}
	return true;
}

void init()
{
	for (int i = 0; i < H; ++i) hashTable[i] = -1;
	ans = 0;
	cur = 0;
}

unsigned int getHash(int x)
{
	unsigned int hash = 0;
	for (int i = 0; i < k; ++i)
	{
		hash += num[x][i] * (i + 1);
	}
	return (hash & 0x7fffffff) % H;
}

void searchHash(int x)
{
	unsigned int h = getHash(x);
	int next = hashTable[h];
	while (next != -1)
	{
		if (cmp(node[next].pos, x))
		{
			if (x - node[next].pos > ans) ans = x - node[next].pos;
			return;
		}
		next = node[next].next;
	}
	node[cur].pos = x;
	node[cur].next = hashTable[h];
	hashTable[h] = cur;
	++cur;
}

int main()
{
	int val;
	init();
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &val);
		for (int j = 0; j < k; ++j)
		{
			num[i][j] = (val & 1);
			val >>= 1;
		}
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			num[i][j] += num[i - 1][j];
		}
	}
	for (int i = n - 1; i >= 0; --i)
	{
		if (allsame(i))
		{
			ans = i + 1;
			break;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			num[i][j] -= num[i][k - 1];
		}
	}
	for (int i = 0; i < n; ++i) searchHash(i);
	printf("%d\n", ans);
	return 0;
}
