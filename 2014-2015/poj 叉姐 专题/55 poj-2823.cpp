#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define Max 1000010
int val[Max];
int n,k;
int max_num[Max],min_num[Max],pos_max[Max],pos_min[Max];
int res_max[Max],res_min[Max];
int min_head,min_tail,max_head,max_tail,cur;
int main(){
    scanf("%d%d",&n,&k);
    min_head=min_tail=max_head=max_tail=1;
    for(int i=1;i<=k;i++) {
        scanf("%d",&val[i]);
        while(min_head<min_tail&&min_num[min_tail-1]>=val[i]) min_tail--;
        min_num[min_tail]=val[i];
        pos_min[min_tail]=i;
        min_tail++;
        while(max_head<max_tail&&max_num[max_tail-1]<=val[i]) max_tail--;
        max_num[max_tail]=val[i];
        pos_max[max_tail]=i;
        max_tail++;
    }
    /*
    8 3
1 3 -1 -3 5 3 6 7
    */

    cur=1;
    for(int i=k+1;i<=n;i++){
        scanf("%d",&val[i]);
        res_max[cur]=max_num[max_head];
        res_min[cur]=min_num[min_head];
        cur++;

        while (min_head < min_tail && i - pos_min[min_head] >= k) ++min_head;
        while (min_head < min_tail && min_num[min_tail-1] >= val[i]) --min_tail;
        min_num[min_tail] = val[i];
        pos_min[min_tail] = i;
        ++min_tail;

        while (max_head < max_tail && i - pos_max[max_head]>= k) ++max_head;
        while (max_head < max_tail && max_num[max_tail - 1] <= val[i]) --max_tail;
        max_num[max_tail] = val[i];
        pos_max[max_tail] = i;
        ++max_tail;
    }
    res_min[cur] = min_num[min_head];
    res_max[cur] = max_num[max_head];
    for(int i=1;i<n-k+1;i++) printf("%d ",res_min[i]);printf("%d\n",res_min[n-k+1]);//cout<<min_num[n-k+1]<<endl;
    for(int i=1;i<n-k+1;i++) printf("%d ",res_max[i]);printf("%d\n",res_max[n-k+1]);

    return 0;
}
