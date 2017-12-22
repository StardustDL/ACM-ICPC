#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
double ksm(double a,int n){
       double ans=1;
       while(n){
                if(n&1)ans*=a;
                a*=a;
                n>>=1;
       }
       return ans;
}
int main(){
    double f1,f0,a,b,c,d,x1,x2;
    int n;
    cin>>f0>>f1>>a>>b>>n;
    x1=0.5*(a+sqrt(a*a+4*b));
    x2=0.5*(a-sqrt(a*a+4*b));
    c=(f1-f0*x2)/(x1-x2);
    d=(f1-f0*x1)/(x2-x1);
    printf("%.0lf",c*ksm(x1,n)+d*ksm(x2,n));
    return 0;
}
