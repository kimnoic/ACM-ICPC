#include <bits/stdc++.h>
using namespace std;
//�ж�����b��Ӧ������a�е�Ԫ��֮���Ƿ�Ϊs
bool isSum(int a[], int b[], int n, int s) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret += a[b[i]];
	}
	return s == ret;
}

//a����ʼ����
//n��a������Ԫ�ظ���
//m��ѡ��Ԫ�صĸ���
//b����Ž��������
//bn������b��Ԫ�ظ���������m
void combine(int a[], int n, int m, int b[], int bn, int s) {
	for (int i = n; i >= m; i--) {
		b[m - 1] = i - 1;
		if (m > 1) { //һ��Ҫѡm��������m = 1ʱ�Ž����ݹ�
			combine(a, i - 1, m - 1, b, bn, s);
		} else if (isSum(a, b, bn, s)) {
			for (int j = bn - 1; j >= 0; j--) {
				cout << a[b[j]] << ' ';
			}
			cout << endl;
		}
	}
}
#define Max 6666
int a[Max],b[Max],n,m,k;
int main(){
    for(int i=1;i<=6660;i++){
        a[i]=1;
    }
    combine(a,6660,2016,b,0,2016);
    return 0;
}
