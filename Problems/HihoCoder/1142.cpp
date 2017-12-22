#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define sqr(x) ((x)*(x))
int a,b,c,x,y;
inline double gety(double x){
    return a*x*x+b*x+c;
}
inline double dist(double a,double b){
    return sqr(a-x)+sqr(b-y);
}
inline double calc(double x){
    return dist(x,gety(x));
}
int main(){
    cin>>a>>b>>c>>x>>y;
    double l=-500,r=500;
    while(r-l>1e-5){
        double ml=l+(r-l)/3,mr=r-(r-l)/3;
        double cl=calc(ml),cr=calc(mr);
        if(cl<cr)r=mr;
        else l=ml;
    }
    printf("%.3lf\n",sqrt(calc(l)));
    return 0;
}