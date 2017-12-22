/*
一元三次方程求解
分析：二分，注意范围的选取：注意这句话：根与根之差的绝对值>=1 
	  首先将-100至100分成长度为1的子区间（题干中提到根之间的差值>=1)，再对每一个区间进行判断：两端点的函数值是否相乘小于零，是则在该区间一定有根，用二分法将有解区间长度分为小于0.001，此时的端点值便是方程的一个解，输出该解；不是则在该区间无解，继续向后寻找有解区间。直到三个解都寻找完毕时程序结束。 
*/
#include<iostream>
#include<cstdio>
using namespace std;
const double eps=0.001,NO=-1000;
double a,b,c,d;
double f(double x){
	return a*x*x*x+b*x*x+c*x+d;
}
double ef(double l,double r){
	if(f(l)*f(r)>0)return NO;
	while(r-l>eps){
		double mid=(l+r)/2;
		if(f(mid)*f(l)<0)r=mid;
		else if(f(mid)*f(r)<0)l=mid;
		else return NO;
	}
	return l;
}
int main(){
	cin>>a>>b>>c>>d;
	for(int i=-100;i<=99;i++){
		double t=f(i)==0?i:ef(i,i+1);
		if(t!=NO)printf("%.2lf ",t);
	}
	return 0;
}
