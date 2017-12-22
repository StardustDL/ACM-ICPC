/*
I Think I Need a Houseboat
题意：由坐标 (0,0) 开始，以半圆为形状每年侵蚀50m^2，问(0,0)开始到(x,y)结束需要多长时间
分析：πr^2 每年增长100，对于给定的坐标，到圆心的距离平方为 d=x*x + y*y，计算πd /100，因为d不会等于某个半径，所以   πd /100结果一定是一个带小数的数，假设结果为n.m，则说明该坐标在第n年年底时还没被侵蚀，而在n+1年时会被侵蚀。 
*/
#include<cstdio>
#include<cmath>
int main(){
	int n;
	float pi,x,y,years;
	scanf("%d",&n);
	pi=acos(-1.0);
	for(int i=1;i<=n;i++){
		scanf("%f%f",&x,&y);
	    years = pi*(x*x+y*y)/100;
	    printf("Property %d: This property will begin eroding in year %d.\n",i,(int)years+1);
	}
	printf("END OF OUTPUT.\n");
    return 0;
}

