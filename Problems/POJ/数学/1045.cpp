/*
题意：给出公式V2=iR,V2=Vr * cos(wt + q), V1=Vs * cos(wt), i = C * d(v1 - v2)/dt; d是求导数的意思。已知Vs,R,C,w，求Vr。
分析：利用V2分别等于两个式子，将i,V2和V1带入，可得方程：R*C*d(Vs * cos(wt) - Vr * cos(wt + q))/dt  = Vr * cos(wt + q)
		根据求导公式：d(cos(x))/dx = -sinx可将原方程化为：R*C*w*(Vr*sin(wt + q) - Vs*sin(wt)) = Vr * cos(wt + q)
		在这里三角函数的参数有两个：wt+q和wt，我们分别令他们为0,方程分别可变为：R*C *w*Vs*sin(q) = Vr; R*C * w*sin(q) = cos(q)
		由2式得：cot(q) = R * C * w。
		由公式：sin^2(a) = 1/(cot ^2(a) + 1)
		可得：sin(q)=sqrt(1/(cot^2(q) + 1))
		即：sin(q) =sqrt(1/(R^2*C^2*w^2 + 1))
		代入1式可得：Vr = R * C * w * Vs * sqrt(1/(R^2*C^2*w^2 + 1))
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

