/*
Fence
���⣺��һȦ��ʣ��߶�Ϊh����(0,0)�㴦��һ��·�ƣ�����������ڣ�Ҳ����������⣬�������ס����ʲ��ܱ��������������Ĳ��ֵĹ�ǿΪI0=k/r��k��һ����֪������rΪ��Դ�����յ���ľ��롣��ôһ������С����ܵ��Ĺ��ն�ΪdI=I0*|cos��|*dl*h������alphaΪ��������ʷ��ߵļнǡ����ڣ�������дһ�����򣬼�������ܵ����ܵĹ��նȡ�
���������ϴ�����ǻ��֣�û�ж������� 
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

