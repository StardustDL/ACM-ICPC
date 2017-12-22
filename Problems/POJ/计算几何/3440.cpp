/*
Coin Toss
题意：n*m个边长为t的正方形组成的矩形。往矩形上抛一个直径为c的硬币，问覆盖1，2，3，4个矩形的概率为多少？
分析：就是数学题，计算出覆盖1，2，3，4个矩形时硬币圆心可以在的位置区域的面积，除以总面积就是概率了 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
using namespace std;
const double pi=acos(-1.0);
int main(){  
    int T;  
    double n,m,t,c,ans[4];  
    scanf("%d",&T);  
    for(int i=1;i<=T;i++){  
        scanf("%lf%lf%lf%lf",&n,&m,&t,&c);  
        ans[0]=(t-c/2)*(t-c/2)*4 + (t-c)*(t-c/2)*(2*m+2*n-8) + (t-c)*(t-c)*(n-2)*(m-2);  //覆盖一个方格时硬币圆心可以在的位置  
        ans[2] = (c*c - pi*(c/2)*(c/2) )*(n-1)*(m-1);  
        ans[3] = pi*(c/2)*(c/2)*(n-1)*(m-1);  
        ans[1] = n*m*t*t - ans[0] - ans[2] - ans[3];  
        printf("Case %d:\n",i);  
		printf("Probability of covering 1 tile  = %.4f%%\n",ans[0]*100.0/(n*m*t*t));  
        for(int i=1;i<4;i++)
			printf("Probability of covering %d tiles = %.4f%%\n",i+1,ans[i]*100.0/(n*m*t*t));  
        puts("");  
    }  
    return 0;  
}  

