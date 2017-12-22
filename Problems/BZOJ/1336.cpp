/*
[Balkan2002]Alien最小圆覆盖
分析：随机增量法，不能只输出两位小数= = 
*/
#include <cmath>  
#include <cstdio>  
#include <cstring>   
#include <iostream>  
#include <algorithm>
#include <cstdlib> 
using namespace std;
const int MAXN=100000;
const double eps=1e-12;
#define sqr(x) ((x)*(x)) 
struct Point{  
    double x,y;  
    Point(){}  
    Point(double _,double __):x(_),y(__) {}  
    friend Point operator + (const Point &p1,const Point &p2){return Point(p1.x+p2.x,p1.y+p2.y);}  
    friend Point operator - (const Point &p1,const Point &p2){return Point(p1.x-p2.x,p1.y-p2.y);}
    friend double operator * (const Point &p1,const Point &p2){return p1.x*p2.y-p1.y*p2.x;}  
    friend Point operator * (const Point &p1,double rate){return Point(p1.x*rate,p1.y*rate);}
    friend Point Rotate(const Point &p){//逆时针旋转90度 
        return Point(-p.y,p.x);  
    }  
}ps[MAXN+3];
double dist(const Point &p1,const Point &p2){return sqrt( sqr(p1.x-p2.x) + sqr(p1.y-p2.y) ) ;}
struct Line{  
    Point p,v;
    Line(const Point &_,const Point &__):p(_),v(__) {}  
};
struct Circle{  
    Point o;  
    double r;  
    Circle(const Point &_,double __):o(_),r(__) {}  
    bool In_Circle(const Point &p){  
        return dist(p,o)<r+eps;  
    }  
}ans=Circle(Point(0,0),0);
Point Get_Intersection(const Line &l1,const Line &l2){
    double temp=(l2.v*(l1.p-l2.p))/(l1.v*l2.v);//面积比等于长度比，注意方向 
    return l1.p+l1.v*temp;
}
int n;  
int main(){  
    srand(19981222);  
    scanf("%d",&n); 
    for(int i=1;i<=n;i++)scanf("%lf%lf",&ps[i].x,&ps[i].y); 
    random_shuffle(ps+1,ps+n+1);  
    for(int i=1;i<=n;i++){  
        if(ans.In_Circle(ps[i]))continue; 
        ans=Circle(ps[i],0);
        for(int j=1;j<i;j++){  
            if(ans.In_Circle(ps[j]))continue;
            ans=Circle((ps[i]+ps[j])*0.5,dist(ps[i],ps[j])*0.5);  
            for(int k=1;k<j;k++){
            	if(ans.In_Circle(ps[k]))continue;
                Line l1=Line((ps[i]+ps[j])*0.5,Rotate(ps[i]-ps[j]));//两条垂直平分线 
                Line l2=Line((ps[i]+ps[k])*0.5,Rotate(ps[i]-ps[k]));
                Point o=Get_Intersection(l1,l2);
                ans=Circle(o,dist(ps[i],o));
            }
        }
    }  
    printf("%.5lf\n%.5lf %.5lf\n",ans.r,ans.o.x,ans.o.y);
    return 0;  
}  
