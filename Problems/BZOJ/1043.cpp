/*
分析：求出被覆盖的所有弧O(n^2)，跑一边线段覆盖得到总长，减一下。
	  求 弧的方法：先求出圆心连线与x轴夹角a，再求交点与圆心连线和两圆心连线的夹角b，
	  这样得到两交点与圆心连线的与x轴夹角a+b,a-b。
	  接下来判断一下：若a-b<0则要转到另一侧(a-b+2pi..2pi)+(0..a+b)，若a+b>2pi，则(0..a+b-2pi)+(a-b..2pi)，PS:这两种情况不可能同时发生 因为b<=180*
	  若都没有，那么直接(a-b..a+b) 
*/
#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
#include<cmath>  
#include<algorithm>  
using namespace std;  
struct circle{double r,x,y;}a[10000];  
struct arc{double a,b;}q[10000];  
int n,le;double Ans;  
double pi=acos(-1); 
#define sqr(x) ((x)*(x))
double dist(circle a,circle b){
    return sqrt(sqr((a.x-b.x))+sqr((a.y-b.y)));  
}  
double ang(double R,double d,double r){  
    return acos((R*R+d*d-r*r)/(2*R*d));  
}
bool cmp(arc a,arc b){  
    if (a.a==b.a)return a.b<b.b;  
    else return a.a<b.a;
}
void add(double l,double r){
    q[++le].a=l,q[le].b=r;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
		scanf("%lf%lf%lf",&a[i].r,&a[i].x,&a[i].y);
    for(int i=1;i<=n;i++){
        bool f=0;le=0;  
        for (int j=i+1;j<=n;j++){  
            double dis=dist(a[i],a[j]);  
            if (dis<=a[j].r-a[i].r){f=1;break;}//i被内含 
            if (dis>=a[i].r+a[j].r||dis<=a[i].r-a[j].r)  continue;//j被内含或两圆外离  
            double x=a[j].x-a[i].x,y=a[j].y-a[i].y;  
            double a1=atan2(y,x)+pi;//求圆心连线与x轴正方向的夹角 
            double a2=ang(a[i].r,dis,a[j].r);//求交点与i圆心连线和两圆心连线的夹角 
            if (a1-a2<0)add(0,a1+a2),add(a1-a2+2*pi,2*pi);
			else if (a1+a2>2*pi)add(a1-a2,pi*2),add(0,a1+a2-2*pi);  
            else add(a1-a2,a1+a2);
        }  
        if(f==1)continue;  
        sort(q+1,q+le+1,cmp);  
        double l=-1,r=-1,sum=0;  
        for(int j=1;j<=le;j++)  
        	if(q[j].a<=r)  
            	r=max(r,q[j].b);  
        	else sum+=r-l,l=q[j].a,r=q[j].b;
        sum+=r-l;
        Ans+=(2*pi-sum)*a[i].r;  
    }  
    printf("%.3f\n",Ans);  
    return 0;  
}  
