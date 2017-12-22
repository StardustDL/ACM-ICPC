/*
��������������ǵ����л�O(n^2)����һ���߶θ��ǵõ��ܳ�����һ�¡�
	  �� ���ķ����������Բ��������x��н�a�����󽻵���Բ�����ߺ���Բ�����ߵļн�b��
	  �����õ���������Բ�����ߵ���x��н�a+b,a-b��
	  �������ж�һ�£���a-b<0��Ҫת����һ��(a-b+2pi..2pi)+(0..a+b)����a+b>2pi����(0..a+b-2pi)+(a-b..2pi)��PS:���������������ͬʱ���� ��Ϊb<=180*
	  ����û�У���ôֱ��(a-b..a+b) 
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
            if (dis<=a[j].r-a[i].r){f=1;break;}//i���ں� 
            if (dis>=a[i].r+a[j].r||dis<=a[i].r-a[j].r)  continue;//j���ں�����Բ����  
            double x=a[j].x-a[i].x,y=a[j].y-a[i].y;  
            double a1=atan2(y,x)+pi;//��Բ��������x��������ļн� 
            double a2=ang(a[i].r,dis,a[j].r);//�󽻵���iԲ�����ߺ���Բ�����ߵļн� 
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
