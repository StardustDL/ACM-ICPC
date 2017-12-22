/*
һԪ���η������
���������֣�ע�ⷶΧ��ѡȡ��ע����仰�������֮��ľ���ֵ>=1 
	  ���Ƚ�-100��100�ֳɳ���Ϊ1�������䣨������ᵽ��֮��Ĳ�ֵ>=1)���ٶ�ÿһ����������жϣ����˵�ĺ���ֵ�Ƿ����С���㣬�����ڸ�����һ���и����ö��ַ����н����䳤�ȷ�ΪС��0.001����ʱ�Ķ˵�ֵ���Ƿ��̵�һ���⣬����ý⣻�������ڸ������޽⣬�������Ѱ���н����䡣ֱ�������ⶼѰ�����ʱ��������� 
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
