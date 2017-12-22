/*
���⣺������ʽV2=iR,V2=Vr * cos(wt + q), V1=Vs * cos(wt), i = C * d(v1 - v2)/dt; d����������˼����֪Vs,R,C,w����Vr��
����������V2�ֱ��������ʽ�ӣ���i,V2��V1���룬�ɵ÷��̣�R*C*d(Vs * cos(wt) - Vr * cos(wt + q))/dt  = Vr * cos(wt + q)
		�����󵼹�ʽ��d(cos(x))/dx = -sinx�ɽ�ԭ���̻�Ϊ��R*C*w*(Vr*sin(wt + q) - Vs*sin(wt)) = Vr * cos(wt + q)
		���������Ǻ����Ĳ�����������wt+q��wt�����Ƿֱ�������Ϊ0,���̷ֱ�ɱ�Ϊ��R*C *w*Vs*sin(q) = Vr; R*C * w*sin(q) = cos(q)
		��2ʽ�ã�cot(q) = R * C * w��
		�ɹ�ʽ��sin^2(a) = 1/(cot ^2(a) + 1)
		�ɵã�sin(q)=sqrt(1/(cot^2(q) + 1))
		����sin(q) =sqrt(1/(R^2*C^2*w^2 + 1))
		����1ʽ�ɵã�Vr = R * C * w * Vs * sqrt(1/(R^2*C^2*w^2 + 1))
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n;
double vs,r,c,w;
int main(){
    scanf("%lf%lf%lf%d",&vs,&r,&c,&n);
    while(n--){
        scanf("%lf",&w);
        printf("%.3f\n",r*c*w*vs*sqrt(1/(r*r*c*c*w*w+1)));
    }
    return 0;
}

