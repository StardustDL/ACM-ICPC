/*
Coin Toss
���⣺n*m���߳�Ϊt����������ɵľ��Ρ�����������һ��ֱ��Ϊc��Ӳ�ң��ʸ���1��2��3��4�����εĸ���Ϊ���٣�
������������ѧ�⣬���������1��2��3��4������ʱӲ��Բ�Ŀ����ڵ�λ������������������������Ǹ����� 
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
        ans[0]=(t-c/2)*(t-c/2)*4 + (t-c)*(t-c/2)*(2*m+2*n-8) + (t-c)*(t-c)*(n-2)*(m-2);  //����һ������ʱӲ��Բ�Ŀ����ڵ�λ��  
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

