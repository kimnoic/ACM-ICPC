#include <iostream>
using namespace std;
double judge(int a)
{
    if(a>=85) return 4.0;
    else if(a>=80&&a<=84) return 3.5;
    else if(a>=75&&a<=79) return 3.0;
    else if(a>=70&&a<=74) return 2.5;
    else return 2.0;
}
int main()
{
    int n;
    cin>>n;
    int a,b;
    while(cin>>a>>b)
    {
        if(b==1)
        {
            printf("%.4f %.4f\n",judge(a),judge(a));
        }
        else
        {
            if(a>=85)
        {
            int t=100-a;
            int sum=t*b;
            int y=sum/15;

            double k=(4.0*(b-sum)+3.5*);
            printf("%")
        }

        }
    }
    return 0;
}
