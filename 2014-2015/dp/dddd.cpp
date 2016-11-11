#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    map<string, int> Ballon;
    string color, MaxColor;
    int n, max;
    while(cin>>n&&n){
        Ballon.clear();
        while(n--){
            cin>>color;
            Ballon[color]++;
        }
        map<string, int>::iterator it;
        max = 0;
        for(it=Ballon.begin(); it!=Ballon.end(); it++){
            if(it->second>max){
                max = it->second;
                MaxColor = it->first;
            }
        }
        cout<<MaxColor<<endl;
    }
    return 0;
}
