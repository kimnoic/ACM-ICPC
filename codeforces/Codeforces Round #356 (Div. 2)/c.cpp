#include <bits/stdc++.h>

using namespace std;
char t[233];
int cnt;
int p[20]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
bool prime(int k){
	for(int i=2;i<=sqrt(k);i++)
		if(k%i==0)
			return false;
	return true;
}

int main(){
    cnt=0;
    for(int i=0;i<15;i++){
        if(cnt>1)
            break;
        cout<<p[i]<<endl;
    fflush(stdout);
        cin>>t;
        if(t[0]=='y'){
            cnt++;
            if(cnt>1)
                break;
            int k=p[i]*p[i];
            if(k<=100){
                cout<<k<<endl;
                fflush(stdout);
                cin>>t;
                if(t[0]=='y'){
                    cnt++;
                    break;
                }
            }
        }

    }
    if(cnt>1)
        cout<<"composite";
    else
        cout<<"prime";
    return 0;
}
