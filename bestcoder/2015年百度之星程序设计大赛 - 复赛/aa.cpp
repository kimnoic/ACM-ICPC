#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <stdlib.h>
struct Line
{
	int x1, x2;
};
struct Point
{
	int x,y;
};
Point cross(Line a, Line b) {
	if (b.x1 > b.x2)
		swap(b.x1, b.x2);
	if (a.x1 < b.x1 || a.x1 > b.x2) flag = true;
	if (a.y1 > a.y2)
		swap(a.y1, a.y2);
	if (b.y1 < a.y1 || b.y1 > a.y2) flag = true;
	return Point(a.x1, b.y1);
}

int dis(Point a, Point b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

bool check(Point a, Point b, Point c, Point d) {
	return (dis(a, b) == dis(b, d) && dis(a, b) == dis(a, c) && dis(a, b) == dis(c, d));
}

int calc(int n, int x, int y) {
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (d[i].y1 == d[i].y2)
			for (int j = i + 1; j <= n; ++j)
				if (d[j].y1 == d[j].y2) {
					flag = false;
					Point a = cross(d[x], d[i]), b = cross(d[x], d[j]), c = cross(d[y], d[i]), e = cross(d[y], d[j]);
					if (flag) continue;
						++ans;
				}
	return ans;
}

int main(void){
	int T;
	scanf("%d", &T);
	for (int Test = 1; Test <= T; ++Test) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d%d%d", &d[i].x1, &d[i].y1, &d[i].x2, &d[i].y2);
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			if (d[i].x1 == d[i].x2)
				for (int j = i + 1; j <= n; ++j)
					if (d[j].x1 == d[j].x2)
						ans += calc(n, i, j);
		printf("Case #%d:\n%d\n", Test, ans);
	}
