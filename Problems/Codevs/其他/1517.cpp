/*
求一次函数解析式
分析：y1=kx1+b，y2=kx2+b
	  k=(y2-y1)/(x2-x1)，b=y1-k*x1
*/
#include<iostream>
#include<cstdio>
using namespace std;
int x1,y1,x2,y2;
int main(){
	cin>>x1>>y1>>x2>>y2;
	if(x2-x1==0){
		cout<<"nonono~";
		return 0;
	}
	double k=(y2-y1)*1.0/(x2-x1);
	printf("%.2lf %.2lf",k,(y1-k*x1));
	return 0;
}
