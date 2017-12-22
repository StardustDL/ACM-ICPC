/*
Fence
题意：有一圈篱笆，高度为h，在(0,0)点处有一根路灯，可以在篱笆内，也可以在篱笆外，被篱笆遮住的篱笆不能被照亮。被照亮的部分的光强为I0=k/r，k是一个已知常数，r为光源到被照到点的距离。那么一段无限小篱笆受到的光照度为dI=I0*|cosα|*dl*h，其中alpha为光线与篱笆法线的夹角。现在，任务是写一个程序，计算篱笆受到的总的光照度。
分析：网上大多数是积分，没有懂。。。 
*/
#include<iostream>
#include<cmath>
using namespace std;
#define MAXN 101
#define PI 3.1415926
struct point{double x,y;};
point a[MAXN];
double Max=0,Min=0,sum=0,h,k;
int n;
double angle(point A,point B){
    double k1=atan2(A.y,A.x),k2=atan2(B.y,B.x);
    if(k2-k1>PI)k1+=2*PI;
    if(k1-k2>PI)k2+=2*PI;
    return k2-k1;
}
int main(){
    scanf("%lf%lf%d",&k,&h,&n);
    for(int i=0;i<n;i++)scanf("%lf%lf",&a[i].x,&a[i].y);
    a[n].x=a[0].x;a[n].y=a[0].y;
    for(int i=0;i<n;i++){
        sum+=angle(a[i],a[i+1]);
        if(sum<Min)Min=sum;
        if(sum>Max)Max=sum;
        if(Max-Min>=2*PI){
            Max=Min+2*PI;
            break;
        }
    }
    printf("%.2f\n",(Max-Min)*k*h);
    return 0;
}

